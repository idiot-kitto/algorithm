#include <bits/stdc++.h>
using namespace std;

int solution(string name) {
    int answer = 0, cnt = 0, next = 0;
    int arr[name.size()], check[name.size()];
    queue<int> q;
    
    for(int i=0 ; i<name.size() ; i++){
        if(name[i] != 'A') {check[i] = 1; cnt++;}
        else check[i] = 0;
        arr[i] = name[i] - 'A';
        if(arr[i]>13) arr[i] = 26 - arr[i];
    }
    while(q.size() != cnt){
        if(check[next] == 1){
            q.push(next);
            check[next] = 0;
        }
        else {
            int l = next, r = next, move = 0;
            while(1){
                r++; l--; move++;
                if(r >= name.size()) r = 0;
                else if(l < 0) l = name.size()-1;
                
                if(check[r] == 1) {next = r; break;}
                else if(check[l] == 1) {next = l; break;}
            }
            answer += move;
        }
    }
    while(!q.empty()){
        answer += arr[q.front()];
        q.pop();
    }
    
    return answer;
}
