#include <bits/stdc++.h>
using namespace std;
int arr1[1000001],arr2[1000001];
int solution(vector<int> a) {
    int answer = a.size();
    arr1[0] = a[0]; arr2[a.size()-1]=a[a.size()-1];
	for (int i=1 ; i<=a.size()-1 ; i++) {
		if (arr1[i-1]>a[i]) arr1[i]=a[i];
		else arr1[i] = arr1[i-1];}
	for (int i=a.size()-2 ; i>=0 ; i--) {
		if (arr2[i+1] > a[i]) arr2[i]=a[i];
		else arr2[i] = arr2[i+1];}

    if(a.size()<3) return answer;
    else{
        for(int i=1 ; i<=a.size()-2 ; i++) 
            if(a[i]>arr1[i] && a[i]>arr2[i]) answer--;
    } return answer;
}
