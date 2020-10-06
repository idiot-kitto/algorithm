#include <bits/stdc++.h>
using namespace std;
vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer; map<string, int> mp; vector<pair<string,int>> v;
    
    for(int i=0 ; i<genres.size() ; i++) mp[genres[i]] += plays[i];
    for(auto iter = mp.begin() ; iter != mp.end() ; iter++) v.push_back({iter->first,iter->second});
    sort(v.begin(),v.end(),[](const pair<string,int> &v1, const pair<string,int> &v2){
        return v1.second > v2.second;});
    for(int i=0 ; i<v.size() ; i++){
        vector<pair<int,int>> tmp;
        for(int j=0 ; j<genres.size() ; j++) 
            if(v[i].first == genres[j]) tmp.push_back({j,plays[j]});
        if(tmp.size() == 1) {answer.push_back(tmp[0].first);continue;}
        sort(tmp.begin(),tmp.end(),[](const pair<int,int> &v1, const pair<int,int> &v2){
            return v1.second > v2.second;});
        answer.push_back(tmp[0].first); answer.push_back(tmp[1].first);
    }
    return answer;
}
