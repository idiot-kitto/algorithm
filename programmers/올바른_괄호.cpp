#include <bits/stdc++.h>
using namespace std;
stack<char> stk;
bool solution(string s)
{
    bool answer = true;

    for(int i=0 ; i<s.size() ; i++){
        if(stk.empty() && s[i] == ')'){
            answer = false;
            return answer;
        }
        else if(s[i] == '(')
            stk.push(s[i]);
        else if(!stk.empty() && stk.top() == '(')
            stk.pop();
    }
    if(stk.empty()) answer = true;
    else answer = false;
    return answer;
}
