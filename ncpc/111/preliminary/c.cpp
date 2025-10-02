#include<bits/stdc++.h>
using namespace std;

void solve(){
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int ans;
	ans = max((2*(d*b+d*c)+a), (2*(c*a+c*d)+b));
	ans = max(ans, (2*(b*a+b*d)+c));
	ans = max(ans, (2*(a*c+a*b)+d));

	ans = max(ans, (2*(a*b+a*c+d*c+d*b)));

	ans = max(ans, (2*(c*d) + a + b));
	ans = max(ans, (2*(a*c) + b + d));
	ans = max(ans, (2*(a*b) + c + d));
	ans = max(ans, (2*(b*d) + a + c));

	ans = max(ans, (a*b)*2 + (c*d)*2);
	ans = max(ans, (a*c)*2 + (b*d)*2);

	ans = max(ans, (a + b + c + d));
	cout << ans << endl;
}

int main(){
	ios::sync_with_stdio(false), cin.tie(0);
	int t = 1;
	cin >> t;
	while(t--) solve();
	return 0;
}
