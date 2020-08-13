#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll dp[31][31];
ll solve(int w, int h){
    if(dp[w][h]) return dp[w][h];
    if(!w) return 1;
    dp[w][h] = solve(w-1,h+1);
    if(h) dp[w][h] += solve(w,h-1);
    return dp[w][h];
}

int main()
{ios_base::sync_with_stdio(false);
    while(1){
        cin >> n; if(!n) break;
        cout << solve(n,0) << "\n";
    }
    return 0;
}

/*
재귀와 dp를 이용했다. 숫자가 int범위를 벗어날 정도로 커지기 때문에 long long을 사용한다.
문자열에 w를 먼저 사용해야 h를 사용할 수 있다. (9번줄)
dp배열에 이미 저장된 값은 새로 계산하지않고 가져와 쓰여지도록 함으로써 (7번줄) TLE를 피할 수 있다.
*/
