/**
 * \file bounding_box.hpp
 *
 * \copyright 2021 John Harwell, All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

#pragma once

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/math/vector3.hpp"
#include "rcppsw/spatial/spatial.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
namespace rcppsw::spatial {

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * \class bounding_box
 * \ingroup spatial
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
               const coord_type& anchor)
      : ER_CLIENT_INIT("rcppsw.math.bounding_box"),
        mc_dims(dims),
        m_anchor_initialized(true),
        m_anchor(anchor) {
    update(m_anchor);
  }

  ~bounding_box(void) override = default;

  bounding_box(const bounding_box&) = default;
  bounding_box& operator=(const bounding_box&) = default;
  bounding_box(bounding_box&&) = default;
  bounding_box& operator=(bounding_box&&) = default;

  const coord_type& anchor3D(void) const {
    ER_ASSERT(m_anchor_initialized,
              "%s called with no anchor set",
              __FUNCTION__);
    return m_anchor;
  }
  const coord_type& dims3D(void) const { return mc_dims; }

  coord_type center3D(void) const {
    ER_ASSERT(m_anchor_initialized,
              "%s called with no anchor set",
              __FUNCTION__);

    return m_center;
  }

  coord_value_type xsize(void) const { return mc_dims.x(); }
  coord_value_type ysize(void) const { return mc_dims.y(); }
  coord_value_type zsize(void) const { return mc_dims.z(); }

  void update(const coord_type& anchor) {
    ER_TRACE("anchor: %s", rcppsw::to_string(anchor).c_str());
    ER_TRACE("bb: %s", rcppsw::to_string(coord_type(xsize(),
                                                    ysize(),
                                                    zsize())).c_str());
    m_anchor = anchor;
    m_center = m_anchor + coord_type(xsize(),
                                     ysize(),
                                     zsize()) / 2.0;
    ER_TRACE("center: %s", rcppsw::to_string(m_center).c_str());
    m_xspan = rspatial::xspan(anchor3D(), xsize());
    m_yspan = rspatial::yspan(anchor3D(), ysize());
    m_zspan = rspatial::zspan(anchor3D(), zsize());
  }

  rmath::range<coord_value_type> xspan(void) const {
    ER_ASSERT(m_anchor_initialized,
              "%s called with no anchor set",
              __FUNCTION__);
    return m_xspan;
  }
  rmath::range<coord_value_type> yspan(void) const {
    ER_ASSERT(m_anchor_initialized,
              "%s called with no anchor set",
              __FUNCTION__);
    return m_yspan;
  }
  rmath::range<coord_value_type> zspan(void) const {
    ER_ASSERT(m_anchor_initialized,
              "%s called with no anchor set",
              __FUNCTION__);
    return m_zspan;
  }

 private:
  /* clang-format off */
  const coord_type               mc_dims;

  bool                           m_anchor_initialized{false};
  coord_type                     m_anchor{};
  coord_type                     m_center{};

  rmath::range<coord_value_type> m_xspan{};
  rmath::range<coord_value_type> m_yspan{};
  rmath::range<coord_value_type> m_zspan{};
  /* clang-format on */
};

} /* namespace rcppsw::spatial */
