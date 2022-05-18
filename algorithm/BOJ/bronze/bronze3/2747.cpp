#include <iostream>
#include <vector>

using namespace std;

vector<int>memory(1000001, 0);

int fib(int N){
    if(N<=1)
        return N;
    else{
        if(memory[N]==0){
            memory[N] = fib(N-1) + fib(N-2);
            return memory[N];
        }//없는경우
        else {
            return memory[N];
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N = 0;
    cin >> N;
    cout << fib(N) << "\n";

    return 0;
}
