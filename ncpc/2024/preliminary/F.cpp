#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ALL(v) v.begin(), v.end()
#define PB push_back
#define endl '\n'


void solve(){
    while(true){
        int t;
        cin >> t;
        if(t==0) break;
		cout << "Object " << t << ":" << endl;

        string s;
        cin >> s;
		int n = s.size()-1;

		int m = 1000;
		int m2 = 2 * m + 1;
		vector < vector < int > > arr(m2, vector < int > (m2, 0));
		vector < int > row(m2, 0);
		vector < int > col(m2, 0);
		
		int offs[8][2] = {{0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1}, {1, 0}, {1, 1}};

		int x = m;
		int y = m;
		arr[m][m]++;
		row[m]++;
		col[m]++;

        for(int i=0; i<n; i++){
			int dir = s[i]-'0';
			x += offs[dir-1][0];
			y += offs[dir-1][1];
			// cout << x << ' ' << y << endl;
			arr[x][y]++;
			row[x]++;
			col[y]++;
        }

		// for(int i=990; i<1010; i++){
		// 	cout << row[i] << ' ';
		// }
		// cout << endl;
		// for(int i=990; i<1010; i++){
		// 	cout << col[i] << ' ';
		// }
		// cout << endl;

		int x1 = -1, x2 = -1, y1 = -1, y2 = -1;
		for(int i=0; i<m2; i++){
			if(row[i]!=0){
				if(x1==-1) x1 = i;
				else x2 = i;
			}
			if(col[i]!=0){
				if(y1==-1) y1 = i;
				else y2 = i;
			}
		}
		// cout << x1 << ' ' << x2 << ' ' << y1 << ' ' << y2 << endl;

		// for(int i=x1; i<=x2; i++){
		// 	for(int j=y1; j<=y2; j++){
		// 		// cout << arr[i][j];
		// 		if(arr[i][j]>0) cout << arr[i][j];
		// 		else cout << ' ';
		// 	}
		// 	cout << endl;
		// }

		for(int i=x1; i<=x2; i++){
			for(int j=y1; j<=y2; j++){
				if(arr[i][j]>0) cout << '*';
				else cout << ' ';
			}
			cout << endl;
		}

		if(!(x==m and y==m)){
			cout << "not a closed curve" << endl;
		}

		// cout << x << ' ' << y << endl;
		// cout << arr[m][m] << ' ' << arr[x][y] << endl;

		bool intersecting = false;
		for(int i=x1; i<=x2; i++){
			for(int j=y1; j<=y2; j++){
				// if(arr[i][j]>1 and !(i==x and j==y) and !(i==m and j==m)) intersecting = true;
				// else if(arr[i][j]>2 and ((i==x and j==y) or (i==m and j==m))) intersecting = true;
				// else if()
				if(((x==m and y==m and !(i==x and j==y)) or (x!=m and y!=m)) and arr[i][j]>1){
					intersecting = true;
				}else if(x==m and y==m and i==x and j==y and arr[i][j]>2){
					intersecting = true;
				}
			}
		}

		if(intersecting) cout << "self-Intersecting" << endl;

		cout << endl;
    }

}

int main(){
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    //cin >> t;
    while(t--) solve();
    return 0;
}
