/**
 * \file range.hpp
 *
 * \copyright 2018 John Harwell, All rights reserved.
 *
 * This file is part of RCPPSW.
 *
 * RCPPSW is free software: you can redistribute it and/or modify it under the
 * terms of the GNU General Public License as published by the Free Software
 * Foundation, either version 3 of the License, or (at your option) any later
 * version.
 *
 * RCPPSW is distributed in the hope that it will be useful, but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR
 * A PARTICULAR PURPOSE.  See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * RCPPSW.  If not, see <http://www.gnu.org/licenses/
 */

#ifndef INCLUDE_RCPPSW_MATH_RANGE_HPP_
#define INCLUDE_RCPPSW_MATH_RANGE_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <cmath>
#include <iosfwd>
#include <string>

#include "rcppsw/er/client.hpp"
#include "rcppsw/rcppsw.hpp"
#include "rcppsw/utils/string_utils.hpp"
#include "rcppsw/er/stringizable.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, math);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * \class range
 * \ingroup math
 *
 * \brief Convenience class holding a [min, max] range. Makes comparisons like
 * "is this number in this range" much more intuitive and easy to debug.
 *
 * If you use the default constructor you must call \ref set() or read
 * initialization from a stream before calling any member functions to avoid
 * undefined behavior.
 *
 * To call any member functions other than \ref lb() and \ref ub(), the range
 * must be non-empty, meaning that the min must not be equal to the max (if it
 * is an assertion will trigger).
 *
 * No mutator functions are provided beyond setters, with the idea that ranges
 * should generally be read-only. If you want to modify a range (e.g., \ref
 * translate() it), a new range should be returned and the original range be
 * unmodified.
 */
template <typename T>
class range final : public er::client<range<T>>, er::stringizable {
 public:
  range(void) noexcept : ER_CLIENT_INIT("rcppsw.math.range") {}
  range(const T& lb, const T& ub) noexcept
      : ER_CLIENT_INIT("rcppsw.math.range"),
        m_initialized(true),
        m_lb(lb),
        m_ub(ub),
        m_span(m_ub - m_lb) {}

  /**
   * \brief Get the lower bound of the range.
   */
  RCPPSW_NODISCARD T lb(void) const { return m_lb; }

  /**
   * \brief Get the upper bound of the range.
   */
  RCPPSW_NODISCARD T ub(void) const { return m_ub; }

  /**
   * \brief Get the size of the range (max - max).
   */
  RCPPSW_NODISCARD T span(void) const { return m_span; }

  /**
   * \brief Set the range lower bound. It must be less than the current \ref
   * ub() or an assertion will trigger.
   */
  void lb(const T& lb) {
    ER_ASSERT(m_initialized, "Range not initialized");
    ER_ASSERT(lb < m_ub,
              "New lower bound (%s) >= upper bound (%s)",
              rcppsw::to_string(lb).c_str(),
              rcppsw::to_string(m_ub).c_str());
    m_lb = lb;
    m_span = m_ub;
    m_span -= m_lb;
  }

  /**
   * \brief Set the range upper bound. It must be greater than the current \ref
   * lb() or an assertion will trigger.
   */
  void ub(const T& ub) {
    ER_ASSERT(m_initialized, "Range not initialized");
    ER_ASSERT(ub > m_lb,
              "New upper bound (%s) <= lower bound (%s)",
              rcppsw::to_string(ub).c_str(),
              rcppsw::to_string(m_lb).c_str());

    m_ub = ub;
    m_span = m_ub;
    m_span -= m_lb;
  }

  /**
   * \brief Set the \ref lb() and \ref ub() for the range simultaneously. The lb
   * must be < ub or an assertion will trigger.
   */
  void set(const T& lb, const T& ub) {
    ER_ASSERT(lb < ub,
              "New lower bound (%s) >= New upper bound (%s)",
              rcppsw::to_string(m_lb).c_str(),
              rcppsw::to_string(m_ub).c_str());
    m_initialized = true;
    m_lb = lb;
    m_ub = ub;
    m_span = m_ub;
    m_span -= m_lb;
  }

  /**
   * \brief Determine if a value is within the range [lb, ub] (boundary points
   * included).
   *
   * \param value The value to test.
   */
  template <typename U = T, RCPPSW_SFINAE_DECLDEF(!std::is_floating_point<U>::value)>
  bool contains(const T& value) const {
    ER_ASSERT(m_initialized, "Range not initialized");
    return value >= m_lb && value <= m_ub;
  }

  template <typename U = T, RCPPSW_SFINAE_DECLDEF(std::is_floating_point<U>::value)>
  bool contains(const T& value) const {
    ER_ASSERT(m_initialized, "Range not initialized");
    return value >= m_lb && value <= m_ub;
  }

  /**
   * \brief Determine if one range completely contains another (boundary points
   * are included with both ranges).
   */
  bool contains(const range<T>& other) const {
    return this->contains(other.m_lb) && this->contains(other.m_ub);
  }

