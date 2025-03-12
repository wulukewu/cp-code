#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    char a = 'a';
    cout << a-0 << endl;

    int b = 65;
    char c = b + 0;
    cout << c << endl;
}
