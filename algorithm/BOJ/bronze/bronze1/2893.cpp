#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int sugar5;
    int r = 0;
    int N = 0;
    cin >> N;
    sugar5 = N / 5;
    r = N%5;
    if(r==0) // 5로 다 나뉘어진다면 바로 출력 
        cout << sugar5;
    else if (r==1 && sugar5>=1){ //5로 나누었을 때 1이 남는다면 그 전 5개봉지를 1개빼고 5+1 -> 3개 봉지 2개로 나눈다.
        cout << sugar5 -1 + 2 << "\n";
    }
    else if (r==2 && sugar5>=2) { //5로 나누었을 때 2가 남는다면 그 전 5개봉지를 2개 빼고 10+2 -> 3개 봉지 4개로 나눈다.
        cout << sugar5 -2 + 4 << "\n";
    }
    else if (r==3 ){ //5로 나누었을 때 3이 남는다면 3개봉지 1개만을 추가해주면 된다.
        cout << sugar5 + 1 <<"\n";
    }
    else if (r==4 && sugar5>=1){ //5로 나누었을 때 4가 남는다면 5개봉지를 1개 빼고 5+4 -> 3개 봉지 3개로 나누다.
        cout << sugar5-1 +3 <<"\n";
    }
    else { // 그 이외에 경우는 모두 -1로 처리한다.
        cout << -1 << "\n";
    }

    return 0;
}