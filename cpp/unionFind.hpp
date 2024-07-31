#include <vector>
using namespace std;
using ll = long long;

struct UF {
  vector<int> _parent, _size;
  UF(int n) {
    _parent = vector<int>(n, -1);
    _size = vector<int>(n, 1);
  }

  int leader(int n) {
    auto a = n;
    vector<int> B;
    while (_parent[a] != -1) {
      B.push_back(a);
      a = _parent[a];
    }
    // 経路圧縮
    for (auto b : B) {
      _parent[b] = a;
    }

    return a;
  }

  void merge(int a, int b) {
    int leaa = leader(a);
    int leab = leader(b);
    if (leaa == leab) {
      return;
    }

    // union by size
    if (_size[leaa] < _size[leab]) {
      swap(leaa, leab);
    }
    _parent[leab] = leaa;
    _size[leaa] += _size[leab];
  }

  bool same(int a, int b) { return leader(a) == leader(b); }

  int size(int n) { return _size[leader(n)]; }
};
