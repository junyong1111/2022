#include <iostream>
#include <string>

using namespace std;

int main(void){
    // freopen("input.txt", "r" ,stdin);
    int N = 0;
    cin >> N;
    cin.ignore();
    for(int i=1; i<=N; i++){
        string str;
        getline(cin, str);
        cout << i << ". "  << str << "\n";
    }
    return 0;
}