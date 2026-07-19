#include <bits/stdc++.h>
// #define int long long
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
	int n,m;
	cin>>n>>m;
	vector<int>arr(n);
	FOR(i,0,n) cin>>arr[i];
	vector<int>dp(m+1,0);
	dp[0]=1;
	FOR(i,0,n){
		FOR(j,arr[i],m+1){
			dp[j]+=dp[j-arr[i]];
			if(dp[j]>1e9)dp[j]%=M;
		}
	}
	cout<<dp[m];
}