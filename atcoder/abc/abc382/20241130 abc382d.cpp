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

int n,m;
set<vector<int>>arr;
void D(int x,int y,vector<int>t){
	// print(t);
	if(x==n) {
		arr.insert(t);
		return;
	}
	int z=y;
	if(x!=0) z+=10;
	while(z+(n-x-1)*10<=m){
		t[x]=z;
		D(x+1,z,t);
		z++;
	}
}

signed main(){
	Fio;
	cin>>n>>m;
	vector<int>t(n,0);
	D(0,1,t);
	cout<<arr.size()<<endl;
	for(auto& it:arr){
		print(it);
	}
}