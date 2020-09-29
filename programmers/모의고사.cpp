#include <bits/stdc++.h>
using namespace std;
int ans1, ans2, ans3;
int a1[10] = {1,2,3,4,5};
int a2[10] = {2,1,2,3,2,4,2,5};
int a3[10] = {3,3,1,1,2,2,4,4,5,5};
vector<int> solution(vector<int> answers) {
    vector<int> answer;
    for(int i=0 ; i<answers.size() ; i++){
        if(answers[i] == a1[i%5]) ans1++;
        if(answers[i] == a2[i%8]) ans2++;
        if(answers[i] == a3[i%10]) ans3++;
    }
    if(max(ans1,max(ans2,ans3)) == ans1){
        answer.push_back(1);
        if(ans1 == ans2) answer.push_back(2);
        if(ans1 == ans3) answer.push_back(3);
    }
    else if(max(ans1,max(ans2,ans3)) == ans2){
        answer.push_back(2);
        if(ans2 == ans1) answer.push_back(1);
        if(ans2 == ans3) answer.push_back(3);
    }
    else if(max(ans1,max(ans2,ans3)) == ans3){
        answer.push_back(3);
        if(ans3 == ans2) answer.push_back(2);
        if(ans3 == ans1) answer.push_back(1);
    }
    sort(answer.begin(),answer.end());
    return answer;
}
