#include <bits/stdc++.h>
// #define int long long
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
	long n,m;
	cin>>n>>m;
	map<int,int>s;
	vector<int>arr(n);
	FOR(i,0,n){
		cin>>arr[i];
		s[arr[i]]=i;
	}
	long x;
	FOR(i,0,n){
		FOR(j,i+1,n){
			x=m-arr[i]-arr[j];
			if(s.find(x)!=s.end() and s[x]!= i and s[x]!= j){
				cout<<i+1<<' '<<j+1<<' '<<s[x]+1;
				exit(0);
			}
		}
	}
	cout<<"IMPOSSIBLE";
}