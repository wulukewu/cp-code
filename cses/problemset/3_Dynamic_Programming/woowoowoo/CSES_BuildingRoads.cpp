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
	vector<int>ans;
	vector<bool>v(n+1,false);
	queue<int>q;
	FOR(i,1,n+1){
		if(v[i])continue;
		ans.push_back(i);
		q.push(i);
		v[i]=true;
		while(!q.empty()){
			for(int j:arr[q.front()]){
				if(v[j]) continue;
				v[j]=true;
				q.push(j);
			}
			q.pop();
		}
	}
	cout<<ans.size()-1<<endl;
	FOR(i,1,ans.size()) cout<<ans[i-1]<<' '<<ans[i]<<endl;
	return 0;
}
