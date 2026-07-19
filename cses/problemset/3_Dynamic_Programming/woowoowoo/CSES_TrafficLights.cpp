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
	int n,m;
	cin>>n>>m;
	set<int>s;
	set<int>::iterator lit;
	set<int>::iterator uit;
	multiset<int>arr;
	s.insert(0);
	s.insert(n);
	arr.insert(n);
	FOR(i,0,m){
		int x;
		cin>>x;
		lit=s.lower_bound(x);
		uit=s.upper_bound(x);
		arr.erase(arr.find(*uit-(*(--lit))));
		arr.insert(x-(*(lit)));
		arr.insert((*(uit))-x);
		s.insert(x);
		// print(s);
		// print(arr);
		// cout<<*(lit)<<' '<<*uit<<'\n';
		cout<<*(--arr.end())<<' ';
	}
}