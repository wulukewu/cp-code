#include <bits/stdc++.h>
#define int long long
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define F first
#define S second
using namespace std;
template<typename T>
void print(T a){
	for(auto u:a){
		cout<<u<<' ';
	}
	cout<<endl;
}
signed main(){
	ios_base::sync_with_stdio(0), cin.tie(0),cout.tie(0);
	int n,k;
	cin>>n>>k;
	vector<int>arr(n,0);
	FOR(i,0,n) arr[i]=i+1;
	int x=-1;
	FOR(i,0,n){
		x+=k+1;
		// if(x>=n) x=i+x%n;
		// swap(arr[i],arr[x]);
		// print(arr);
	}
}
//pbds 