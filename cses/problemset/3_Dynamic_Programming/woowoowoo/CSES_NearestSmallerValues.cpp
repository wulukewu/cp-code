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
	vector<int>arr(n);
	FOR(i,0,n) cin>>arr[i];
	stack<pair<int,int>>s;
	vector<int>ans(n,0);
	
	FOR(i,0,n){
		if(s.empty()){
			s.push({arr[i],i+1});
			continue;
		}
		if(s.top().F<arr[i]){
			ans[i]=s.top().S;
			s.push({arr[i],i+1});
			continue;
		}
		while(s.top().F>=arr[i]){
			s.pop();
			if(s.empty()) break;
		}
		if(!s.empty())ans[i]=s.top().S;
		s.push({arr[i],i+1});
	}
	print(ans);
}