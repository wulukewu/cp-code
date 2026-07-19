#include <bits/stdc++.h>
#define int long long
#define FOR(i,a,b) for(int i=a;i<b;i++)
using namespace std;
template<typename T>
void print(T a){
	for(auto u:a){
		cout<<u<<' ';
	}
	cout<<endl;
}
signed main(){
	int n;
	cin>>n;
	set<int>s;
	FOR(i,0,n) {
		int a;
		cin>>a;
		s.insert(a);
	}
	cout<<s.size();
}