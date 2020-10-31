#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    int k = citations.size();
    while(k){
        int cnt = 0;
        for(int i=0 ; i<citations.size() ; i++)
            if(citations[i] >= k) cnt++;
        if(cnt >= k){answer = k; break;}
        k--;
    }
    return answer;
}
