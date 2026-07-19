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
	int n,m,k,a,b,c;
	cin>>n>>m>>k;
	vector<vector<pair<int,int>>>arr(n+1);
	FOR(i,0,m){
		cin>>a>>b>>c;
		arr[a].pb({b,c});
	}
	// for(auto& i:arr){
	// 	for(auto& j:i){
	// 		cout<<j.F<<' '<<j.S<<endl;
	// 	}
	// }

	vector<int>v(n+1,0);
	PQG<pair<int,int>>q;
	q.push({0,1});
	pair<int,int>t;
	while(!q.empty()){
		t=q.top();
		q.pop();
		if(v[t.S]>=k) continue;
		v[t.S]+=1;
		if(t.S==n){
			cout<<t.F<<' ';
		}
		// cout<<t.F<<' '<<t.S<<endl;
		for(auto& i:arr[t.S]){
			// cout<<i.F<<'\n';
			// if(v[i.F]>=k) continue;
			q.push({i.S+t.F,i.F});
			// if(i.F==n){
			// 	cout<<i.S+t.F<<' ';
			// }
		}
		// print(v);
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