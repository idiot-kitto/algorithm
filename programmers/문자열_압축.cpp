#include <bits/stdc++.h>
using namespace std;

int solution(string s) {
    int answer = s.size();
    for(int i=1 ; i<=s.size()/2 ; i++){
        string ss, tmp; int cnt = 1;
        for(int j=0 ; j<s.size() ; j+=i){
            if(!j) tmp = s.substr(j,i);
            else{
                if(s.substr(j,i) == tmp) cnt++;
                else{
                    if(cnt > 1) ss += to_string(cnt); 
                    ss += tmp; tmp = s.substr(j,i); cnt = 1;
                }
            }
        }
        if(cnt > 1) ss += to_string(cnt);
        ss += tmp;
        answer = min(answer, (int)ss.size());
    }
    return answer;
}
