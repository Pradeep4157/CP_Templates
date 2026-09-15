const long long MOD1 = 1e9 + 7;
const long long MOD2 = 1e9 + 9;
const long long BASE = 911382323;

struct Hashing {
    int n;
    string s, rev;

    vector<long long> h1, h2, rh1, rh2;
    vector<long long> p1, p2;

    Hashing(string _s) {
        s = _s;
        n = s.size();

        rev = s;
        reverse(rev.begin(), rev.end());

        h1.resize(n + 1);
        h2.resize(n + 1);
        rh1.resize(n + 1);
        rh2.resize(n + 1);

        p1.resize(n + 1);
        p2.resize(n + 1);

        p1[0] = p2[0] = 1;

        for (int i = 0; i < n; i++) {
            p1[i + 1] = p1[i] * BASE % MOD1;
            p2[i + 1] = p2[i] * BASE % MOD2;

            h1[i + 1] = (h1[i] * BASE + (s[i] - 'a' + 1)) % MOD1;
            h2[i + 1] = (h2[i] * BASE + (s[i] - 'a' + 1)) % MOD2;

            rh1[i + 1] = (rh1[i] * BASE + (rev[i] - 'a' + 1)) % MOD1;
            rh2[i + 1] = (rh2[i] * BASE + (rev[i] - 'a' + 1)) % MOD2;
        }
    }

    pair<long long, long long> getHash(
        vector<long long>& h1,
        vector<long long>& h2,
        int l,
        int r
    ) {
        long long x1 = (h1[r + 1] - h1[l] * p1[r - l + 1]) % MOD1;
        long long x2 = (h2[r + 1] - h2[l] * p2[r - l + 1]) % MOD2;

        if (x1 < 0) x1 += MOD1;
        if (x2 < 0) x2 += MOD2;

        return {x1, x2};
    }

    bool isPalindrome(int l, int r) {
        int rl = n - 1 - r;
        int rr = n - 1 - l;

        return getHash(h1, h2, l, r)
            == getHash(rh1, rh2, rl, rr);
    }
};
