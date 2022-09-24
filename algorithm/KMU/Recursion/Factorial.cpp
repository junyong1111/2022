// 백준 마지막 팩토리얼 수 참고
#include <iostream>

using namespace std;

typedef long long ll;

ll factorial(int N, int count);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt", "r", stdin);

    int testCase = 0;
    cin >> testCase;

    while(testCase--){
        int number = 0;
        cin >> number;

        cout << factorial(1,number)%1000 <<"\n";
    }
    
    return 0;
}

ll factorial(int count, int N){
	if(N <= 1) return count;
	count = count*N;
	while(count%10 == 0) count/=10;
	count = count%100000;
	return factorial(count, N-1);
}