#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second

void solve(){
	int m;
	cin >> m;
	string s;
	cin >> s;
	
	queue < int > N;
	queue < int > C;
	queue < int > U;
	
	for(int i=0; i<m; i++){
		if(s[i]=='N'){
			N.push(i);
		}else if(s[i]=='C'){
			C.push(i);
		}else{
			U.push(i);
		}
	}
	
	int ans = 0;
	int n, c, u;
	while(!N.empty() and !C.empty() and !U.empty()){
		n = N.front();
		N.pop();
		
		if(C.empty()) break;
		bool cbreak = false;
		c = C.front();
		while(n>c){
			C.pop();
			if(C.empty()){
				cbreak = true;
				break;
			}
			c = C.front();
		}
		if(cbreak) break;
		
		if(U.empty()) break;
		bool ubreak = false;
		u = U.front();
		while(c>u){
			U.pop();
			if(U.empty()){
				ubreak = true;
				break;
			}
			u = U.front();
		}
		if(ubreak) break;
		
		ans++;
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
