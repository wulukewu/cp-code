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
int M=1e9+7;
int n=1e6;
vector<vector<int>>dp(1e6+1,vector<int>(4,0));
void ans(){
	dp[1][1]=1;
	dp[1][2]=1;

	FOR(i,2,1e6+1){
		dp[i][0]=(dp[i-1][0]+dp[i-1][1])*3;
		dp[i][1]=dp[i-1][0]+dp[i-1][1]+dp[i-1][2]+dp[i-1][3];
		dp[i][2]=dp[i-1][0]+dp[i-1][1]+dp[i-1][2]+dp[i-1][3];
		dp[i][3]=dp[i-1][2]+dp[i-1][3];
		FOR(j,0,4) dp[i][j]%=M;
	}
}
bool solve(){
	int n;
	cin>>n;
	cout<<(dp[n][0]+dp[n][1]+dp[n][2]+dp[n][3])%M<<endl;
	// cout<<"Yes\n";
	return true;
}

signed main(){
	Fio;
	int T=1;
	cin>>T;
	ans();
	while(T--) {
		if(!solve()) cout<<"No\n";
	}
}