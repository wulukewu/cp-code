#include <bits/stdc++.h>
#define int long long
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define F first
#define S second
#define Fio ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
using namespace std;
template<typename T>
void print(T a){
	for(auto u:a){
		cout<<u<<' ';
	}
	cout<<endl;
}
signed main(){
	Fio;
	int n;
	cin>>n;
	vector<int>dp(n+1,n+1);
	dp[0]=0;
	set<int>::iterator it;
	FOR(i,1,n+1){
		int x=i;
		set<int>s;
		while(x>0){
			s.insert(x%10);
			x/=10;
		}
		for(it=s.begin();it!=s.end();it++){
			if(i-*it<0) continue;
			if(*it==0) continue;
			dp[i]=min(dp[i],dp[i-*it]+1);
		}
	}
	// print(dp);
	cout<<dp[n];
}