#include <bits/stdc++.h>
using namespace std;

bool isprime(int n){
    if(n < 2) return false;
    for(int i=2 ; i<n ; i++){
        if(n%i == 0) return false;
    }return true;
}

int solution(string numbers) {
    int answer = 0;
    vector<int> v;
    for(int i=0 ; i<numbers.size() ; i++) v.push_back(numbers[i] - '0');
    sort(v.begin(), v.end());
    set<int> ss;
    do{
        for(int i=1 ; i<=v.size() ; i++){
            int tmp = 0;
            for(int j=0 ; j<i ; j++){
                tmp = (tmp * 10) + v[j];
                ss.insert(tmp);
            }
        }
    }while(next_permutation(v.begin(),v.end()));
    for(auto iter = ss.begin() ; iter != ss.end() ; iter++)
        if(isprime(*iter)) answer++;
    return answer;
}
