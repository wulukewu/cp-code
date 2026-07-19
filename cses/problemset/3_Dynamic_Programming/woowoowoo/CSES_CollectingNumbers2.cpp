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
	int n,m,a,b;
	cin>>n>>m;
	vector<int>arr(n);
	FOR(i,0,n) cin>>arr[i];
	vector<int>brr(n);
	FOR(i,0,n) brr[arr[i]-1]=i;
	int ans=1;
	FOR(i,1,n) if(brr[i-1]>brr[i]) ans++;
	// cout<<ans;
	// print(brr);
	FOR(i,0,m){
		cin>>a>>b;
		--a,--b;
		// cout<<a<<b<<' '<<arr[a]<<arr[b]<<' '<<brr[arr[b]-1]<<brr[arr[b]-1]<<endl;
		if(arr[a]>1 && brr[arr[a]-2]>a) ans--;
		if(arr[b]>1 && brr[arr[b]-2]>b) ans--;
		if(arr[a]<n && brr[arr[a]]<a && arr[b]!=arr[a]+1) ans--;
		if(arr[b]<n && brr[arr[b]]<b && arr[b]!=arr[a]-1) ans--;
		swap(brr[arr[a]-1],brr[arr[b]-1]);
		swap(arr[a],arr[b]);
		if(arr[a]>1 && brr[arr[a]-2]>a) ans++;
		if(arr[b]>1 && brr[arr[b]-2]>b) ans++;
		if(arr[a]<n && brr[arr[a]]<a && arr[b]!=arr[a]+1) ans++;
		if(arr[b]<n && brr[arr[b]]<b && arr[b]!=arr[a]-1) ans++;
		// print(arr);
		// print(brr);
		cout<<ans<<endl;
	}
}