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
	int n,m,a,b,c;
	cin>>n>>m;
	vector<vector<pair<int,int>>>arr(n+1);
	vector<int>cnt(n+1,0);
	FOR(i,0,m){
		cin>>a>>b>>c;
		arr[a].pb({b,c});
		cnt[b]++;
	}
	vector<int>val(n+1,0);
	val[1]=1;
	vector<int>v(n+1,0);
	// v[1]=1;
	PQG<pair<int,pair<int,int>>>pq;
	pq.push({1,{1,0}});
	pair<int,pair<int,int>>t;
	vector<int>mi(n+1,INT_MAX);
	vector<int>mx(n+1,0);
	mi[1]=1;
	mx[1]=1;
	while(!pq.empty()){
		t=pq.top();
		pq.pop();
		// if(v[t.S]) continue;
		// v[t.S]=true;

		if(v[t.S.F]) {
			if(v[t.S.F]==t.F){
				val[t.S.F]+=val[t.S.S];
				val[t.S.F]%=M;
				mi[t.S.F]=min(mi[t.S.F],mi[t.S.S]+1);
				mx[t.S.F]=max(mx[t.S.F],mx[t.S.S]+1);
			}
			continue;
		}
		val[t.S.F]+=val[t.S.S];
		val[t.S.F]%=M;
		mi[t.S.F]=min(mi[t.S.F],mi[t.S.S]+1);
		mx[t.S.F]=max(mx[t.S.F],mx[t.S.S]+1);
		v[t.S.F]=t.F;
		for(auto& i:arr[t.S.F]){	
			pq.push({i.S+t.F,{i.F,t.S.F}});
		}
	}
	
	// print(v);
	// print(val);
	// print(mi);
	// print(mx);
	cout<<v[n]-1<<' '<<val[n]<<' '<<mi[n]-1<<' '<<mx[n]-1;;

}

signed main(){
	Fio;
	int T=1;
	// cin>>T;
	while(T--) {
		solve();
	}
}