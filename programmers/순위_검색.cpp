#include <bits/stdc++.h>
using namespace std;
typedef pair<string,string> pss;
vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    map< pair<pss,pss> , vector<int>> mp;
    for(int i=0 ; i<info.size() ; i++){
        deque<string> dq;
        string tmp = "";
        for(int j=0 ; j<info[i].size() ; j++){
            if(info[i][j] == ' '){dq.push_back(tmp); tmp = "";}
            else if(j == (int)info[i].size() - 1){tmp += info[i][j]; dq.push_back(tmp); tmp = "";}
            else tmp += info[i][j];
        }
        int score = stoi(dq[4]);
        for(int k=0 ; k<=4 ; k++){
            vector<int> ind;
            for(int j=0 ; j<k ; j++) ind.push_back(0);
            for(int j=k ; j<4 ; j++) ind.push_back(1);
            do{
                string s0 = dq[0], s1 = dq[1], s2 = dq[2], s3 = dq[3];
                if(ind[0] == 0) s0 = "-";
                if(ind[1] == 0) s1 = "-";
                if(ind[2] == 0) s2 = "-";
                if(ind[3] == 0) s3 = "-";
                mp[ {{s0,s1},{s2,s3}} ].push_back(score);
            }while(next_permutation(ind.begin(),ind.end()));
        }
    }
    string lang[4] = {"cpp","java","python","-"};
    string job[3] = {"backend","frontend","-"};
    string career[3] = {"junior","senior","-"};
    string food[3] = {"chicken","pizza","-"};
    for(int a=0 ; a<4 ; a++)
        for(int b=0 ; b<3 ; b++)
            for(int c=0 ; c<3 ; c++)
                for(int d=0 ; d<3 ; d++){
                    auto &v = mp[ { { lang[a] , job[b] } , { career[c] , food[d] } } ];
                    sort(v.begin(), v.end());
                }
    
    for(int i=0 ; i<query.size() ; i++){
        deque<string> dq;
        string tmp = "";
        for(int j=0 ; j<query[i].size() ; j++){
            if(query[i][j] == ' ' && tmp == "and"){tmp = ""; continue;}
            else if(query[i][j] == ' ' && tmp != "and"){dq.push_back(tmp); tmp = "";}
            else if(j == (int)query[i].size() - 1){tmp += query[i][j]; dq.push_back(tmp); tmp = "";}
            else tmp += query[i][j];
        }
        int ans = 0, score = stoi(dq[4]);
        auto v = mp[{{dq[0],dq[1]},{dq[2],dq[3]}}];
        auto pos = upper_bound(v.begin(), v.end(), score - 1);
        answer.push_back(v.end() - pos);
    }
    return answer;
}
