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
	int N;
	cin>>N;
	int n=1e6+5;
	int M=1e9+7;
	vector<vector<int>>arr(n+1,vector<int>(6,0));
	FOR(i,0,6) arr[i][i]=1;
	FOR(i,1,n+1){
		FOR(j,0,6) arr[i][0]+=arr[i-1][j];
		FOR(j,0,6) if(i-2>=0) arr[i][1]+=arr[i-2][j];
		FOR(j,0,6) if(i-3>=0) arr[i][2]+=arr[i-3][j];
		FOR(j,0,6) if(i-4>=0) arr[i][3]+=arr[i-4][j];
		FOR(j,0,6) if(i-5>=0) arr[i][4]+=arr[i-5][j];
		FOR(j,0,6) if(i-6>=0) arr[i][5]+=arr[i-6][j];
		FOR(j,0,6) arr[i][j]%=M;
	}
	int ans=0;
	FOR(i,0,6) ans+=arr[N-1][i];
	cout<<ans%M;
	// FOR(i,0,n+1) print(arr[i]);
}