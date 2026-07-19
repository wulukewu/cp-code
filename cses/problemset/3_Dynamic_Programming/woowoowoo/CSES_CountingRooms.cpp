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
	int n,m;
	cin>>n>>m;
	vector<vector<int>>arr(n,vector<int>(m,0));
	FOR(i,0,n){
		string s;
		cin>>s;
		FOR(j,0,m) if(s[j]=='#') arr[i][j]=1;
	}
	int ans=0;
	FOR(i,0,n){
		FOR(j,0,m){
			if(arr[i][j]>0) continue;
			queue<pair<int,int>>q;
			q.push({i,j});
			arr[i][j]=1;
			while(!q.empty()){
				int x=q.front().F,y=q.front().S;
				q.pop();
				FOR(o,-1,2){
					FOR(p,-1,2){
						if(o*o+p*p!=1) continue;
						if(x+o>=n or y+p>=m or x+o<0 or y+p<0) continue;
						if(arr[x+o][y+p]>0) continue;
						q.push({x+o,y+p});
						arr[x+o][y+p]=1;
					}
				}
			}
			ans++;
		}
	}
	cout<<ans;

}