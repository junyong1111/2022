// 백준 정리 필요 
#include <iostream>

using namespace std;

typedef long long ll;

ll factorial(int N, int count);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt", "r", stdin);

    int number = 0;
    cin >> number ;

    cout << factorial(1,number) % 10 <<"\n";
    
    return 0;
}

ll factorial(int count, int N){
	if(N <= 1) return count;
	count = count*N;
	while(count%10 == 0) count/=10;
	count = count%100000;
	return factorial(count, N-1);
}
