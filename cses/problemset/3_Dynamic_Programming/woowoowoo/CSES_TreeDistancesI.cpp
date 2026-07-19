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
template <typename T>
void printQ(priority_queue<T> pq) {
    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
}
int M=1e9+7;

void solve(){
	int n,a,b;
	cin>>n;
	vector<vector<int>>arr(n+1);
	FOR(i,0,n-1){
		cin>>a>>b;
		arr[a].pb(b);
		arr[b].pb(a);
	}
	vector<vector<int>>v(3,vector<int>(n+1));
	auto dfs=[&](auto&& self,int x,int prv,int y,int z)->pair<int,int>{
		pair<int,int>res,t;
		res.F=0;
		res.S=x;
		for(auto& i:arr[x]){
			if(i==prv) continue;
			t=self(self,i,x,y,z+1);
			if(t.F>res.F){
				swap(t,res);
			}
		}
		v[y][x]=z;
		return {res.F+1,res.S};
	};

	pair<int,int>x;
	x=dfs(dfs,1,-1,0,0);
	// cout<<x.F<<' '<<x.S;
	x=dfs(dfs,x.S,-1,1,0);
	dfs(dfs,x.S,-1,2,0);
	// print(v[0]);
	// print(v[1]);
	// print(v[2]);
	FOR(i,1,n+1) cout<<max({v[0][i],v[1][i],v[2][i]})<<' ';
}

signed main(){
	Fio;
	int T=1;
	// cin>>T;
	while(T--) {
		solve();
	}
}