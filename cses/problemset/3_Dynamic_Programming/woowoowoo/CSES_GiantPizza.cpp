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

int n,m;
const int mxm=2e5+5;
int scc[mxm];
int v[mxm]={0};
int vv[mxm]={0};
void solve(){
	cin>>n>>m;
	char a,b;
	int c,d;
	vector<vector<int>>mp1(mxm),mp2(mxm);
	vector<pair<int,int>>ed;
	FOR(i,0,n){
		cin>>a>>c>>b>>d;
		int x=2*c,y=2*d;
		if(a=='-') x^=1;
		if(b=='-') y^=1;
		int nx=x^1,ny=y^1;
		mp1[nx].pb(y);
		mp1[ny].pb(x);
		ed.pb({nx,y});
		ed.pb({ny,x});
		mp2[x].pb(ny);
		mp2[y].pb(nx);
	}
	// for(auto& i:mp1) print(i);
	vector<int>ord;

	auto dfs=[&](auto&& self,int x)->void{
		v[x]=1;
		for(auto& i:mp1[x]) if(v[i]==0) self(self,i);
		ord.pb(x);
	};

	FOR(i,2,2*m+1) if(v[i]==0) dfs(dfs,i);

	reverse(ALL(ord));
	// print(ord);

	auto dfs2=[&](auto&& self,int x,int y)->void{
		scc[x]=y;
		for(auto& i:mp2[x]){
			if(scc[i]==0) self(self,i,y);
		}
	};

	int com=0;
	for(auto& i:ord) if(scc[i]==0) dfs2(dfs2,i,++com);
	
	string ans;
	FOR(i,1,m+1){
		// cout<<scc[i*2]<<' '<<scc[i*2+1]<<' ';
		if(scc[i*2]==scc[i*2+1]){
			cout<<"IMPOSSIBLE";
			return;
		}
		ans+= (scc[2*i]>=scc[2*i+1] ? '+':'-');
		ans+=' ';
	}
	cout<<ans;

}

signed main(){
	Fio;
	int T=1;
	// cin>>T;
	while(T--) {
		solve();
	}
}