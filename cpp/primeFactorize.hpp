#include <map>
using namespace std;

map<long long, int> primeFactorize(long long N) {
  auto N2 = N;
  map<long long, int> ans;

  for (int i = 2; i * i <= N; ++i) {
    int cnt = 0;
    while (N2 % i == 0) {
      N2 /= i;
      cnt++;
    }
    if (cnt > 0) {
      ans[i] = cnt;
    }
  }
  if (N2 != 1) {
    ans[N2] = 1;
  }
  return ans;
}
