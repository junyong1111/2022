#include <iostream>

using namespace std;

int gcd(int a, int b);
void fractionAdd(int a, int b, int c, int d);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt", "r", stdin);

    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;
    
    cin >> a >> b >> c >> d;
    fractionAdd(a,b,c,d);

    return 0;
}


int gcd(int a, int b){
    if(b==0)
        return a;
    else
        return gcd(b, a%b);
}
void fractionAdd(int a, int b, int c, int d){
    int answerA = 0;
    int answerB = 0;
    if(b!=d){
        answerB = b*d;
        answerA = (a*d) + (b*c);
    }
    else{
        answerB = b;
        answerA = a+c;
    }
    int temp =  gcd(answerA, answerB);
    cout << answerA/temp << " " << answerB/temp << "\n";
}