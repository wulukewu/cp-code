#include<bits/stdc++.h>
using namespace std;
#define pb push_back

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	int n,q,a,b;
	cin>>n>>q;
	vector<vector<int>>bl(30,vector<int>(n+1,1));

	vector<vector<int>>arr(n+1);
	for(int i=2;i<=n;i++){
		cin>>bl[0][i];
		arr[bl[0][i]].pb(i);
	}
	for(int i=0;i<=20;i++){
		for(int j=1;j<=n;j++){
			if(bl[i][j]<=0) continue;
			bl[i+1][j]=bl[i][bl[i][j]];
		}
	}

	queue<int>qu;
	qu.push(1);
	vector<int>ly(n+2,0);
	while(!qu.empty()){
		auto t=qu.front();
		qu.pop();
		for(auto& i:arr[t]){
			ly[i]=ly[t]+1;
			qu.push(i);
		}
	}

	auto up=[&](int x,int y)->int{
		for(int i=0;i<=20;i++){
			if((y>>i)&1) x=bl[i][x];
		}
		return x;
	};

	for(int i=0;i<q;i++){
		cin>>a>>b;
		
		int x,y=0;
		if(ly[a]<=ly[b]) {x=a;y=b;}
		else {x=b;y=a;}
		
		y=up(y,abs(ly[a]-ly[b]));
		
		if(x==y) {
			cout<<x<<endl;
			continue;
		}
		for(int j=20;j>=0;j--){
			if(bl[j][x]!=bl[j][y]){
				x=bl[j][x];
				y=bl[j][y];
			}
		}
		cout<<bl[0][x]<<endl;
	}
}