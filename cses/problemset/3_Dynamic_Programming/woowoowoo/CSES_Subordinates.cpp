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
	int n,a;
	cin>>n;
	vector<vector<int>>arr(n+1);
	FOR(i,0,n-1){
		cin>>a;
		arr[a-1].pb(i+1);
	}

	vector<int>res(n);

	auto dfs=[&](auto&& self,int x)->int{
		int ans=0;
		for(auto& i:arr[x]){
			ans+=self(self,i)+1;
		}
		res[x]=ans;
		return ans;
	};

	res[0]=dfs(dfs,0);
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