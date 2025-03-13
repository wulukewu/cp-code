#include <iostream>
#include <algorithm>

using namespace std;

int sum_int(int a, int b){
    return a + b;
}

string sum_string(string a, string b){
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    string s = b + a;
    return s;
}

signed main(){
    // freopen("intput.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int a, b;
    cin >> a >> b;

    string s1, s2;
    cin >> s1 >> s2;

    cout << sum_int(a, b) << endl << sum_string(s1, s2);
}