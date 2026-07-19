#include <bits/stdc++.h>
#define int long long
#define FOR(i,a,b) for(int i=a;i<b;i++)
using namespace std;
template<typename T>
void print(T a){
	for(auto u:a){
		cout<<u<<' ';
	}
	cout<<endl;
}
signed main(){
	int n,m,k;
	cin>>n>>m>>k;
	vector<int>p(n,0);
	FOR(i,0,n) cin>>p[i];
	vector<int>a(m,0);
	FOR(i,0,m) cin>>a[i];
	sort(p.begin(),p.end());
	sort(a.begin(),a.end());
	int l=0,r=0;
	int c=0;
	while(l<n and r<m){
		// cout<<p[l]<<' '<<a[r]<<endl;
		if(a[r]-k>p[l]) l++;
		else if(a[r]+k<p[l]) r++;
		else{
			r++;
			l++;
			c++;
		}
	}
	// cout<<l<<' '<<r<<endl;
	cout<<c;
}