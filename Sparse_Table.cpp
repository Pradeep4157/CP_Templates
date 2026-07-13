#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    can be used to find Range min, max, gcd

*/
int log2(long long x)
{
    return 62 - __builtin_clz(x); // use 31 incase using int..
}
int log2(int x)
{
    return 31 - __buildin_clz(x);
}
struct sparse_table
{
    // table[i][j] -> min [j...j + 2^i - 1].
    int n;
    int max_pow;
    vector<vector<int>> table;
    void init(int pow, vector<int> arr)
    {
        n = arr.size();
        max_pow = log2(n) + 1;
        table.resize(max_pow, vector<int>(n));
        for (int i = 0; i < n; i++)
        {
            table[0][i] = arr[i];
        }
        for (int i = 1; i < max_pow; i++)
        {
            for (int j = 0; (j + (1 << i) - 1) < n; j++)
            {
                table[i][j] = min(table[i - 1][j], table[i][j + (1 << (i - 1))]);
            }
        }
    }
    int query(int l, int r)
    { // O(logn)
        int ans = 1e9;
        int idx = l;
        for (int i = log2(r - l + 1); i >= 0; i--)
        {
            if (idx + (1 << i) - 1 <= r)
            {
                ans = min(ans, table[i][idx]);
                idx += (1 << i);
            }
        }
        return ans;
    }
    int query_2(int l, int r)
    { // O(1)
        int len = r - l + 1;
        int log_len = log2(len);
        int ans = min(table[log_len][l], table[log_len][r - (1 << log_len) + 1]);
        return ans;
    }
}