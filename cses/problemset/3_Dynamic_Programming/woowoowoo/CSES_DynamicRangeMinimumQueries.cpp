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
	int n;vector<int>arr,lazy;
	segment(vector<T>&init){
		n=init.sz();arr=vector<T>(n*4,0);lazy=vector<T>(n*4,0);
		for(int i=0;i<n;i++)arr[i+n]=init[i];
		for(int i=n-1;i>0;i--){arr[i]=action(arr[i*2],arr[i*2 | 1]);}
	}
	T action(T a,T b){
		return min(a,b);    //###############
	}
	void apply(int x,T v){
		arr[x]+=v;
		if(x<n) lazy[x]+=v;
	}
	void push(int x,int l,int r){
		if(!lazy[x]) return;
		arr[LC(x)]+=lazy[x];
		arr[RC(x)]+=lazy[x];
		lazy[LC(x)]+=lazy[x];
		lazy[RC(x)]+=lazy[x];
		lazy[x]=0;
	}
	void modify(int x,int y){
		arr[x+n-1]=y;int t=1;
		for(int i=(n+x-1)/2;i>=1;i/=2){
			arr[i]=action(arr[i*2],arr[i*2+1]);
		}
	}
	int query(int l,int r){
		T res=INT_MAX;		//###########
		for(l+=n-1,r+=n-1;l<=r;l/=2,r/=2){
			if(l&1) res=action(res,arr[l++]);
			if(!(r&1)) res=action(res,arr[r--]);}
		return res;
	}
};

int M=1e9+7;

void solve(){
	int n,m;
	cin>>n>>m;
	vector<int>arr(n);
	FOR(i,0,n) cin>>arr[i];

	segment<int>seg(arr);

	int a,b,c;
	FOR(i,0,m){
		cin>>a>>b>>c;
		if(a==1) seg.modify(b,c);
		else cout<<seg.query(b,c)<<endl;
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