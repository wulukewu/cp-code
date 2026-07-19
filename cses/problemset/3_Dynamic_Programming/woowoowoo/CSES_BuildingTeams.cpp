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
	vector<int>v(n+1,-1);
	queue<int>q;
	FOR(i,1,n){
		if(v[i]!=-1) continue;
		q.push(i);
		v[i]=0;
		while(!q.empty()){
			for(auto j:arr[q.front()]){
				if(v[j]!=-1){
					if(v[j]!=(v[q.front()]+1)%2){
						cout<<"IMPOSSIBLE";
						return 0;
					}
					continue;
				}
				v[j]=(v[q.front()]+1)%2;
				q.push(j);
			}
			q.pop();
		}
	}
	FOR(i,1,n+1) cout<<v[i]+1<<' ';
}