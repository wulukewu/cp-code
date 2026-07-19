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
template<typename T> using PQ = priority_queue<T>;
template<typename T> using PQG = priority_queue<T, vector<T>, greater<T>>;
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
template <typename T>
void printQ(priority_queue<T> pq) {
    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
}

template<typename T>
class fenwick{
public:
	vector<T>bit;int size=3e5;
	fenwick(int s){size=s;bit=vector<T>(size,0);}
	int lb(int x){return x&(-x);}
	void up(int x,T y){for(int i=x;i<size;i+=lb(i))bit[i]+=y;}
	T sum(int x){T res=0;for(int i=x;i>=1;i-=lb(i))res+=bit[i];return res;}
};

template<class T>
class segment{
public:
	int n;vector<int>arr;
	segment(vector<T>&init){
		n=init.sz();arr=vector<T>(n*2,0);
		for(int i=0;i<n;i++)arr[i+n]=init[i];
		for(int i=n-1;i>0;i--){arr[i]=action(arr[i*2],arr[i*2 | 1]);}
	}
	int action(int a,int b){
		return min(a,b);    //###############
	}
	void modify(int x,int y){
		arr[x+n-1]=y;       //###############
		for(int i=(n+x-1)/2;i>=1;i/=2){
			arr[i]=action(arr[i*2],arr[i*2+1]);
		}
	}
	int query(int l,int r){
		int res=INT_MAX;		//###########
		for(l+=n-1,r+=n-1;l<=r;l/=2,r/=2){
			if(l&1) res=action(res,arr[l++]);
			if(!(r&1)) res=action(res,arr[r--]);}
		return res;
	}
};

int M=1e9+7;

void solve(){
	int n,m,a,b;
	cin>>n>>m;
	vector<int>arr(n+1);
	FOR(i,1,n+1) cin>>arr[i];

	vector<set<int>>vis(n+1);
	vector<int>vt(n+1,-1);
	vector<vector<int>>quer(n+1);
	vector<vector<int>>end(n+1);
	vector<int>v(n+1,-1);
	map<pair<int,int>,int>mp;
	map<pair<int,int>,int>ans1;
	vector<int>ans(m,-1);
	vector<pair<int,int>>ed;
	FOR(i,0,m){
		cin>>a>>b;
		quer[a].pb(b);
		end[b].pb(a);
		mp[{a,b}]=i;
		ed.pb({a,b});
	}

	set<int>s;
	int cnt=1,t=0;
	auto dfs=[&](auto&& self,int x)->void{
		v[x]=cnt++;
		vis[t].insert(x);
		vt[x]=t;
		s.insert(x);
		// print(s);
		// cout<<x<<endl<<flush;
		for(auto& i:end[x]){
			if(mp.find({i,x})==mp.end()) continue;
			if(s.find(i)!=s.end()){
				// cout<<i<<' '<<x<<' '<<v[i]<<' '<<v[x]<<' '<<mp[{i,x}]<<endl<<flush;
				ans1[{i,x}]=v[x]-v[i];
				mp.erase({i,x});
			}
		}
		if(~v[arr[x]]){
			for(auto& i:s){
				for(auto& j:quer[i]){
					if(v[arr[x]]==-1) continue;
					if(mp.find({i,j})==mp.end()) continue;
					// cout<<x<<' '<<arr[x]<<endl;
					cout<<i<<' '<<j<<' '<<vt[j]<<' '<<(vis[vt[arr[x]]].find(j)!=vis[vt[arr[x]]].end())<<endl;
					// cout<<x<<' '<<i<<endl;
					// cout<<v[x]<<' '<<v[i]<<' '<<v[j]<<' '<<v[arr[x]]<<endl;
					// print(vis[vt[arr[x]]]);
					if(vis[vt[arr[x]]].find(j)!=vis[vt[arr[x]]].end()){
						if(v[x]<v[i] || v[j]<v[arr[x]]) continue;
						ans1[{i,j}]=v[x]-v[i]+v[j]-v[arr[x]]+1;
						mp.erase({i,j});
					}
				}
			}
			return;
		}
		self(self,arr[x]);
	};

	FOR(i,1,n+1){
		if(v[i]!=-1) continue;
		t++;
		s.clear();
		dfs(dfs,i);
		// print(s);
	}

	// print(v);
	// print(vt);
	// print(ans);
	FOR(i,0,m){
		if(ans1.find({ed[i].F,ed[i].S})==ans1.end()) continue;
		if(ans1[{ed[i].F,ed[i].S}]<0) continue;
		ans[i]=ans1[{ed[i].F,ed[i].S}];
	}
	for(auto& i:ans) cout<<i<<endl;

}

signed main(){
	Fio;
	int T=1;
	// cin>>T;
	while(T--) {
		solve();
	}
}