  /**
   * \brief Determine if one range overlaps with another.
   *
   * Overlap is a commutative calculation (i.e. overlap(A,B) <-> overlap(B,A)).
   *
   * To implement this, we need to check if either bound of the argument is
   * contained in our range, AND if either of our bounds are contained in the
   * argument's range. The second part is necessary if A is completely contained
   * inside B in order for the calculation to be commutative.
   */
  bool overlaps_with(const range<T>& other) const {
    return this->contains(other.m_lb) || this->contains(other.m_ub) ||
           other.contains(this->m_lb) || other.contains(this->m_ub);
  }

  /**
   * \brief Wrap the specified value into the range [min, max] using wrap around
   * addition/subtraction.
   *
   * \return The wrapped value.
   */
  RCPPSW_NODISCARD RCPPSW_PURE T wrap_value(T value) const {
    ER_ASSERT(m_initialized, "Range not initialized");

    while (value > m_ub) {
      value -= m_span;
    }
    while (value < m_lb) {
      value += m_span;
    }
    return value;
  }

  /**
   * \brief Get the midpoint of the range.
   *
   * For integer ranges where \ref span() is odd, this will truncate (i.e., the
   * centerpoint is always of type \p T).
   */
  T center(void) const { return (m_lb + m_ub) / 2; }


  /**
   * \brief Return a string representation of the range in the form of '[lb,ub]'.
   */
  std::string to_str(void) const override {
    return "[" + rcppsw::to_string(m_lb) + "-" + rcppsw::to_string(m_ub) + "]";
  }

  friend std::ostream& operator<<(std::ostream& stream, const range& c_range) {
    stream << c_range.to_str();
    return stream;
  }
  /**
   * \brief Translate the current range to the specified value, returning a new
   * range resulting from the translation.
   *
   * \return The new translated range.
   */
  range translate(const T& value) const {
    return range(m_lb + value, m_ub + value);
  }
  /**
   * \brief Shrink the current range in both directions with the specified value, returning a new
   * range resulting from the shrink.
   *
   * \return The shrunken range.
   */
  range shrink(const T& value) const {
    return range(m_lb + value, m_ub - value);
  }

  /**
   * \brief Re-center the current range around the specified value, returning a
   * new range centered at that value.
   */
  range recenter(const T&value) const {
    T span = this->span();
    return range(static_cast<T>(value - span / 2.0),
                 static_cast<T>(value + span / 2.0));
  }

  /**
   * \brief For parsing a range from a string in the form of \c "LB:UB".
   */
  friend std::istream& operator>>(std::istream& is, range& r) {
    T values[2] = { T(), T() };
    utils::parse_values<T>(is, 2, values, ':');
    r.set(values[0], values[1]);
    return is;
  }

 private:
  /* clang-format off */
  bool m_initialized{false};
  T    m_lb{};
  T    m_ub{};
  T    m_span{};
  /* clang-format on */
};

/**
 * \brief Specialization of \ref range for signed integers.
 */
using rangei = range<int>;

/**
 * \brief Specialization of \ref range for size_t.
 */
using rangez = range<size_t>;

/**
 * \brief Specialization of \ref range for doubles.
 */
using ranged = range<double>;

/*******************************************************************************
 * Macros
 ******************************************************************************/
/**
 * \brief Convert range{i,u,z} -> ranged directly, without applying any
 * scaling.
 */
#define RCPPSW_MATH_RANGE_DIRECT_CONV2FLT(prefix)                         \
  static inline ranged prefix##range2drange(const range##prefix& other) { \
    return ranged(other.lb(), other.lb());                                \
  }

/**
 * \brief Convert range{i,u,z} -> ranged, applying a multiplicative scaling
 * factor.
 */
#define RCPPSW_MATH_RANGE_SCALED_CONV2FLT(prefix)                       \
  static inline ranged prefix##range2drange(const range##prefix& other, \
                                            double scale) {             \
    return ranged(other.lb() * scale, other.ub() * scale);              \
  }

/**
 * \brief Convert ranged -> range{i,u,z}, applying a divisive scaling factor.
 */
#define RCPPSW_MATH_RANGE_CONV2DISC(dest_prefix, dest_type)                \
  static inline range##dest_prefix drange2##dest_prefix##range(            \
      const range##dest_prefix& other, double scale) {                     \
    return range##dest_prefix(static_cast<dest_type>(other.lb() / scale),  \
                              static_cast<dest_type>(other.ub() / scale)); \
  }

/*******************************************************************************
 * Free Functions
 ******************************************************************************/
RCPPSW_MATH_RANGE_DIRECT_CONV2FLT(z);
RCPPSW_MATH_RANGE_DIRECT_CONV2FLT(i);
RCPPSW_MATH_RANGE_SCALED_CONV2FLT(z);
RCPPSW_MATH_RANGE_SCALED_CONV2FLT(i);
RCPPSW_MATH_RANGE_CONV2DISC(z, size_t);

NS_END(math, rcppsw);

#endif /* INCLUDE_RCPPSW_MATH_RANGE_HPP_ */
