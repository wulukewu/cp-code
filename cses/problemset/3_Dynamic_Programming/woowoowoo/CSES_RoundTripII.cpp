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
	int n,m,a,b;
	cin>>n>>m;
	vector<vector<int>>arr(n+1);
	FOR(i,0,m){
		cin>>a>>b;
		arr[a].pb(b);
	}

	vector<int>v(n+1,0);
	vector<int>ans;
	int st=0;

	auto cyc=[&](auto&& self, int x, int y)->bool{
		for(auto& i:arr[x]){
			if(v[i]==-1) continue;
			if(v[i]==1) {
				st=i;
				// cout<<y<<endl;
				// cout<<i<<' ';
				ans.pb(i);
				return true;
			}
			v[i]=1;
			bool t=self(self,i,y+1);
			if(t){
				if(x==st){
					// cout<<i<<' '<<x<<endl;
					ans.pb(i);
					ans.pb(x);
					reverse(ALL(ans));
					cout<<ans.sz()<<endl;
					print(ans);
					exit(0);
				}
				// cout<<i<<' ';
				ans.pb(i);
				return true;
			}

		}
		v[x]=-1;
		return false;
	};

	FOR(i,1,n+1){
		if(v[i]) continue;
		cyc(cyc,i,1);
	}
	cout<<"IMPOSSIBLE";

}

signed main(){
	// Fio;
	int T=1;
	// cin>>T;
	while(T--) {
		solve();
	}
}