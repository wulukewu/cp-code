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
	vector<vector<int>>	arr(n,vector<int>(n,0));
	FOR(i,0,n){
		string s;
		cin>>s;
		FOR(j,0,n)if(s[j]=='*') arr[i][j]=-1;
	}
	int M=1e9+7;
	if(arr[0][0]>=0)arr[0][0]=1;
	FOR(i,0,n){
		FOR(j,0,n){
			if(arr[i][j]<0) continue;
			if(i-1>=0 and arr[i-1][j]>=0) arr[i][j]+=arr[i-1][j];
			if(j-1>=0 and arr[i][j-1]>=0) arr[i][j]+=arr[i][j-1];
			arr[i][j]%=M;
		}
	}
	// FOR(i,0,n) print(arr[i]);
	if(arr[n-1][n-1]==-1) cout<<0;
	else cout<<arr[n-1][n-1];
	

}