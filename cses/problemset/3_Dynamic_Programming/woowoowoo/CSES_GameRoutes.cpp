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
	vector<int>cnt(n+1,0);
	FOR(i,0,m){
		cin>>a>>b;
		arr[a].pb(b);
		cnt[b]++;
	}
	queue<int>q;
	vector<int>vi(n+1,0);
	FOR(i,2,n+1){
		if(!cnt[i]){
			// cout<<i<<' ';
			q.push(i);
		}
	}
	while(!q.empty()){
		int x=q.front();
		q.pop();
		for(auto& i:arr[x]){
			if(vi[i] || i==1) continue;
			cnt[i]--;
			if(cnt[i]!=0) continue;
			q.push(i);
			vi[i]=1;
		}
	}
	// for(auto& i:arr)print(i);
	vector<int>v(n+1,0);
	v[1]=1;
	q.push(1);
	// print(cnt);
	while(!q.empty()){
		int x=q.front();
		q.pop();
		for(auto& i:arr[x]){
			if(vi[i]) continue;
			// cout<<i<<' ';
			v[i]+=v[x];
			v[i]%=M;
			if(cnt[i]>1) {
				cnt[i]--;
				continue;
			}
			q.push(i);
			vi[i]=1;
		}
		// cout<<x<<endl;
		// print(v);
	}
	// print(v);
	cout<<v[n];
}

signed main(){
	Fio;
	int T=1;
	// cin>>T;
	while(T--) {
		solve();
	}
}