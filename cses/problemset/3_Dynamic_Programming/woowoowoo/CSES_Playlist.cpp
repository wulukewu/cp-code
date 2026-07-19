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
	map<int,int>mp;
	vector<int>brr;
	int x=0;
	FOR(i,0,n) cin>>arr[i];
	FOR(i,0,n){
		int a=arr[i];
		if(mp.find(a)->second!=mp.end()->second){
			int y=mp.find(a)->second+1;
			FOR(j,x,y) mp.erase(arr[j]);
			// mp.erase(mp.begin(),mp.find(a));
			x=y;
		}
		mp.insert(pair<int,int>(a,i));
		brr.push_back(mp.size());
		// cout<<x<<' '<<arr[i]<<' '<<i<<' '<<mp.size()<<endl;
		
	}
	// print(brr);
	sort(brr.begin(),brr.end());
	cout<<brr[n-1];
		

}