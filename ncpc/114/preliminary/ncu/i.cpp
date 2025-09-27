#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second

void solve(){
	int n, q;
	cin >> n >> q;
	vector<int> v_N(n+2,0);
	vector<int> v_C(n+2,0);
	vector<int> v_U(n+2,0);
	
	for(int i = 0; i < q; i++){
		int l, r;
		char s;
		cin >> l >> r >> s;
		if(s == 'N'){
			v_N[l] += 1;
			v_N[r+1] -= 1;
		}else if(s == 'C'){
			v_C[l] += 1;
			v_C[r+1] -= 1;
		}else if(s == 'U'){
			v_U[l] += 1;
			v_U[r+1] -= 1;
		}
	}
	
	int N=0, C=0, U=0;
	
	for(int i = 1; i <= n; i++){
		N += v_N[i];
		C += v_C[i];
		U += v_U[i];
		
		int ans;
		ans = min(N, C);
		ans = min(ans, U);
		if (N > 0 && C > 0 && U > 0){
			cout << ans << " ";
		}else{
			cout << "0" << " ";
		}
	}

}

int main(){
	ios::sync_with_stdio(false), cin.tie(0);
	int t = 1;
	//cin >> t;
	while(t--) solve();
	return 0;
}
