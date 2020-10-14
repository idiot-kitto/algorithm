#include <bits/stdc++.h>
using namespace std;
int ans0, ans1;
vector<vector<int>> arr;
void solve(int x, int y, int length)
{
    int val = arr[x][y];
    if(length == 1){
        if(arr[x][y] == 1) {ans1++; return;}
        else {ans0++; return;}
    }
    bool check = true;
    for(int i=x ; i<x+length ; i++){
        for(int j=y ; j<y+length ; j++)
            if(arr[i][j] != val){
                check = false;
                break;
            }
        if(!check) break;
    }
    if(check){
        if(arr[x][y] == 1){ans1++;return;}
        else{ans0++;return;}
    }
    else{
        solve(x,y,length/2);
        solve(x+length/2,y,length/2);
        solve(x,y+length/2,length/2);
        solve(x+length/2,y+length/2,length/2);
    }
}

vector<int> solution(vector<vector<int>> array) {
    vector<int> answer;
    arr = array;
    solve(0,0,arr.size());
    
    answer.push_back(ans0); answer.push_back(ans1);
    return answer;
}
