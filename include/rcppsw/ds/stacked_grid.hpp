/**
 * @file stacked_grid.hpp
 *
 * @copyright 2017 John Harwell, All rights reserved.
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

#ifndef INCLUDE_RCPPSW_DS_STACKED_GRID_HPP_
#define INCLUDE_RCPPSW_DS_STACKED_GRID_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <vector>
#include <tuple>

#include "rcppsw/ds/grid2D.hpp"
#include "rcppsw/common/common.hpp"
#include "rcppsw/math/dcoord.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, ds);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @class stacked_grid2
 * @ingroup ds
 *
 * @brief A sandwich of 2 2D grids of the same size (x,y) dimensions, which can
 * contain different kinds of objects. The objects in each layer of the grid are
 * stored contiguously, but the grids themselves are not necessarily
 * contiguous. The layers are 0 indexed.
 *
 * This was implemented because the BGL only appears to support layered
 * graphs/grids of the same object type.
 */
template<typename TupleTypes>
class stacked_grid2 {
 public:
  stacked_grid2(double resolution, size_t x_max, size_t y_max)
      : m_layers() {
    add_layer<value_type<0>>(resolution, x_max, y_max);
    add_layer<value_type<1>>(resolution, x_max, y_max);
  }
  virtual ~stacked_grid2(void) {
    delete reinterpret_cast<const layer_type<0>*>(m_layers[0]);
    delete reinterpret_cast<const layer_type<1>*>(m_layers[1]);
  }

  template <class T>
  using layer = rcppsw::ds::grid2D<T>;

  /**
   * @brief The type of the objects stored in a particular layer.
   * @tparam The index of the layer.
   */
  template<uint Index>
  using value_type = typename std::tuple_element<Index, TupleTypes>::type;

  /**
   * @brief The type of a particular layer.
   * @tparam The index of the layer.
   */
  template<uint Index>
  using layer_type = rcppsw::ds::grid2D<value_type<Index>>;

  /**
   * @brief Get a reference to an object at a particular (layer,i,j) location
   *
   * @tparam The index of the layer.
   * @param i The x coordinate.
   * @param j The y coordinate.
   *
   * @return The object at the specified location.
   */
  template<uint Index>
  typename layer_type<Index>::value_type& access(size_t i, size_t j) {
    return reinterpret_cast<layer_type<Index>*>(m_layers[Index])->access(i, j);
  }

  template<uint Index>
  const typename layer_type<Index>::value_type& access(size_t i, size_t j) const {
    return reinterpret_cast<const layer_type<Index>*>(m_layers[Index])->access(i, j);
  }

  /**
   * @brief Get a reference to an object at a particular (layer,i,j) location
   *
   * @tparam The index of the layer.
   * @param d The discrete coordinate pair.
   *
   * @return The object at the specified location.
   */
  template <int Index>
  typename layer_type<Index>::value_type& access(const math::dcoord2& d) {
    return access<Index>(d.first, d.second);
  }
  template <int Index>
  const typename layer_type<Index>::value_type& access(const math::dcoord2& d) const {
    return access<Index>(d.first, d.second);
  }

  /**
   * @see \ref base_grid2D::xdsize().
   */
  size_t xdsize(void) const {
    return (reinterpret_cast<const layer_type<0>*>(m_layers[0]))->xdsize();
  }

  /**
   * @see \ref base_grid2D::xrsize().
   */
  size_t xrsize(void) const {
    return (reinterpret_cast<const layer_type<0>*>(m_layers[0]))->xrsize();
  }

  /**
   * @see \ref base_grid2D::ydsize().
   */
  size_t ydsize(void) const {
    return (reinterpret_cast<const layer_type<0>*>(m_layers[0]))->ydsize();
  }

  /**
   * @see \ref base_grid2D::yrsize().
   */
  size_t yrsize(void) const {
    return (reinterpret_cast<const layer_type<0>*>(m_layers[0]))->yrsize();
  }

  /**
   * @see \ref base_grid2D::resolution().
   */
  double resolution(void) const {
    return (reinterpret_cast<const layer_type<0>*>(m_layers[0]))->resolution();
  }

 private:
  template<typename LayerType, typename... Args>
  void add_layer(Args&&... args) {
    m_layers.emplace_back(new layer<LayerType>(std::forward<Args>(args)...));
  }
  std::vector<void*> m_layers;
};

NS_END(ds, rcppsw);

#endif /* INCLUDE_RCPPSW_DS_STACKED_GRID_HPP_ */
