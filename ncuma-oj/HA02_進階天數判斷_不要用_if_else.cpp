#include <iostream>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    int ans = 31 - (m%2==0)*(m<8) - (m%2==1)*(m>=8);
    int a = (n%4==0) - (n%100==0) + (n%400==0);
    ans += (a-2) * (m==2);
    cout << ans;
}