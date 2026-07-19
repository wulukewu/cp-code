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
	ios_base::sync_with_stdio(0), cin.tie(0);
	int n;
	cin>>n;
	int x=-1;
	vector<int>arr(n,0);
	FOR(i,0,n){
		int y=x;
		int z=0;
		while(z<2){
			y++;
			y%=(n);
			if(arr[y]==0) z++;
			// cout<<y+1<<' '<<111111<<endl;
			x=y;
		}
		arr[x]=1;
		cout<<x+1<<' ';
	}
	// cout<<x+1;
	// print(arr);
}