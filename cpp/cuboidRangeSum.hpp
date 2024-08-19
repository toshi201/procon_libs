#include <vector>
using namespace std;

template <typename T> struct CuboidRangeSum {
  vector<vector<vector<T>>> _cumA;

  CuboidRangeSum(vector<vector<vector<T>>> &vec) {
    int N = vec.size();
    vector cumA(N + 1, vector(N + 1, vector<T>(N + 1, 0)));
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        for (int k = 0; k < N; ++k) {
          cumA[i + 1][j + 1][k + 1] =
              vec[i][j][k] + cumA[i][j][k] - cumA[i][j + 1][k] -
              cumA[i + 1][j][k] - cumA[i][j][k + 1] + cumA[i + 1][j + 1][k] +
              cumA[i][j + 1][k + 1] + cumA[i + 1][j][k + 1];
        }
      }
    }
    _cumA = cumA;
  }

  T sum(int lx, int rx, int ly, int ry, int lz, int rz) {
    auto ans = _cumA[rx][ry][rz] - _cumA[rx][ly][rz] - _cumA[rx][ry][lz] -
               _cumA[lx][ry][rz] + _cumA[rx][ly][lz] + _cumA[lx][ry][lz] +
               _cumA[lx][ly][rz] - _cumA[lx][ly][lz];
    return ans;
  }
};
