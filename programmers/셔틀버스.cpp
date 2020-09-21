#include <bits/stdc++.h>
using namespace std;

string solution(int n, int t, int m, vector<string> timetable) {
    string answer;
    int start = 540, num = 0, ans = 0; vector<int> v;
    for(int i=0 ; i<timetable.size() ; i++)
        v.push_back(stoi(timetable[i].substr(0,2))*60 + stoi(timetable[i].substr(3,5)));
    sort(v.begin(),v.end());
    
    for(int i=0 ; i<n ; i++){
        int full = m;
        for(int j=num ; j<v.size() ; j++)
            if(v[j]<=start){num++;full--; if(!full)break;}
        if(i==n-1){
            if(!full) ans = v[num-1]-1;
            else ans = start;
        }
        start += t;
    }
    if(ans/60 < 10) {answer+="0";answer+=to_string(ans/60);}
    else answer+=to_string(ans/60);
    answer+=":";
    if(ans%60 < 10) {answer+="0";answer+=to_string(ans%60);}
    else answer+=to_string(ans%60);
    
    return answer;
}
