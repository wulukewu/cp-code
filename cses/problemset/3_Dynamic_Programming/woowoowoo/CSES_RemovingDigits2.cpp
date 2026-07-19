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
	int n;
	cin>>n;
	vector<int>dp(n+1,INT_MAX);
	dp[0]=0;
	FOR(i,1,n+1){
		int x=i,j;
		while(x){
			j=x%10;
			if(i-j>=0){
				dp[i]=min(dp[i-j]+1,dp[i]);
			}
			x/=10;
		}
	}
	// print(dp);
	cout<<dp[n];
}