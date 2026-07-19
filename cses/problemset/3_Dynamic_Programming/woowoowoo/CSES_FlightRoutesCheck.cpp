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
	int n,m,a,b;
	cin>>n>>m;
	vector<vector<int>>arr(n+1),brr(n+1);
	FOR(i,0,m){
		cin>>a>>b;
		arr[a].pb(b);
		brr[b].pb(a);
	}

	vector<bool>v1(n+1,false),v2(n+1,false);
	v1[1]=true;
	v2[1]=true;

	queue<int>q;
	q.push(1);

	while(!q.empty()){
		for(auto& i:arr[q.front()]){
			if(v1[i]) continue;
			v1[i]=true;
			q.push(i);
		}
		q.pop();
	}

	q.push(1);
	while(!q.empty()){
		for(auto& i:brr[q.front()]){
			if(v2[i]) continue;
			v2[i]=true;
			q.push(i);
		}
		q.pop();
	}

	FOR(i,1,n+1){
		if(!v1[i]){
			cout<<"NO\n1 "<<i;
			return;
		}
		if(!v2[i]){
			cout<<"NO\n"<<i<<" 1";
			return;
		}
	}

	cout<<"YES";


}

signed main(){
	Fio;
	int T=1;
	// cin>>T;
	while(T--) {
		solve();
	}
}