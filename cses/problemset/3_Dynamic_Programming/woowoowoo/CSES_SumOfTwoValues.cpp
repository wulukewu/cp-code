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
	int n,k;
	cin>>n>>k;
	multimap<int,int>mp;
	vector<int>arr(n,0);
	FOR(i,0,n){
		cin>>arr[i];
		mp.insert(pair<int,int>(arr[i],i+1));
	}
	FOR(i,0,n){
		int x=mp.find(arr[i])->second;
		// cout<<mp.count(arr[i])<<endl;
		if(mp.find(k-arr[i])!=mp.end()){
			int y=mp.find(k-arr[i])->second;
			// cout<<y<<endl;
			if(mp.count(arr[i])>1 and arr[i]==k-arr[i]){
				int z=0;
				while(z<n){
					if(arr[z]==arr[x-1]) {
						if(x==z+1){
							z++;
							continue;
						}
						cout<<x<<' '<<z+1;
						exit(0);
					}
					z++;
				}
			}
			if(x==y) continue;
			cout<<x<<' '<<y;
			exit(0);
		}
	}
	cout<<"IMPOSSIBLE";
}