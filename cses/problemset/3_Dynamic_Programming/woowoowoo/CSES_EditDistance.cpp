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
	string s,t;
	cin>>s>>t;
	int n=s.sz(),m=t.sz();
	vector<vector<int>>dp(n+1,vector<int>(m+1,INT_MAX));
	FOR(i,0,n+1){
		FOR(j,0,m+1){
			if(i==0) dp[0][j]=j;
			if(j==0) dp[i][0]=i;
			if(i+1<=n)dp[i+1][j]=min(dp[i+1][j],dp[i][j]+1);
			if(j+1<=m)dp[i][j+1]=min(dp[i][j+1],dp[i][j]+1);
			if(i+1<=n && j+1<=m)dp[i+1][j+1]=min(dp[i+1][j+1],dp[i][j]+1);
			if(s[i]==t[j] && i+1<=n && j+1<=m) dp[i+1][j+1]=min(dp[i][j],dp[i+1][j+1]);
		}
	}
	// FOR(i,0,n+1) print(dp[i]);
	cout<<dp[n][m];
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