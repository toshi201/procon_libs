
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;
using matrix = vector<vector<ll>>;
matrix mat_mul(matrix &A, matrix &B, ll mod) {
    int N = A.size();
    vector C(N, vector(N, 0LL));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < N; ++k) {
                C[i][j] += A[i][k] * B[k][j];
                C[i][j] %= mod;
            }
        }
    }
    return C;
}

matrix pow_mat(matrix &A, ll b, ll mod) {
    int N = A.size();
    vector C(N, vector(N, 0LL));
    for (int i = 0; i < N; ++i) {
        C[i][i] = 1;
    }
    auto B = A;
    for (int i = 0; i < 64; ++i) {
        if (b & (1LL << i)) {
            C = mat_mul(B, C, mod);
        }
        B = mat_mul(B, B, mod);
    }
    return C;
}