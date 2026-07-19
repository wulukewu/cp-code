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

bool solve(){
	int n,m;
	cin>>n>>m;
	vector<int>p(n+1);
	FOR(i,0,n+1) p[i]=i;
	vector<int>v(n+1,1);
	int c=n;
	int a,b;

	auto find=[&](auto&& self,int x)->int{
		if(p[x]==x) return x;
		p[x]=self(self,p[x]);
		return p[x];
	};

	int mx=1;

	FOR(i,0,m){
		cin>>a>>b;
		int x=find(find,a);
		int y=find(find,b);
		if(x==y) {
			cout<<c<<' '<<mx<<endl;
			continue;
		}
		c--;
		v[y]+=v[x];
		v[x]=0;
		p[x]=p[y];
		mx=max(mx,v[y]);
		cout<<c<<' '<<mx<<endl;
		// print(v);
		// print(p);
	}

	// cout<<"Yes\n";
	return true;
}

signed main(){
	Fio;
	int T=1;
	// cin>>T;
	while(T--) {
		if(!solve()) cout<<"No\n";
	}
}