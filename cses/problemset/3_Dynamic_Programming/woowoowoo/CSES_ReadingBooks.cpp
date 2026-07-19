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
	int n;
	cin>>n;
	vector<int>arr(n);
	int s=0;
	FOR(i,0,n){
		cin>>arr[i];
		s+=arr[i];
	}
	sort(arr.begin(),arr.end());
	if(arr[n-1]<<1>=s) cout<<(arr[n-1]<<1);
	else cout<<s;

}