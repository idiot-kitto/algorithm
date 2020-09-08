#include <bits/stdc++.h>
using namespace std;
vector<int> ans;
int minimality(int bit)
{
    for(int i=0 ; i<ans.size() ; i++)
        if((ans[i] & bit) == ans[i]) return 0;
    return 1;
}

int solution(vector<vector<string>> relation) {
    int row=relation.size(), col=relation[0].size();
    for(int i=1 ; i<(1<<col) ; i++){
        map<string,int> m;
        for(int j=0 ; j<row ; j++){
            string s;
            for(int k=0 ; k<col ; k++){
                if(i & (1<<k)) s+=relation[j][k];
            }
            m[s] = 1;
        }
        if(m.size()==row && minimality(i) == 1) ans.push_back(i);
    }
    return ans.size();
}
