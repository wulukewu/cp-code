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
	// set<int>s;
	vector<vector<int>>arr(n,vector<int>(3));
	FOR(i,0,n){
		cin>>arr[i][0]>>arr[i][1]>>arr[i][2];
	}
	sort(arr.begin(),arr.end());
	// s.insert(0);
	int ans=0;
	PQG<pair<int,int>>q;
	FOR(i,0,n){
		while(!q.empty() && q.top().F<arr[i][0]){
			// s.insert(q.front().S);
			ans=max(ans,q.top().S);
			q.pop();
		}
		// auto it=s.lower_bound(arr[i][0]);
		// if()
		// cout<<x<<endl;
		q.push({arr[i][1],arr[i][2]+ans});
		// cout<<arr[i][1]<<' '<<arr[i][2]+ans<<endl;
	}
	while(!q.empty()){
		ans=max(ans,q.top().S);
		q.pop();
	}
	cout<<ans;
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