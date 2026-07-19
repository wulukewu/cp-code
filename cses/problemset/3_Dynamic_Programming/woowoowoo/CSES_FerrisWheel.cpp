#include <bits/stdc++.h>
#define int long long
#define FOR(i,a,b) for(int i=a;i<b;i++)
using namespace std;
template<typename T>
void print(T a){
	for(auto u:a){
		cout<<u<<' ';
	}
	cout<<endl;
}
signed main(){
	int n,m;
	cin>>n>>m;
	vector<int>arr(n,0);
	FOR(i,0,n) cin>>arr[i];
	sort(arr.begin(),arr.end());
	int idx=0;
	int x=0;
	FOR(i,0,n){
		if(i+idx>=n) break;
		if(n-i-1==idx) x++;
		else if(arr[n-i-1]+arr[idx]<=m){
			x++;
			idx++;
		}
		else {
			x++;
		}
	}
	cout<<x;


}