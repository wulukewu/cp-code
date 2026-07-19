// cp
#include <bits/stdc++.h>
#define int long long
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define F first
#define S second
#define pb push_back
#define ALL(v) v.begin(),v.end()
#define endl '\n'
#define sz size
#define Fio ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr)
using namespace std;
template<typename T>
void print(T a){
	for(auto u:a){
		cout<<u<<' ';
	}
	cout<<endl;
}
template<typename T>
void printp(T a){
	for(auto u:a){
		cout<<u.F<<' '<<u.S<<endl;
	}
	cout<<endl;
}

void solve(){
	int n;
	cin>>n;
	if(n==1){
		cout<<10;
		return;
	}
	vector<set<int>>arr(1<<n-1);
	FOR(i,0,1<<n-1){
		arr[i].insert( ((i*2)%(1<<n-1)) );
		arr[i].insert( ((i*2)%(1<<n-1)) + 1);
		// arr[i].erase(i);
	}
	// for(auto& i:arr) print(i);

	vector<int>ans;

	auto dfs=[&](auto&& self, int x)->void{
		while(arr[x].sz()){
			auto t=*arr[x].begin();
			arr[x].erase(t);
			self(self,t);
		}
		ans.pb(x);
	};

	dfs(dfs,0);

	reverse(ALL(ans));
	// print(ans);

	FOR(i,0,n-2) cout<<0;
	for(auto& i:ans) {
		cout<<(i%2);
	}
}

signed main(){
	Fio;
	int T=1;
	// cin>>T;
	while(T--) {
		solve();
	}
}