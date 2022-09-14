#include <iostream>
#include <string>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt", "r", stdin);

    string a,b;

    cin >> a >> b;

    int asum = 0;
    int bsum = 0;
    for(int i=a.length()-1; i>=0; i--){
        asum = asum *10;
        asum = asum + a[i] -48;
    }

    for(int i=b.length()-1; i>=0; i--){
        bsum = bsum *10;
        bsum = bsum + b[i] -48;
    }

    int sum = asum + bsum; 
    string answer = to_string(sum);

    int Anw  = 0;
    for(int i=answer.length()-1; i>=0; i--){
        Anw = Anw * 10;
        Anw = Anw  + answer[i] - 48;
    }

    cout << Anw;


    
    


    


    return 0;

}
