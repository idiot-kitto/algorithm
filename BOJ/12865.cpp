#include <bits/stdc++.h>
using namespace std;
int d[101][100001], w[101], v[101];
int n, k;
int main()
{ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> n >> k;
    for (int i=1; i<=n; i++) cin >> w[i] >> v[i];
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=k; j++) {
            d[i][j] = d[i-1][j];
            if (j >= w[i])
                d[i][j] = max(d[i][j], d[i-1][j-w[i]] + v[i]);
        }
    }
    cout << d[n][k];
    return 0;
}

/*
max(d[i][j] : i번째 물건을 담지 않은 경우 , d[i-1][j-w[i]] + v[i] : i번째 물건을 담은 경우)
*/
