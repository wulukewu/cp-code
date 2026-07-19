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

bool solve(){
	int n,m,a,b;

	cin>>n>>m;
	vector<vector<int>>arr(n+1);
	FOR(i,0,m){
		cin>>a>>b;
		arr[a].pb(b);
		arr[b].pb(a);
	}
	queue<int>q;
	vector<int>v(n+1,0);
	vector<int>p(n+1,0);
	bool t=false;
	
	auto dfs=[&](auto&& self,int x)->void{
		for(auto& i:arr[x]){
			if(v[i]) {
				if(v[x]-v[i]>=2){
					int y=x;
					cout<<v[x]-v[i]+2<<endl<<i<<' '<<y<<' ';
					while(y!=i){
						y=p[y];
						cout<<y<<' ';
					}
					// print(v);
					exit(0);
				}
				continue;
			}
			v[i]=v[x]+1;
			p[i]=x;
			self(self,i);
			v[i]=INT_MAX;
		}
	};

	FOR(i,1,n+1){
		if(v[i]) continue;
		v[i]=1;
		dfs(dfs,i);
		if(t) return true;
		// print(v);
	}
	cout<<"IMPOSSIBLE";

	// cout<<"Yes\n";
	return true;
}

signed main(){
	// Fio;
	int T=1;
	// cin>>T;
	while(T--) {
		if(!solve()) cout<<"No\n";
	}
}