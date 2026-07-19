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
	int n;
	cin>>n;
	multiset<int>ms;
	multiset<int>::iterator it;
	FOR(i,0,n){
		int a;
		cin>>a;
		if(i==0) {
			ms.insert(a);
			continue;
		}
		it=ms.upper_bound(a);
		if(a<*ms.begin()){
			ms.erase(ms.begin());
			ms.insert(a);
		}
		else if(it!=ms.end() and *(it)>a){
			ms.erase(it);
			ms.insert(a);
		}
		else ms.insert(a);

		// cout<<*(it)<<endl;
		// print(ms);
		// cout<<endl;
	}
	cout<<ms.size();
}