#include<vector>
#include<algorithm>
using namespace std;

template <typename T>
vector<T> coordinate_compress(vector<T>& A) {
    vector<T> B = A;
    sort(B.begin(), B.end());
    B.erase(unique(B.begin(), B.end()), B.end());

    int N = A.size();
    vector<T> C(N);
    for (int i = 0; i < N; ++i) {
        C[i] = lower_bound(B.begin(), B.end(), A[i]) - B.begin();
    }

    return C;
}
