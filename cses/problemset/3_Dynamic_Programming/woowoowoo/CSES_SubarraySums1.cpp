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
	int n,m;
	cin>>n>>m;
	queue<int>q;
	int x=0;
	int t;
	int ans=0;
	FOR(i,0,n){
		cin>>t;
		q.push(t);
		x+=t;
		if(x==m){
			ans++;
			x-=q.front();
			q.pop();
			// continue;
		}
		while(x>=m){
			x-=q.front();
			q.pop();
			if(x==m) ans++;
		}
		// cout<<ans<<' '<<t<<' '<<q.front()<<endl;
	}
	cout<<ans;
}