// iterator find_by_order(k): 0-indexed
// size_type order_of_key(key): min id s.t. >= key
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
template <class T> using rbtree = __gnu_pbds::tree<
  T,
  __gnu_pbds::null_type,
  std::less<T>,
  __gnu_pbds::rb_tree_tag,
  __gnu_pbds::tree_order_statistics_node_update
>;
