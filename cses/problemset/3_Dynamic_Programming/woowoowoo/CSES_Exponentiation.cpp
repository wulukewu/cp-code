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

int Mod=1000000007;
int F(int x,int y){
	if(y==1) return x;
	if(y%2==0) return F(x*x%Mod,y/2);
	else return F(x*x%Mod,y/2)%Mod*x%Mod;
}

signed main(){
	Fio;
	int n;
	cin>>n;
	while(n--){
		int a,b;
		cin>>a>>b;
		if(b==0) cout<<1<<endl;
		else if(a==0) cout<<0<<endl;
		else cout<<F(a,b)<<endl;
	}
}