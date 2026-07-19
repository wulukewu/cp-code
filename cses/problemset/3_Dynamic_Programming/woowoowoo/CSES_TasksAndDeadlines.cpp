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
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
	FOR(i,0,n){
		int a,b;
		cin>>a>>b;
		pq.push({a,b});
	}
	int ans=0;
	int x=0;
	while(!pq.empty()){
		pair<int,int>t=pq.top();
		pq.pop();
		x+=t.F;
		ans+=(t.S-x);
	}
	cout<<ans;
}