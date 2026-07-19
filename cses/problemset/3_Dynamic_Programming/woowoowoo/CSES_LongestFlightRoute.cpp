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
	vector<vector<int>>brr(n+1);
	vector<int>cnt(n+1,0);
	FOR(i,0,m){
		cin>>a>>b;
		arr[a].pb(b);
		cnt[b]++;
		brr[b].pb(a);
	}

	vector<int>v(n+1,0);
	vector<int>val(n+1,0);

	queue<int>q;

	FOR(i,2,n+1){
		if(!cnt[i]) q.push(i);
	}

	while(!q.empty()){
		int t=q.front();
		q.pop();
		for(auto& i:arr[t]){
			if(i==1 || v[i]) continue;
			cnt[i]--;
			if(cnt[i]) continue;
			v[i]=true;
			q.push(i);
		}
	}

	q.push(1);
	val[1]=1;

	while(!q.empty()){
		int t=q.front();
		q.pop();
		if(v[t]) continue;
		v[t]=t;
		for(auto& i:arr[t]){
			if(v[i]) continue;
			cnt[i]--;
			if(cnt[i]) continue;
			val[i]=max(val[i],val[t]+1);
			q.push(i);
		}
	}

	// print(val);
	if(!val[n]){
		cout<<"IMPOSSIBLE";
		return;
	}
	cout<<val[n]<<endl;
	int ans=n;
	vector<int>res(1,n);
	while(ans!=1){
		for(auto& i:brr[ans]){
			if(val[i]==val[ans]-1){
				res.pb(i);
				ans=i;
				break;
			}
		}
	}
	reverse(ALL(res));
	print(res);
}

signed main(){
	Fio;
	int T=1;
	// cin>>T;
	while(T--) {
		solve();
	}
}