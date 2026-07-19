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
	int n,m;
	cin>>n>>m;
	vector<pair<int,pair<int,int>>>arr(m);
	vector<int>p(n+1);
	FOR(i,0,n+1) p[i]=i;
	FOR(i,0,m){
		cin>>arr[i].S.F>>arr[i].S.S>>arr[i].F;
	}

	auto find=[&](auto&& self, int x)->int{
		if(p[x]==x) return x;
		p[x]=self(self,p[x]);
		return p[x];
	};

	sort(ALL(arr));
	// for(auto& i:arr){
	// 	cout<<i.F<<' '<<i.S.F<<' '<<i.S.S<<endl;
	// }

	int ans=0;
	FOR(i,0,m){
		int x=find(find,arr[i].S.F), y= find(find,arr[i].S.S);
		// cout<<i<<' '<<x<<' '<<y<<endl;
		if(x==y) continue;

		ans+=arr[i].F;
		p[x]=p[y];

		// cout<<i<<' '<<ans<<endl;
	}

	int x=find(find,1);
	FOR(i,2,n+1){
		if(x!=find(find,i)){
			cout<<"IMPOSSIBLE";
			return;
		}
	}

	cout<<ans;

}

signed main(){
	Fio;
	int T=1;
	// cin>>T;
	while(T--) {
		solve();
	}
}