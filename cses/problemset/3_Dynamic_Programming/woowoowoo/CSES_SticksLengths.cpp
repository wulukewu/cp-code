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
	vector<int>arr(n,0);
	int x=0;
	FOR(i,0,n){
		cin>>arr[i];
		x+=arr[i];
	}
	sort(arr.begin(),arr.end());
	int y=0;
	vector<int>ans;
	FOR(i,0,n){
		x-=(n-i)*(arr[i]-y);
		x+=(i)*(arr[i]-y);
		y=arr[i];
		ans.push_back(x);
		// cout<<x<<' '<<i<<endl;
	}
	sort(ans.begin(),ans.end());
	cout<<ans[0];
}