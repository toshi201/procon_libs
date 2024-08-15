#include <functional>
#include <vector>
using namespace std;
using ll = long long;

template <typename T> struct SegTree {

  using F = function<T(T, T)>;
  using F2 = function<T()>;
  vector<T> _node;
  int _array_len, _leaf_cnt;
  F op;
  F2 e;
  SegTree(vector<T> A, F op, F2 e) : op(op), e(e) {
    _array_len = A.size();
    _leaf_cnt = 1;
    while (_leaf_cnt < _array_len) {
      _leaf_cnt <<= 1;
    }
    _node = vector<T>(_leaf_cnt * 2, e());
    for (int i = 0; i < _array_len; ++i) {
      _node[i + _leaf_cnt] = A[i];
    }

    for (int i = _leaf_cnt - 1; i > 0; --i) {
      auto left_child = _node[(i << 1) | 0];
      auto right_child = _node[(i << 1) | 1];
      _node[i] = op(left_child, right_child);
    }
  }

  void set(int p, T x) {
    int node_num = p + _leaf_cnt;
    _node[node_num] = x;

    while (node_num > 1) {
      node_num >>= 1;
      auto left_child = _node[(node_num << 1) | 0];
      auto right_child = _node[(node_num << 1) | 1];
      _node[node_num] = op(left_child, right_child);
    }
  }

  T prod(int l, int r) {
    l += _leaf_cnt;
    r += _leaf_cnt;
    auto ans = e();
    while (l < r) {
      if (l & 1) {
        ans = op(ans, _node[l]);
        l++;
      }
      if (r & 1) {
        r--;
        ans = op(ans, _node[r]);
      }
      l >>= 1;
      r >>= 1;
    }
    return ans;
  }

  T get(int p) { return _node[p + _leaf_cnt]; }
};
