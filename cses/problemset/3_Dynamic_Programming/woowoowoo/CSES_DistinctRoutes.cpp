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
	int n,m,a,b;
	cin>>n>>m;
	vector<vector<int>>arr(n+1);
	vector<set<int>>crr(n+1);
	vector<vector<int>>brr(n+1,vector<int>(n+1,0));
	FOR(i,0,m){
		cin>>a>>b;
		arr[a].pb(b);
		arr[b].pb(a);
		crr[a].insert(b);
		brr[a][b]+=1;
	}

	int ans=0;
	auto bfs=[&]()->bool{
		vector<int>v(n+1,-1);
		queue<int>q;
		q.push(1);
		v[1]=-2;
		// vector<int>res={n};

		while(!q.empty()){
			auto t=q.front();
			q.pop();
			for(auto& i:arr[t]){
				if(~v[i] || !brr[t][i]) continue;
				v[i]=t;
				q.push(i);
			}
		}
		if(v[n]==-1) return false;

		for(int i=n;v[i]!=-2;i=v[i]){
			brr[v[i]][i]-=1;
			brr[i][v[i]]+=1;
		}
		return true;
	};

	
	while(bfs()){
		ans++;
	}

	vector<int>tmp;
	vector<bool>v(n+1,false);
	auto dfs=[&](auto&& self,int x)->bool{
		v[x]=true;
		tmp.pb(x);
		if(x==n) return true;
		for(auto i:crr[x]){
			if(v[i] || brr[x][i]!=0) continue;
			bool t=self(self,i);
			if(t) {
				crr[x].erase(i);
				return true;
			}
		}
		return false;
	};

	cout<<ans<<endl;
	FOR(i,0,ans){
		tmp.clear();
		v=vector<bool>(n+1,false);
		dfs(dfs,1);
		// reverse(ALL(tmp));
		cout<<tmp.sz()<<endl;
		print(tmp);
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