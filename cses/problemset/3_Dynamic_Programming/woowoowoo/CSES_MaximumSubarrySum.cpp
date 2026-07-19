#include <bits/stdc++.h>
#define int long long
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define F first
#define S second
using namespace std;
template<typename T>
void print(T a){
	for(auto u:a){
		cout<<u<<' ';
	}
	cout<<endl;
}
signed main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin>>n;
	vector<int>arr(n,0);
	FOR(i,0,n) cin>>arr[i];
	FOR(i,0,n-1) arr[i+1]+=arr[i];
	// print(arr);
	vector<int>sum;
	int m=arr[0];
	sum.push_back(arr[0]);
	FOR(i,1,n){
		int x=arr[i]-m;
		if(m>0) x+=m;
		sum.push_back(x);
		m=min(m,arr[i]);
	}
	sort(sum.begin(),sum.end());
	// print(sum);
	cout<<sum[n-1];

}