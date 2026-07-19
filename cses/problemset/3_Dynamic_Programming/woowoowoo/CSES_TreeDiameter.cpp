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
	auto dfs=[&](auto&& self,int x,int prv)->pair<int,int>{
		pair<int,int>res,t;
		res.F=0;
		res.S=x;
		for(auto& i:arr[x]){
			if(i==prv) continue;
			t=self(self,i,x);
			if(t.F>res.F){
				swap(t,res);
			}
		}
		return {res.F+1,res.S};
	};

	pair<int,int>x;
	x=dfs(dfs,1,-1);
	// cout<<x.F<<' '<<x.S;
	cout<<dfs(dfs,x.S,-1).F-1;
}

signed main(){
	Fio;
	int T=1;
	// cin>>T;
	while(T--) {
		solve();
	}
}