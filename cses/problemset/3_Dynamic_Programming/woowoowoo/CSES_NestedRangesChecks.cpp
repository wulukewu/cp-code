#include <bits/stdc++.h>
#define int long long
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define F first
#define S second
using namespace std;
template<typename T>
void print(T a){
	for(auto u:a){
		cout<<u<<' ';
	}
	cout<<endl;
}
signed main(){
	ios_base::sync_with_stdio(0), cin.tie(0);
	int n;
	cin>>n;
	vector<vector<int>>arr(n,vector<int>(2,0));
	FOR(i,0,n){
		cin>>arr[i][0]>>arr[i][1];
	}
	sort(arr.begin(),arr.end());
	FOR(i,0,n) print(arr[i]);
}