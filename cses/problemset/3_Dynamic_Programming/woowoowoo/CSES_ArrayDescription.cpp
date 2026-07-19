#include <bits/stdc++.h>
#define int long long
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define F first
#define S second
#define Fio ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr)
using namespace std;
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
signed main(){
	Fio;
	int n,m,a;
	cin>>n>>m;
	vector<vector<int>>dp(n,vector<int>(m+1,0));
	int ans=0;
	FOR(i,0,n){
		cin>>a;
		if(a){
			if(i-1>=0){
				if(a+1<=m) dp[i][a]+=dp[i-1][a+1];
				dp[i][a]+=dp[i-1][a];
				if(a-1>=1) dp[i][a]+=dp[i-1][a-1];
			}
			else dp[0][a]=1;
			dp[i][a]%=M;
		}
		else{
			if(i){
				FOR(j,1,m+1){
					if(j+1<=m) dp[i][j]+=dp[i-1][j+1];
					dp[i][j]+=dp[i-1][j];
					if(j-1>=1) dp[i][j]+=dp[i-1][j-1];
					if(dp[i][j]>1e9) dp[i][j]%=M;
				}
			}
			else{
				FOR(j,1,m+1) dp[i][j]=1;
			}
		}
	}
	FOR(i,1,m+1) ans+=dp[n-1][i];
	ans%=M;
	cout<<ans<<endl;
	// for(auto& i:dp) print(i);

}