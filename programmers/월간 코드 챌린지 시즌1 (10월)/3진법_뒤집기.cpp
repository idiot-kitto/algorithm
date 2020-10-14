#include <bits/stdc++.h>
using namespace std;

int solution(int n) {
    int answer = 0; string s;
    while(n){
        s += to_string(n%3); 
        n/=3;
    }//cout << s;
    int a = 1;
    for(int i=s.size()-1 ; i>=0 ; i--){
        answer += int(s[i]-'0') * a;
        a*=3;
    }
    return answer;
}
