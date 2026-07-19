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
	int n;
	cin>>n;
	vector<string>arr(n);
	vector<vector<bool>>v(n,vector<bool>(n,false));
	FOR(i,0,n) cin>>arr[i];
	queue<pair<int,int>>q;
	q.push({0,0});
	v[0][0]=true;
	FOR(i,1,n*2){
		int x=q.size();
		char m='Z';
		vector<pair<int,int>>tmp;
		FOR(j,0,x){
			m=min(m,arr[q.front().F][q.front().S]);
			// q.push(q.front());
			tmp.pb(q.front());
			q.pop();
		}
		cout<<m;
		for(auto& j:tmp){
			if(arr[j.F][j.S]==m) {
				if(j.S+1<n && !v[j.F][j.S+1]) {
					q.push({j.F,j.S+1});
					v[j.F][j.S+1]=true;
				}
				if(j.F+1<n && !v[j.F+1][j.S]) {
					q.push({j.F+1,j.S});
					v[j.F+1][j.S]=true;
				}
			}
		}
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