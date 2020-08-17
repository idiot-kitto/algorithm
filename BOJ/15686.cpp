#include <bits/stdc++.h>
using namespace std;

int n, m, arr[51][51], ans = INT_MAX;
vector<pair<int,int>> chicken;
vector<int> valid_chicken;
vector<pair<int,int>> house;

int main()
{ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for(int i=0 ; i<n ; i++)
        for(int j=0 ; j<n ; j++){
            cin >> arr[i][j];
            if(arr[i][j] == 2) chicken.push_back(make_pair(i,j));
            else if(arr[i][j] == 1) house.push_back(make_pair(i,j));
        }
    for(int i=0 ; i<m ; i++) valid_chicken.push_back(1);
    for(int i=0 ; i<chicken.size()-m ; i++) valid_chicken.push_back(0);
    sort(valid_chicken.begin(),valid_chicken.end());
    
    do{
        int total_distance = 0;

        for(int i=0 ; i<house.size() ; i++){
            int temp = INT_MAX;
            int x1 = house[i].first, y1 = house[i].second;
            for(int j=0 ; j<chicken.size() ; j++){
                if(valid_chicken[j] == 1){
                    int x2 = chicken[j].first, y2 = chicken[j].second;
                    temp = min(temp, abs(x1-x2) + abs(y1-y2));
                }
            }
            total_distance += temp;
        }
        ans = min(ans, total_distance);
    }while(next_permutation(valid_chicken.begin(),valid_chicken.end()));

    cout << ans;

    return 0;
}
/*
조합을 이용해 전체 치킨집 중 M개를 선택하고, 
집 하나마다 폐업하지 않은 치킨집까지의 거리중 최소값을 더해나가면 된다.
*/
