/**
 * @file stacked_grid.hpp
 *
 * @copyright 2018 John Harwell, All rights reserved.
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
#include <tuple>
#include <vector>

#include "rcppsw/ds/overlay_grid2D.hpp"
#include "rcppsw/math/vector2.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, ds);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @class stacked_grid
 * @ingroup rcppsw ds
 *
 * @brief A sandwich of N 2D grids of the same size (x,y) dimensions, which can
 * contain different kinds of objects. The objects in each layer of the grid are
 * stored contiguously, but the grids themselves are not necessarily
 * contiguous. The layers are 0 indexed.
 *
 * This was implemented because the BGL only appears to support layered
 * graphs/grids of the same object type. Although in hindsight I could have done
 * this with grid_graph and boost::variant (was not aware of this when I
 * implemented this class). Might not have been as highly performing in that
 * case though.
 */
template <typename TupleTypes>
class stacked_grid {
 public:
  stacked_grid(double resolution, double x_max, double y_max)
      : m_layers(kStackSize) {
    add_layers<kStackSize - 1>(resolution, x_max, y_max);
  }

  virtual ~stacked_grid(void) { rm_layers<kStackSize - 1>(); }

  /**
  * @brief The type of the objects stored in a particular layer.
  * @tparam Index The index of the layer.
  */
  template <size_t Index>
  using value_type = typename std::tuple_element<Index, TupleTypes>::type;

  /**
   * @brief The type of a particular layer.
   * @tparam Index The index of the layer.
   */
  template <size_t Index>
  using layer_value_type = rcppsw::ds::overlay_grid2D<value_type<Index>>;

  /**
   * @brief Get a reference to an object at a particular (layer,i,j) location
   *
   * @tparam Index The index of the layer.
   * @param i The x coordinate.
   * @param j The y coordinate.
   */
  template <size_t Index>
  typename layer_value_type<Index>::value_type& access(size_t i, size_t j) {
    return reinterpret_cast<layer_value_type<Index>*>(m_layers[Index])
        ->access(i, j);
  }

  template <size_t Index>
  const typename layer_value_type<Index>::value_type& access(size_t i,
                                                             size_t j) const {
    return reinterpret_cast<const layer_value_type<Index>*>(m_layers[Index])
        ->access(i, j);
  }

  /**
   * @brief Get a reference to an object at a particular (layer,i,j) location
   *
   * @tparam Index The index of the layer.
   * @param d The discrete coordinate pair.
   */
  template <size_t Index>
  typename layer_value_type<Index>::value_type& access(const math::vector2u& d) {
    return access<Index>(d.x(), d.y());
  }
  template <size_t Index>
  const typename layer_value_type<Index>::value_type& access(
      const math::vector2u& d) const {
    return access<Index>(d.x(), d.y());
  }

  template <size_t Index>
  layer_value_type<Index>* layer(void) {
    return reinterpret_cast<layer_value_type<Index>*>(m_layers[Index]);
  }
  template <size_t Index>
  const layer_value_type<Index>* layer(void) const {
    return reinterpret_cast<const layer_value_type<Index>*>(m_layers[Index]);
  }

  /**
   * @see \ref base_overlay_grid2D::xdsize().
   */
  size_t xdsize(void) const {
    return (reinterpret_cast<const layer_value_type<0>*>(m_layers[0]))->xdsize();
  }

  /**
   * @see \ref base_overlay_grid2D::xrsize().
   */
  double xrsize(void) const {
    return (reinterpret_cast<const layer_value_type<0>*>(m_layers[0]))->xrsize();
  }

  /**
   * @see \ref base_overlay_grid2D::ydsize().
   */
  size_t ydsize(void) const {
    return (reinterpret_cast<const layer_value_type<0>*>(m_layers[0]))->ydsize();
  }

  /**
   * @see \ref base_overlay_grid2D::yrsize().
   */
  double yrsize(void) const {
    return (reinterpret_cast<const layer_value_type<0>*>(m_layers[0]))->yrsize();
  }

  /**
   * @see \ref base_overlay_grid2D::resolution().
   */
  double resolution(void) const {
    return (reinterpret_cast<const layer_value_type<0>*>(m_layers[0]))
        ->resolution();
  }

 private:
  static size_t constexpr kStackSize = std::tuple_size<TupleTypes>::value;

  template <size_t Index, typename... Args>
  void add_layers(Args&&... args) {
    add_layer<Index, Args...>(std::forward<Args>(args)...);
    add_layer<Index - 1, Args...>(std::forward<Args>(args)...);
  }

  /**
   * @brief Add a layer to the stacked grid.
   *
   * Note the reversal of indices! Because of the way recursive instantiation
   * works, we can only start at an index > 0, and go DOWN, but the user
   * specified the order of layers going FORWARD/UP.
   */
  template <size_t Index, typename... Args>
  void add_layer(Args&&... args) {
    m_layers[kStackSize - Index - 1] =
        new layer_value_type<kStackSize - Index - 1>(
            std::forward<Args>(args)...);
  }

  template <size_t Index>
  void rm_layers(void) {
    rm_layer<Index>();
  }

  /**
   * @brief Delete a layer from the stacked grid. Indice reversal is not really
   * necessary here, but doing it for reasons of Principle of Least Surprise.
   */
  template <size_t Index>
  void rm_layer(void) {
    delete reinterpret_cast<const layer_value_type<1>*>(
        m_layers[kStackSize - Index - 1]);
  }

  /* clang-format off */
  std::vector<void*> m_layers;
  /* clang-format on */
};

NS_END(ds, rcppsw);

#endif /* INCLUDE_RCPPSW_DS_STACKED_GRID_HPP_ */
