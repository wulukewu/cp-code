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
	ios_base::sync_with_stdio(false), cin.tie(0);
	int n,mi;
	cin>>n>>mi;
	multiset<int>s;
	multiset<int>::iterator it;
	FOR(i,0,n){
		int a;
		cin>>a;
		s.insert(a);
	}
	FOR(i,0,mi){
		int x;
		cin>>x;
		if(s.size()<=0){
			cout<<-1<<endl;
			continue;
		}
		it=s.upper_bound(x);
		if(*s.begin()>x or *(--it)>x){
			cout<<-1<<endl;
			continue;
		}
		// print(s);
		cout<<*(it)<<endl;
		// cout<<*s.begin()<<' '<<1<<endl;
		s.erase(it);
	}
}