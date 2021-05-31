#!/bin/bash
#
# Usage: doxy_prepare.sh <file_name>

# First, fix namespaces so doxygen parses them better
tmp=$(cat $1 | sed '/^NS_START/ s/,/::/g' | sed '/^NS_START/ s/);/{/g'  | sed '/^NS_START/ s/NS_START(/namespace /g' | sed 's/^NS_END.*$/}/g')

# Next, RCPPSW_ATTR variadic macros
tmp=$(echo "$tmp" | sed -E 's/RCPPSW_ATTR\((.*)\)/;/g')

# Next, SFINAE variadic macros
tmp=$(echo "$tmp" | sed 's/RCPPSW_SFINAE_DECLDEF\((.*)\)/typename std::enable_if<\1,int>::type =0/g')

# Next, decorate variadic macros
tmp=$(echo "$tmp" | sed -E 's/^[ \t]*RCPPSW_DECORATE_DECLDEF_TEMPLATE\((.*),(.*),(.*)\)/template<typename... Args> auto Func(Args\&\&\.\.\. args) \3 -> decltype(std::declval<decltype(rpdecorator::decorator<\1>::decoratee())>().Func(args...)) { return rpdecorator::decorator<\1>::decoratee().\2( std::forward<Args>(args)...); }/g')


# Next, DECLDEF variadic macros
tmp=$(echo "$tmp" | sed -E 's/^[ \t]*RCPPSW_WRAP_DECLDEF\((.*),(.*),(.*)\)/template <typename... Args>auto Func\(Args\&\&\.\.\. args\) \3 ->decltype(std::declval<decltype(Member)>().Func(args...)) { return \2\.\1(std::forward<Args>(args)...); }/g')

tmp=$(echo "$tmp" | sed -E 's/^[ \t]*RCPPSW_WRAP_DECLDEF\((.*),(.*)\)/template <typename... Args>auto Func\(Args\&\&\.\.\. args\) ->decltype(std::declval<decltype(Member)>().Func(args...)) { return \2\.\1(std::forward<Args>(args)...); }/g')

echo "$tmp"

