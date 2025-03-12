#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

signed main() {

	int n=21;
	vector < int > arr(n);

	for(int i=0; i<n; i++){
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end());

	int ans = -1;
	for(int i=0; i<n-1; i++){
		// cout << i << endl;
		if(arr[i]==arr[i+1]){
			i++;
		}else{
			if(arr[i+1]==arr[i+2]){
				ans = i;
			}else{
				ans = i+1;
			}
			break;
		}
	}
	if(ans==-1){
		ans = arr[n-1];
	}

	cout << ans;



	 
}