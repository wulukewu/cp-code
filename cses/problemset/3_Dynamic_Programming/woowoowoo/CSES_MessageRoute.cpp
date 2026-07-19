#include <bits/stdc++.h>
#define int long long
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define F first
#define S second
#define Fio ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr)
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
	int n,m,a,b;
	cin>>n>>m;
	vector<vector<int>>arr(n+1);
	FOR(i,0,m){
		cin>>a>>b;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}
	vector<int>v(n+1,0);
	queue<int>q;
	q.push(1);
	v[1]=1;
	while(!q.empty()){
		for(int i:arr[q.front()]){
			if(v[i]) continue;
			v[i]=q.front();
			q.push(i);
		}
		q.pop();
	}
	if(v[n]==0){
		cout<<"IMPOSSIBLE";
		return 0;
	}
	int ans=0,x=n;
	stack<int>s;
	while(x!=1){
		ans++;
		s.push(x);
		x=v[x];
	}
	cout<<s.size()+1<<endl;
	cout<<1<<' ';
	while(!s.empty()){
		cout<<s.top()<<' ';
		s.pop();
	}
}