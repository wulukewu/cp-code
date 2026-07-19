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
		cout<<u;
	}
	cout<<endl;
}

signed main(){
	Fio;
	int n,m;
	cin>>n>>m;
	pair<int,int> a,b;
	vector<vector<char>>v(n,vector<char>(m,' '));
	
	FOR(i,0,n){
		string ss;
		cin>>ss;
		FOR(j,0,m) {
			if(ss[j]=='A') {a.F=i;a.S=j;}
			if(ss[j]=='B') {b.F=i;b.S=j;}
			if(ss[j]=='#') v[i][j]='X';
		}
	}
	char d[4]={'D','L','U','R'};
	int di[4]={1,0,-1,0};
	queue<pair<int,int>>q;
	q.push(a);
	while(!q.empty()){
		if(q.front().F==b.F and q.front().S==b.S){
			cout<<"YES\n";
			stack<char>s;
			int tx=b.F,ty=b.S;
			while(tx!=a.F||ty!=a.S){
				s.push(v[tx][ty]);
				if(v[tx][ty]=='D') tx--;
				else if(v[tx][ty]=='L') ty++;
				else if(v[tx][ty]=='U') tx++;
				else if(v[tx][ty]=='R') ty--;
			}
			cout<<s.size()<<endl;
			while(!s.empty()) {
				cout<<s.top();
				s.pop();
			}
			exit(0);
		}
		FOR(i,0,4){
			int x=q.front().F+di[i],y=q.front().S+di[(i+1)%4];
			if(x>=n or y>=m or x<0 or y<0) continue;
			if(v[x][y]!=' ') continue;
			v[x][y]=d[i];
			q.push({x,y});
		}
		q.pop();
	}
	cout<<"NO";
}