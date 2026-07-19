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
	vector<pair<pair<int,int>,int>>v(n);
	FOR(i,0,n) cin>>v[i].F.F>>v[i].F.S;
	FOR(i,0,n) v[i].S=i;
	sort(v.begin(),v.end());
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
	vector<int>r(n);
	FOR(i,0,n){
		int a=v[i].F.F,b=v[i].F.S,c=v[i].S;
		if(i==0 or pq.top().F>=a){
			pq.push({b,pq.size()+1});
			r[c]=pq.size();
			// cout<<pq.size()<<' ';
		}
		else{
			int x=pq.top().S;
			// cout<<x<<' ';
			pq.pop();
			pq.push({b,x});
			r[c]=x;
		}
	}
	cout<<pq.size()<<endl;
	print(r);

}