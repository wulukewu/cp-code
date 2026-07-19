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
int M=1e9+7;

void solve(){
	int n=8;
	vector<vector<bool>>v(n,vector<bool>(n,false));
	string s;
	FOR(i,0,n){
		cin>>s;
		FOR(j,0,n) if(s[j]=='*') v[i][j]=true;
		// print(v[i]);
	}
	int ans=0;

	auto dfs=[&](auto&& self,int a,int b,int c,int t)->void{
		if(t<1) {
			ans++;
			return;
		}

		FOR(i,0,n){
			if(((a|b|c)>>i)&1 || v[n-t][i]) continue;
			a^=(1<<i);
			b^=(1<<i);
			c^=(1<<i);
			self(self,a<<1,b,c>>1,t-1);
			a^=(1<<i);
			b^=(1<<i);
			c^=(1<<i);
		}

	};

	dfs(dfs,0,0,0,n);

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