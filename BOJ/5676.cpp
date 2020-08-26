#include <bits/stdc++.h>
using namespace std;
int n, k, i, j, V;
char c;
string ans;
vector<int> X, tree;

int init(int node, int s, int e)
{
    int m = (s+e) / 2;
    if(s==e) return tree[node] = X[s];
    else return tree[node] = init(node*2, s, m) * init(node*2+1, m+1, e);
}

void update(int node, int s, int e, int idx, int v)
{
    if(s>idx || idx>e) return;
    tree[node] *= v;
    if(s!=e){
        int m = (s+e) / 2;
        update(node*2, s, m, idx, v);
        update(node*2+1, m+1, e, idx, v);
    }
}

int query(int node, int s, int e, int l, int r)
{
    if(l>e || r<s) return 1;
    if(l<=s && e<=r) return tree[node];
    int m = (s+e) / 2;
    return query(node*2, s, m, l, r) * query(node*2+1, m+1, e, l, r);
}

int main()
{ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    while(cin>>n>>k){
        ans = "";
        X.resize(n); tree.resize(4*n);
        for(int i=0 ; i<n ; i++) {
            int temp; cin >> temp;
            if(temp > 0) X[i] = 1;
            else if(temp < 0) X[i] = -1;
            else if(temp == 0) X[i] = 0;
        }
        init(1, 0, n-1);
        while(k--){
            cin >> c;
            if(c == 'C'){
                cin >> i >> V;
                if(V > 0) V = 1;
                else if(V < 0) V = -1;
                if(X[i-1] == 0){
                    if(V>0 || V<0){
                        X[i-1] = V;
                        init(1, 0, n-1);
                    }
                }
                else{
                    if(X[i-1] == 1 && V == -1) {
                        X[i-1] = V;
                        update(1, 0, n-1, i-1, V);
                    }
                    else if(X[i-1] == -1 && V == 1){
                        X[i-1] = V;
                        update(1, 0, n-1, i-1, -V);
                    }
                    else if(V == 0){
                        X[i-1] = V;
                        update(1, 0, n-1, i-1, V);
                    }
                }
            }
            else if(c == 'P'){
                cin >> i >> j;
                int tmp = query(1, 0, n-1, i-1, j-1);
                if(tmp > 0) ans += "+";
                else if(tmp < 0) ans += "-";
                else if(tmp == 0) ans += "0";
            }
        }
        cout << ans << "\n";
    }
    return 0;
}

/*
풀면서 상당히 못짰다고 느낀 코드다..
기존 리프노드의 부호와 바꾸는 노드의 부호가 다를 때, 0 일 때 각각의 경우를 모두 생각하느라 힘들었다.
그리고 원래 노드가 0 일때에도 update를 해서 풀어야하는 의도가 아니었을까 싶은데 귀찮아서 init을 해버렸는데도 AC를 받았다.
테스트케이스에서 0 으로 바꾸는 작업이 많이 없었던것 같다.ㅋㅋ
재채점에서 TLE가 뜨면 그때 수정해야겠다.(금방할듯) 지금은 머리가 아프다.
*/
