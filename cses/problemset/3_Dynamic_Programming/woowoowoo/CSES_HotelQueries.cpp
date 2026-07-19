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
template<typename T>
void printp(T a){
	for(auto u:a){
		cout<<u.F<<' '<<u.S<<endl;
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

template<typename T>
class fenwick{
public:
	vector<T>bit;int size=3e5;
	fenwick(int s){size=s;bit=vector<T>(size,0);}
	int lb(int x){return x&(-x);}
	void up(int x,T y){for(int i=x;i<size;i+=lb(i))bit[i]+=y;}
	T sum(int x){T res=0;for(int i=x;i>=1;i-=lb(i))res+=bit[i];return res;}
};

template<class T>
class segment{
public:
	int n;vector<int>arr;
	segment(vector<T>&init){
		n=init.sz();arr=vector<T>(n*2,0);
		for(int i=0;i<n;i++)arr[i+n]=init[i];
		for(int i=n-1;i>0;i--){arr[i]=action(arr[i*2],arr[i*2 | 1]);}
	}
	int action(int a,int b){
		return min(a,b);    //###############
	}
	void modify(int x,int y){
		arr[x+n-1]=y;       //###############
		for(int i=(n+x-1)/2;i>=1;i/=2){
			arr[i]=action(arr[i*2],arr[i*2+1]);
		}
	}
	int query(int l,int r){
		int res=INT_MAX;		//###########
		for(l+=n-1,r+=n-1;l<=r;l/=2,r/=2){
			if(l&1) res=action(res,arr[l++]);
			if(!(r&1)) res=action(res,arr[r--]);}
		return res;
	}
};

int M=1e9+7;

int st[200005<<2]={0};
vector<int>h(2e5+5);
void up(int x,int l,int r,int u){
	// cout<<x<<' '<<l<<' '<<r<<' '<<u<<endl;
	if(l==r){
		st[x]=h[u-1];
		return;
	}
	int mid=(l+r)>>1;
	if(u<=mid){
		up(x<<1,l,mid,u);
	}
	else up(x<<1|1,mid+1,r,u);
	st[x]=max(st[x<<1],st[x<<1|1]);
}

int query(int x,int l,int r,int u){
	// cout<<x<<' '<<l<<' '<<r<<' '<<u<<endl;
	if(l==r) return l;
	int mid=(l+r)>>1;
	if(st[x<<1]>=u) return query(x<<1,l,mid,u);
	else return query(x<<1|1,mid+1,r,u);
}

void solve(){
	int n,m,tt;
	cin>>n>>m;
	FOR(i,0,n) cin>>h[i];
	// FOR(i,0,m) cin>>r[i];
	FOR(i,0,n){
		up(1,1,n,i+1);
	}
	// FOR(i,0,20) cout<<st[i+1]<<' ';
	FOR(i,0,m){
		cin>>tt;
		if(st[1]<tt){
			cout<<0<<' ';
			continue;
		}
		int ans=query(1,1,n,tt);
		cout<<ans<<' ';
		h[ans-1]-=tt;
		up(1,1,n,ans);
	}
}

signed main(){
	Fio;
	int T=1;
	// cin>>T;
	while(T--) {
		solve();
	}
}