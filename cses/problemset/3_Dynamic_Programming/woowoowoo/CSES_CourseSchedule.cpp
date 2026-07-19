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
	vector<vector<int>>brr(n+1);
	FOR(i,0,m){
		cin>>a>>b;
		arr[b].pb(a);
		brr[a].pb(b);
	}
	queue<int>q;
	vector<bool>v(n+1,false);
	vector<int>r(n+1,0);
	vector<int>ans;
	FOR(i,1,n+1){
		if(arr[i].empty()) {
			v[i]=true;
			q.push(i);
			ans.pb(i);
		}
		else r[i]=arr[i].sz();
	}
	while(!q.empty()){
		for(auto& i:brr[q.front()]){
			if(v[i]) continue;
			if(r[i]) {
				r[i]--;
				if(r[i])continue;
			}
			v[i]=true;
			q.push(i);
			ans.pb(i);
		}
		q.pop();
	}

	// print(r);
	if(ans.sz()!=n){
		cout<<"IMPOSSIBLE";
	}
	else print(ans);

	// cout<<"Yes\n";
	return true;
}

signed main(){
	Fio;
	int T=1;
	// cin>>T;
	while(T--) {
		if(!solve()) cout<<"No\n";
	}
}