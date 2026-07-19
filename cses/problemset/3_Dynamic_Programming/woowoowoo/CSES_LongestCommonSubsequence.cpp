// cp
#include <bits/stdc++.h>
#define int long long
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define F first
#define S second
#define pb push_back
#define ALL(v) v.begin(),v.end()
#define endl '\n'
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
	int n,m;
	cin>>n>>m;
	vector<int>arr(n),brr(m);
	FOR(i,0,n) cin>>arr[i];
	FOR(i,0,m) cin>>brr[i];
	vector<vector<int>>dp(n+1,vector<int>(m+1,0));
	// dp[0][0]=0;
	FOR(i,0,n+1){
		FOR(j,0,m+1){
			if(i+1<=n && j+1<=m && (arr[i]==brr[j])) dp[i+1][j+1]=max(dp[i+1][j+1],dp[i][j]+1);
			if(i+1<=n) dp[i+1][j]=max(dp[i+1][j],dp[i][j]);
			if(j+1<=m) dp[i][j+1]=max(dp[i][j+1],dp[i][j]);
		}
	}
	cout<<dp[n][m]<<endl;
	int z=dp[n][m],x=n,y=m;
	vector<int>ans;
	while(z){
		if(x-1>=0 && dp[x-1][y]==z){
			x-=1;
		}
		else if(y-1>=0 && dp[x][y-1]==z){
			y-=1;
		}
		else{
			x--;
			y--;
			z=dp[x][y];
			ans.pb(arr[x]);
		}
	}
	reverse(ALL(ans));
	print(ans);
	// FOR(i,0,n+1) print(dp[i]);
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