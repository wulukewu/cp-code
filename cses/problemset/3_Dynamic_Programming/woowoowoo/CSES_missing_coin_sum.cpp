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
	int n;
	cin>>n;
	vector<int>arr(n,0);
	FOR(i,0,n) cin>>arr[i];
	sort(arr.begin(),arr.end());
	int x=0;
	bool t=true;
	FOR(i,0,n){
		if(arr[i]>x+1){
			cout<<x+1;
			t=false;
			exit(0);
		}
		x+=arr[i];
	}
	cout<<x+1;

}