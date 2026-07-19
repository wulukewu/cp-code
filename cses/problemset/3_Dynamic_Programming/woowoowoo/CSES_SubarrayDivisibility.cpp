#include <bits/stdc++.h>
#define int long long
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define F first
#define S second
#define Fio ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr)
using namespace std;
template<typename T>
void print(T a){
	for(auto u:a){
		cout<<u<<' ';
	}
	cout<<endl;
}
template <typename T>
void printQ(priority_queue<T> pq) {
    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
}
int M=1e9+7;
signed main(){
	Fio;
	int n;
	cin>>n;
	vector<int>arr(n);
	FOR(i,0,n) cin>>arr[i];
	FOR(i,1,n) arr[i]+=arr[i-1];
	// print(arr);
	map<int,int>mp;
	mp[0]=1;
	int ans=0;
	FOR(i,0,n){
		arr[i]%=n;
		if(mp.find(arr[i])!=mp.end()) ans+=mp[arr[i]];
		if(mp.find(arr[i]-n)!=mp.end()) ans+=mp[arr[i]-n];
		if(arr[i]<0 && mp.find(n+arr[i])!=mp.end()) ans+=mp[arr[i]+n];
		mp[arr[i]]++;
	}
	cout<<ans;
}