/**
 * Author: Lukas Polacek
 * Date: 2009-10-28
 * License: CC0
 * Description: Sparse Table
 * Time: O(1)
 * Status: Bruteforce-tested for N <= 5
 */
#pragma once


const int N = 2e5+5;
int sparse[N][20], a[N];
int LOG[N];
int n;
 
int query(int L, int R){
    int length = R - L + 1;
    int k = LOG[length];
    return __gcd(sparse[L][k], sparse[R - (1 << k) + 1][k]);
}
 
int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    LOG[1] = 0;
    for(int i=2; i<N; i++)LOG[i] = LOG[i/2] + 1;
    int t; cin >> t;
    while(t--){
        cin >> n;
        for(int i=0; i<n; i++)cin >> a[i];
        for(int i=0; i<n; i++)sparse[i][0] = abs(a[i+1] - a[i]);
        for(int j = 1; j < 20; j++)
            for(int i=0; i + (1 << j) - 1 < n - 1; ++i)
                sparse[i][j] = __gcd(sparse[i][j-1], sparse[i + (1 << (j-1))][j-1]);
    }
}
