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

void solve(){
	int n,m,a,b,c;
	cin>>n>>m;
	vector<vector<int>>arr(n);
	vector<vector<int>>brr(n,vector<int>(n,0));
	vector<int>v(n,0);
	FOR(i,0,m){
		cin>>a>>b>>c;
		a--;b--;
		arr[a].pb(b);
		arr[b].pb(a);
		brr[a][b]+=c;
	}

	int t;
	auto bfs=[&]( int x)->bool{
		t=1e18;
		v=vector<int>(n,-1);
		queue<int>q;
		q.push(x);
		v[x]=-2;
		while(!q.empty()){
			auto tem=q.front();
			// cout<<tem<<' '<<arr[tem].sz()<<endl;
			q.pop();
			for(auto& i:arr[tem]){
				if(v[i]!=-1) continue;
				if(brr[tem][i]==0) continue;
				v[i]=tem;
				q.push(i);
			}
			// print(v);
		}
		// print(v);
		if(v[n-1]==-1) return false;
		x=n-1;
		while(v[x]!=-2){
			t=min(t,brr[v[x]][x]);
			x=v[x];
		}
		x=n-1;
		while(v[x]!=-2){
			brr[v[x]][x]-=t;
			brr[x][v[x]]+=t;
			x=v[x];
		}
		// cout<<t<<endl;
		return true;
	};

// for(auto& i:brr) print(i);
// 		cout<<endl;
	int ans=0;
	while(true){
		bool res=bfs(0);
		// for(auto& i:brr) print(i);
		// cout<<endl;

		if(!res) break;
		ans+=t;
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