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
	int n,m,a,b,c;
	cin>>n>>m;
	vector<pair<pair<int,int>,int>>arr(m);
	vector<vector<int>>brr(n+1);
	vector<vector<int>>crr(n+1);
	FOR(i,0,m){
		cin>>arr[i].F.F>>arr[i].F.S>>arr[i].S;
		brr[arr[i].F.S].pb(arr[i].F.F);
		crr[arr[i].F.F].pb(arr[i].F.S);
	}

	queue<int>q;
	q.push(n);
	vector<bool>r(n+1,false);
	r[n]=true;
	while(!q.empty()){
		for(auto& i:brr[q.front()]){
			if(r[i]) continue;
			q.push(i);
			r[i]=true;
		}
		q.pop();
	}

	q.push(1);
	vector<int>rr(n+1,false);
	rr[1]=true;
	while(!q.empty()){
		for(auto& i:crr[q.front()]){
			if(rr[i]) continue;
			q.push(i);
			rr[i]=true;
		}
		q.pop();
	}


	vector<int>dis(n+1,LLONG_MIN/2);
	dis[1]=0;
	FOR(i,0,n){
		FOR(j,0,m){
			if(dis[arr[j].F.F]+arr[j].S>dis[arr[j].F.S]){
				dis[arr[j].F.S]=dis[arr[j].F.F]+arr[j].S;
			}
			// print(dis);
		}
		// print(dis);
	}

	// print(dis);
	// print(r);

	FOR(j,0,m){
		if(dis[arr[j].F.F]+arr[j].S>dis[arr[j].F.S] && r[arr[j].F.S] && rr[arr[j].F.S]){
			cout<<-1;
			return true;
		}
	}

	cout<<dis[n];

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