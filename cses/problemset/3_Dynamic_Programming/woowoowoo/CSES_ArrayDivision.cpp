// cp
#include <bits/stdc++.h>
#define int long long
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define F first
#define S second
#define pb push_back
#define ALL(v) v.begin(),v.end()
#define endl '\n'
#define sz size
#define Fio ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr)
using namespace std;
template<typename T> using PQ = priority_queue<T>;
template<typename T> using PQG = priority_queue<T, vector<T>, greater<T>>;
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

void solve(){
	int n,k;
	cin>>n>>k;
	vector<int>	arr(n);
	int s=0,l=0;
	FOR(i,0,n) {
		cin>>arr[i];
		s+=arr[i];
		l=max(l,arr[i]);
	}

	auto che=[&](int x)->bool{
		int c=0,sum=0;
		FOR(i,0,n){
			sum+=arr[i];
			if(sum>x){
				c++;
				sum=arr[i];
			}
		}
		if(sum) c++;
		// cout<<c<<endl;

		if(c<=k) return true;
		else return false;
	};

	int r=s+1;
	l--;
	while(r-l>1){
		int m=(l+r)/2;
		if(che(m)) r=m;
		else l=m;
		// cout<<l<<' '<<r<<endl;
	}

	cout<<l+1;

}

signed main(){
	Fio;
	int T=1;
	// cin>>T;
	while(T--) {
		solve();
	}
}