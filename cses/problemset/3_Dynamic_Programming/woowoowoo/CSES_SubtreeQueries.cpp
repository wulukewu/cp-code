#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define int long long

template<typename T>
void print(T a){
	for(auto u:a){
		cout<<u<<' ';
	}
	cout<<endl;
}

const int m=5e5+5;
int lb(int x){return x&-x;}

int bit[m]={0};

void up(int x,int y){
	for(int i=x;i<m;i+=lb(i)) bit[i]+=y;
}

int sum(int x){
	int res=0;
	for(int i=x;i>=1;i-=lb(i)) res+=bit[i];
	return res;
}

signed main(){
	int n,q,a,b,c;
	cin>>n>>q;
	vector<int>val(n+1,0);
	for(int i=1;i<=n;i++) cin>>val[i];
	vector<vector<int>>arr(n+1);
	for(int i=0;i<n-1;i++){
		cin>>a>>b;
		arr[a].pb(b);
		arr[b].pb(a);
	}

	vector<int>in(n+1,0),out(n+1,0);

	int cnt=0;
	auto dfs=[&](auto&& self,int x,int p)->void{
		in[x]=++cnt;
		for(auto& i:arr[x]){
			if(i==p || i==0) continue;
			self(self,i,x);
		}
		out[x]=cnt;
	};

	dfs(dfs,1,0);
	
	for(int i=1;i<=n;i++) up(in[i],val[i]);
	for(int i=0;i<q;i++){
		cin>>a>>b;
		if(a==2){
			cout<<sum(out[b])-sum(in[b]-1)<<endl;
		}
		else{
			cin>>c;
			up(in[b],c-val[b]);
			val[b]=c;
		}
	}
}