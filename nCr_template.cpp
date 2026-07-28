const long long mod = (long long)(1e9 + 7);

vector<long long> fact, invFact;

long long modPow(long long a, long long b) {
    long long res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

void initNCR(int MAXN) {
    fact.resize(MAXN + 1);
    invFact.resize(MAXN + 1);

    fact[0] = 1;
    for (int i = 1; i <= MAXN; i++)
        fact[i] = fact[i - 1] * i % mod;

    invFact[MAXN] = modPow(fact[MAXN], mod - 2);

    for (int i = MAXN - 1; i >= 0; i--)
        invFact[i] = invFact[i + 1] * (i + 1) % mod;
}

long long nCr(long long n, long long r) {
    if (r < 0 || r > n) return 0;
    return fact[n] * invFact[r] % mod * invFact[n - r] % mod;
}
int main(){
  int n;
  cin >> n;
  initNCR(n + 1);
}
