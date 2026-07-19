#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define pb insert
using namespace std;

int main(){
	int n,k,m,a,b;
	cin>>n>>k>>m;
	n=n+k;
	vector<set<int>>arr(n*2+2);
	vector<vector<int>>brr(2*n+2,vector<int>(n*2+2,0));
	FOR(i,0,m){
		cin>>a>>b;
		b+=n-k;
		arr[a].pb(a+n+1);
		arr[b].pb(b+n+1);
		brr[a][a+n+1]=1;
		brr[b][b+n+1]=1;

		arr[a+n+1].pb(b);
		brr[a+n+1][b]=1;
		arr[b].pb(a+n+1);
		brr[b][a+n+1]=0;

		arr[0].pb(a);
		brr[0][a]+=1;
		arr[b+n+1].pb(n+1);
		brr[b+n+1][n+1]+=1;
	}

	auto bfs=[&]()->bool{
		queue<int>q;
		vector<int>v(2*n+4,-1);
		v[0]=-2;
		q.push(0);
		while(!q.empty()){
			auto t=q.front();
			q.pop();
			for(auto& i:arr[t]){
				if(~v[i] || brr[t][i]==0) continue;
				q.push(i);
				v[i]=t;
			}
		}
		// for(auto& i:v) cout<<i<<' ';
		// 	cout<<endl;
		if(v[n+1]==-1) return false;
		int x=n+1;
		while(v[x]!=-2){
			brr[v[x]][x]-=1;
			brr[x][v[x]]+=1;
			x=v[x];
		}
		return true;
	};

	int ans=0;
	while(true){
		if(bfs()==false) break;
		ans++;
	}
	cout<<ans<<endl;

	// for(auto& i:brr){
	// 	for(auto& j:i) cout<<j<<' ';
	// 	cout<<endl;
	// }

	FOR(i,n+2,n+2+n-k){
		for(auto& j:arr[i]){
			if(brr[i][j]) continue;
			cout<<i-n-1<<' '<<j-n+k<<endl;
		}
	}

	return 0;
}