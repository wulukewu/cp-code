#include <bits/stdc++.h>
#define int long long
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define F first
#define S second
#define Fio ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
using namespace std;
template<typename T>
void print(T a){
	for(auto u:a){
		cout<<u<<' ';
	}
	cout<<endl;
}
signed main(){
	Fio;
	int n,m;
	cin>>n>>m;
	vector<int>arr(n);
	FOR(i,0,n) cin>>arr[i];
	// print(arr);
	long long ans;

	auto search=[&](int x)->long long{
		ans=0;
		FOR(j,0,n) {
			ans+=(x/arr[j]);
		}
		// cout<<ans<<endl;
		return ans;
	};

	long long l=0;
	for(int ma=1e12;ma>0;ma/=2){
		// cout<<l<<' '<<ma<<' '<<endl;
		while(search(ma+l)<m) {
			l+=ma;
		}
	}
	cout<<l+1;
}