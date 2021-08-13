/**
 * \file bounding_box.hpp
 *
 * \copyright 2021 John Harwell, All rights reserved.
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

#ifndef INCLUDE_RCPPSW_MATH_BOUNDING_BOX_HPP_
#define INCLUDE_RCPPSW_MATH_BOUNDING_BOX_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/math/vector3.hpp"
#include "rcppsw/math/spatial.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, math);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * \class bounding_box
 * \ingroup math
 *
 * \brief Mathematical abstraction of the 3D bounding box of an object.
 */
template <typename TCoord>
class bounding_box : public rer::client<bounding_box<TCoord>> {
 public:
  using coord_type = TCoord;
  using coord_value_type = typename coord_type::value_type;

  explicit bounding_box(const coord_type& dims)
      : bounding_box{dims, {}} {}

  bounding_box(const coord_type& dims,
               const coord_type& origin)
      : ER_CLIENT_INIT("rcppsw.math.bounding_box"),
        mc_dims(dims),
        m_origin_initialized(true),
        m_origin(origin) {
    update(m_origin);
  }

  ~bounding_box(void) override = default;

  bounding_box(const bounding_box&) = default;
  bounding_box& operator=(const bounding_box&) = default;
  bounding_box(bounding_box&&) = default;
  bounding_box& operator=(bounding_box&&) = default;

  const coord_type& anchor3D(void) const {
    ER_ASSERT(m_origin_initialized,
              "%s called with no origin set",
              __FUNCTION__);
    return m_origin;
  }
  const coord_type& dims3D(void) const { return mc_dims; }

  coord_type center3D(void) const {
    ER_ASSERT(m_origin_initialized,
              "%s called with no origin set",
              __FUNCTION__);

    return m_center;
  }

  coord_value_type xsize(void) const { return mc_dims.x(); }
  coord_value_type ysize(void) const { return mc_dims.y(); }
  coord_value_type zsize(void) const { return mc_dims.z(); }

  void update(const coord_type& origin) {
    m_origin = origin;
    m_center = m_origin + coord_type(xsize(),
                                     ysize(),
                                     zsize()) / 2.0;
    m_xspan = rmath::xspan(anchor3D(), xsize());
    m_yspan = rmath::yspan(anchor3D(), ysize());
    m_zspan = rmath::zspan(anchor3D(), zsize());
  }

  rmath::range<coord_value_type> xspan(void) const {
    ER_ASSERT(m_origin_initialized,
              "%s called with no origin set",
              __FUNCTION__);
    return m_xspan;
  }
  rmath::range<coord_value_type> yspan(void) const {
    ER_ASSERT(m_origin_initialized,
              "%s called with no origin set",
              __FUNCTION__);
    return m_yspan;
  }
  rmath::range<coord_value_type> zspan(void) const {
    ER_ASSERT(m_origin_initialized,
              "%s called with no origin set",
              __FUNCTION__);
    return m_zspan;
  }

 private:
  /* clang-format off */
  const coord_type               mc_dims;

  bool                           m_origin_initialized{false};
  coord_type                     m_origin{};
  coord_type                     m_center{};

  rmath::range<coord_value_type> m_xspan{};
  rmath::range<coord_value_type> m_yspan{};
  rmath::range<coord_value_type> m_zspan{};
  /* clang-format on */
};

NS_END(math, rcppsw);

#endif /* INCLUDE_RCPPSW_MATH_BOUNDING_BOX_HPP_ */
