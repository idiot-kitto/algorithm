#include <bits/stdc++.h>
using namespace std;
int n, m, s, e, maxc;
int visited[100001];
vector<pair<int,int>> v[100001];

int bfs(int k)
{
    queue<int> q;
    q.push(s);
    visited[s] = 1;

    while(!q.empty()){
        int current = q.front();
        q.pop();
        if(current==e) return 1;

        for(int i=0 ; i<v[current].size() ; i++){
            int next = v[current][i].first;
            int nextc = v[current][i].second;
            if(!visited[next] && k<=nextc){
                visited[next] = 1;
                q.push(next);
            }
        }
    }
    return 0;
}

int main()
{ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=0 ; i<m ; i++){
        int a,b,c;
        cin>>a>>b>>c;
        v[a].push_back({b,c});
        v[b].push_back({a,c});
        maxc = max(maxc,c);
    }
    cin>>s>>e;

    int l=0, h=maxc;
    while(l<=h){
        memset(visited,0,sizeof(visited));
        int m=(l+h)/2;
        if(bfs(m)) l=m+1;
        else h=m-1;
    }
    cout << h;

    return 0;
}
