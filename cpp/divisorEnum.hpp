
#include <algorithm>
#include <vector>
using namespace std;

vector<long long> primeFactorize(long long N) {
  vector<long long> ansvec;
  for (long long i = 1; i * i <= N; ++i) {
    if (N % i == 0) {
      ansvec.push_back(i);
      auto b = N / i;
      if (i != b) {
        ansvec.push_back(b);
      }
    }
  }

  sort(ansvec.begin(), ansvec.end());

  return ansvec;
}
