// Distributed under the MIT License.
// See LICENSE.txt for details.

#include "DataStructures/Index.hpp"

#include "Utilities/GenerateInstantiations.hpp"

/// \cond HIDDEN_SYMBOLS
template <size_t Dim>
bool operator==(const Index<Dim>& lhs, const Index<Dim>& rhs) noexcept {
  return std::equal(lhs.begin(), lhs.end(), rhs.begin());
}

template <size_t Dim>
bool operator!=(const Index<Dim>& lhs, const Index<Dim>& rhs) noexcept {
  return not(lhs == rhs);
}

#define DIM(data) BOOST_PP_TUPLE_ELEM(0, data)
#define GEN_OP(op, dim)                            \
  template bool operator op(const Index<dim>& lhs, \
                            const Index<dim>& rhs) noexcept;
#define INSTANTIATE(_, data)       \
  template class Index<DIM(data)>; \
  GEN_OP(==, DIM(data))            \
  GEN_OP(!=, DIM(data))

GENERATE_INSTANTIATIONS(INSTANTIATE, (0, 1, 2, 3))

#undef DIM
#undef GEN_OP
#undef INSTANTIATE
/// \endcond
