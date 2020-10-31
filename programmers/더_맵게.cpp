#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int solution(vector<int> scoville, int k) {
    int answer = 0; sort(scoville.begin(),scoville.end());
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i=0 ; i<scoville.size() ; i++) pq.push(scoville[i]);
    while(pq.top() < k){
        if(pq.size() == 1) break;
        answer++;
        ll a = pq.top(); pq.pop();
        ll b = pq.top(); pq.pop();
        pq.push(a + 2 * b);
    }
    if(pq.top() < k) return -1;
    else return answer;
}
