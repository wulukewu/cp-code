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
	int n;
	cin>>n;
	vector<int>arr(n);
	int mx=0;
	FOR(i,0,n) {
		cin>>arr[i];
		mx=max(mx,arr[i]);
	}
	vector<int>idx;
	FOR(i,0,n) if(mx==arr[i]) idx.pb(i);
	// print(idx);
	int x=idx.sz();
	int ans=max(idx[0]+1,n-idx[x-1]);
	FOR(i,1,x){
		ans=max(ans,idx[i]-idx[i-1]);
	}
	cout<<ans;

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