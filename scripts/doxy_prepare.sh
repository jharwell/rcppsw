#!/bin/bash
#
# Usage: doxy_prepare.sh <file_name>

# First, RCPPSW_ATTR variadic macros
tmp=$(cat "$1" | sed -E 's/RCPPSW_ATTR\((.*)\)/;/g')

# Next, SFINAE variadic macros, which can span multiple lines
tmp=$(echo "$tmp" |sed -E '/RCPPSW_SFINAE_DECLDEF/ {N;N; s/RCPPSW_SFINAE_DECLDEF\((.*)\)>/typename std::enable_if<\1,int>::type =0>/}')

# Next, decorate variadic macros
tmp=$(echo "$tmp" | sed -E 's/^[ \t]*RCPPSW_DECORATE_DECLDEF_TEMPLATE\((.*),(.*),(.*)\)/template<typename... Args> auto Func(Args\&\&\.\.\. args) \3 -> decltype(std::declval<decltype(rpdecorator::decorator<\1>::decoratee())>().Func(args...)) { return rpdecorator::decorator<\1>::decoratee().\2( std::forward<Args>(args)...); }/g')

tmp=$(echo "$tmp" | sed -E 's/^[ \t]*RCPPSW_DECORATE_DECLDEF/RCPPSW_WRAP_DECLDEF/g')

tmp=$(echo "$tmp" | sed -E 's/RCPPSW_WRAP_DECLDEF_OVERRIDE\((.*),(.*),(.*)\)/auto \1(void) \3->decltype(std::declval<decltype(\2)>().\1()) override { return (\2).\1();}/g')
tmp=$(echo "$tmp" | sed -E '/RCPPSW_WRAP_DECL_OVERRIDE/ {N;N; s/RCPPSW_WRAP_DECL_OVERRIDE\((.*),(.*),(.*)\)/\1 \2(void) \3 override/}')


# Next, DECLDEF variadic macros
tmp=$(echo "$tmp" | sed -E 's/^[ \t]*RCPPSW_WRAP_DECLDEF\((.*),(.*),(.*)\)/template <typename... Args>auto Func\(Args\&\&\.\.\. args\) \3 ->decltype(std::declval<decltype(Member)>().Func(args...)) { return \2\.\1(std::forward<Args>(args)...); }/g')

tmp=$(echo "$tmp" | sed -E 's/^[ \t]*RCPPSW_WRAP_DECLDEF\((.*),(.*)\)/template <typename... Args>auto Func\(Args\&\&\.\.\. args\) ->decltype(std::declval<decltype(Member)>().Func(args...)) { return \2\.\1(std::forward<Args>(args)...); }/g')

echo "$tmp"

