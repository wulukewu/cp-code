#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second

void solve(){
	int n;
	string s;
	cin >> n;
	cin >> s;
	queue<int> q_N;
	queue<int> q_C;
	queue<int> q_U;
	
	int ans = 0;
	for(int i = 0; i < n; i++){
		if(s[i] == 'N'){
			q_N.push(i);
		}else if(s[i] == 'C'){
			if(!q_N.empty()){
				q_C.push(i);
			}
		}else if(s[i] == 'U'){
			if(!q_N.empty() && !q_C.empty() && q_N.front() < q_C.front()){
				q_U.push(i);
				ans += 1;
				q_N.pop();
				q_C.pop();
				q_U.pop();
			}
		}
		
		if(q_N.empty()){
			while(!q_C.empty()){
				q_C.pop();
			}
		}
		
		if(q_C.empty()){
			while(!q_U.empty()){
				q_U.pop();
			}
		}
	}
	cout << ans << endl;
}

int main(){
	ios::sync_with_stdio(false), cin.tie(0);
	int t = 1;
	cin >> t;
	while(t--) solve();
	return 0;
}
