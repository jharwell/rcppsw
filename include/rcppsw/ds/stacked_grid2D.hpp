/**
 * \file stacked_grid2D.hpp
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

#ifndef INCLUDE_RCPPSW_DS_STACKED_GRID2D_HPP_
#define INCLUDE_RCPPSW_DS_STACKED_GRID2D_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <tuple>
#include <utility>
#include <vector>

#include "rcppsw/ds/grid2D_overlay.hpp"
#include "rcppsw/math/vector2.hpp"
#include "rcppsw/types/discretize_ratio.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, ds);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * \class stacked_grid2D
 * \ingroup ds
 *
 * \brief A sandwich of N 2D grids of the same size (x,y) dimensions, which can
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
class stacked_grid2D {
 public:
  /**
   * \param origin The anchor point of the stacked grid in continuous space.
   * \param dims The real size in X,Y which will be discretized into
   *             X/\p grid_res discrete elements along the X dimension and
   *             Y/\p grid_res discrete elements along the Y dimension.
   * \param grid_res The discretization unit for the grid.
   * \param field_res The discretization unit for the field the grid is
   * contained in (can be the same as the \p grid_res).
   */
  stacked_grid2D(const math::vector2d& origin,
                 const math::vector2d& dims,
                 const types::discretize_ratio& grid_res,
                 const types::discretize_ratio& field_res)
      : m_layers(kStackSize) {
    add_layers<kStackSize - 1>(origin, dims, grid_res, field_res);
  }

  virtual ~stacked_grid2D(void) { rm_layers<kStackSize - 1>(); }

  /**
   * \brief The type of the objects stored in a particular layer.
   * \tparam Index The index of the layer.
   */
  template <size_t Index>
  using value_type = typename std::tuple_element<Index, TupleTypes>::type;

  /**
   * \brief The type of a particular layer.
   * \tparam Index The index of the layer.
   */
  template <size_t Index>
  using layer_value_type = rcppsw::ds::grid2D_overlay<value_type<Index>>;

  /**
   * \brief Get a reference to an object at a particular (layer,i,j) location
   *
   * \tparam Index The index of the layer.
   * \param i The x coordinate.
   * \param j The y coordinate.
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
   * \brief Get a reference to an object at a particular (layer,i,j) location
   *
   * \tparam Index The index of the layer.
   * \param d The discrete coordinate pair.
   */
  template <size_t Index>
  typename layer_value_type<Index>::value_type& access(const math::vector2z& d) {
    return access<Index>(d.x(), d.y());
  }
  template <size_t Index>
  const typename layer_value_type<Index>::value_type&
  access(const math::vector2z& d) const {
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
   * \see \ref grid2D_overlay::xdsize().
   */
  size_t xdsize(void) const {
    return (reinterpret_cast<const layer_value_type<0>*>(m_layers[0]))->xdsize();
  }

  rmath::vector2d rdims2D(void) const {
    return (reinterpret_cast<const layer_value_type<0>*>(m_layers[0]))->rdims2D();
  }

  rmath::vector2z ddims2D(void) const {
    return (reinterpret_cast<const layer_value_type<0>*>(m_layers[0]))->ddims2D();
  }

  /**
   * \see \ref grid2D_overlay::xrsize().
   */
  double xrsize(void) const {
    return (reinterpret_cast<const layer_value_type<0>*>(m_layers[0]))->xrsize();
  }

  /**
   * \see \ref grid2D_overlay::ydsize().
   */
  size_t ydsize(void) const {
    return (reinterpret_cast<const layer_value_type<0>*>(m_layers[0]))->ydsize();
  }

  /**
   * \see \ref grid2D_overlay::yrsize().
   */
  double yrsize(void) const {
    return (reinterpret_cast<const layer_value_type<0>*>(m_layers[0]))->yrsize();
  }

  /**
   * \see \ref grid2D_overlay::resolution().
   */
  const types::discretize_ratio& resolution(void) const {
    return (reinterpret_cast<const layer_value_type<0>*>(m_layers[0]))
        ->resolution();
  }

 private:
  static size_t constexpr kStackSize = std::tuple_size<TupleTypes>::value;

  /**
   * \brief Add layers when you have at least 2 layers to add. SFINAE is needed
   * to prevent negative indices in the degenerate case where the stacked grid
   * only has 1 layer.
   */
  template <size_t Index, RCPPSW_SFINAE_DECLDEF((Index > 0)), typename... Args>
  void add_layers(Args&&... args) {
    add_layer<Index, Args...>(std::forward<Args>(args)...);
    add_layer<Index - 1, Args...>(std::forward<Args>(args)...);
  }

  /**
   * \brief Add layers when you only have 1 layer to add. SFINAE is needed to
   * prevent negative indices in the degenerate case where the stacked grid only
   * has 1 layer.
   */
  template <size_t Index, RCPPSW_SFINAE_DECLDEF((Index == 0)), typename... Args>
  void add_layers(Args&&... args) {
    add_layer<Index, Args...>(std::forward<Args>(args)...);
  }

  /**
   * \brief Add a layer to the stacked grid.
   *
   * Note the reversal of indices! Because of the way recursive instantiation
   * works, we can only start at an index > 0, and go DOWN, but the user
   * specified the order of layers going FORWARD/UP.
   */
  template <size_t Index, typename... Args>
  void add_layer(Args&&... args) {
    m_layers[kStackSize - Index - 1] =
        new layer_value_type<kStackSize - Index - 1>(std::forward<Args>(args)...);
  }

  template <size_t Index>
  void rm_layers(void) {
    rm_layer<Index>();
  }

  /**
   * \brief Delete a layer from the stacked grid when there are at least 2
   * layers. Indice reversal is not really necessary here, but doing it for
   * reasons of Principle of Least Surprise.
   */
  template <size_t Index, RCPPSW_SFINAE_DECLDEF((Index > 0))>
  void rm_layer(void) {
    delete reinterpret_cast<const layer_value_type<Index>*>(
        m_layers[kStackSize - Index - 1]);
  }

  /**
   * \brief Remove a layer from the stacked grid when you only have 1 layer.
   */
  template <size_t Index, RCPPSW_SFINAE_DECLDEF((Index == 0))>
  void rm_layer(void) {
    delete reinterpret_cast<const layer_value_type<0>*>(m_layers[0]);
  }

  /* clang-format off */
  std::vector<void*> m_layers;
  /* clang-format on */
};

NS_END(ds, rcppsw);

#endif /* INCLUDE_RCPPSW_DS_STACKED_GRID2D_HPP_ */
