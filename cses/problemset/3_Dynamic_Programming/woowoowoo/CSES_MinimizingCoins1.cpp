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
int MOD=1e9+7;

signed main(){
	Fio;
	int n,m;
	cin>>n>>m;
	vector<int>arr(n);
	FOR(i,0,n) cin>>arr[i];
	vector<int>dp(m+1,INT_MAX);
	dp[0]=0;
	FOR(i,0,m+1){
		FOR(j,0,n){
			if(i-arr[j]>=0){
				dp[i]=min(dp[i-arr[j]]+1,dp[i]);
			}
		}
	}
	// print(dp);
	cout<<(dp[m]==INT_MAX ? -1 : dp[m]);
}