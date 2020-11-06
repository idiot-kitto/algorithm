#include <bits/stdc++.h>
using namespace std;

vector<int> solution(string s) {
    vector<int> answer, v;
    int ans1 = 0, ans2 = 0;
    for(int i=0 ; i<s.size() ; i++) v.push_back(s[i]-'0');
    while(1){
        if(v.size() == 1 && v[0] == 1) break;
        int k = 0;
        ans1++;
        for(int i=0 ; i<v.size() ; i++)
            if(!v[i]){
                v.erase(v.begin() + i, v.begin() + i + 1);
                k++;
                i = -1;
            }
        ans2 += k; k = v.size(); v.clear();
        while(k){v.push_back(k % 2); k /= 2;} 
        reverse(v.begin(),v.end());
    }
    answer.push_back(ans1);
    answer.push_back(ans2);
    return answer;
}
