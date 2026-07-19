#include <bits/stdc++.h>
#define int long long
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define F first
#define S second
#define Fio ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr)
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
	int n,m,a,b,c;
	cin>>n>>m;
	vector<vector<pair<int,int>>>arr(n+1);
	FOR(i,0,m){
		cin>>a>>b>>c;
		arr[a].push_back({b,c});
	}
	vector<int>ans(n+1,4e18);
	vector<bool>v(n+1,false);
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
	pq.push({0,1});
	ans[1]=0;
	// v[1]=true;
	pair<int,int>t;
	while(!pq.empty()){
		t=pq.top();
		// cout<<t.S<<endl;
		pq.pop();
		if(v[t.S]) continue;
		v[t.S]=true;
		for(auto i:arr[t.S]){
			if(v[i.F]) continue;
			pq.push({i.S+t.F,i.F});
			ans[i.F]=min(i.S+t.F,ans[i.F]);
		}
	}
	// print(ans);
	FOR(i,1,n+1) cout<<ans[i]<<' ';
	
}