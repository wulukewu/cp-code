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
	vector<pair<int,int>>arr;
	FOR(i,0,n){
		int a,b;
		cin>>a>>b;
		arr.push_back({a,b});
	}
	sort(arr.begin(),arr.end());
	int x=1;
	int l=arr[0].S;
	// FOR(i,0,n) cout<<arr[i].F<<' '<<arr[i].S<<endl;
	FOR(i,1,n){
		if(arr[i].F<l){
			l=min(l,arr[i].S);
		}
		else if(arr[i].F==arr[i-1].S){
			l=arr[i].S;
			x++;
		}
		else{
			x++;
			l=arr[i].S;
		}
		// c2out<<l<<endl;
	}
	cout<<x;
}