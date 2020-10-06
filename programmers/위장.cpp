#include <bits/stdc++.h>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string,int> mp;
    for(int i=0 ; i<clothes.size() ; i++) mp[clothes[i][1]]++;
    for(auto iter = mp.begin() ; iter != mp.end() ; iter++) answer *= iter->second + 1;
    return answer - 1;
}
