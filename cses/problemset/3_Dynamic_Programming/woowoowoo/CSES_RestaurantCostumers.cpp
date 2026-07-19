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
	ios_base::sync_with_stdio(false);
	int n;
	cin>>n;
	vector<pair<int,int>>arr;
	FOR(i,0,n){
		int a,b;
		cin>>a>>b;
		arr.push_back({a,0});
		arr.push_back({b,1});
	}
	sort(arr.begin(),arr.end());
	vector<int>ans;
	int x=0;
	FOR(i,0,arr.size()){
		if(arr[i].S==0) x++;
		else x--;
		ans.push_back(x);
	}
	sort(ans.begin(),ans.end());
	reverse(ans.begin(),ans.end());
	cout<<ans[0];
}