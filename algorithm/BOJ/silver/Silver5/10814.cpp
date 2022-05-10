#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

typedef struct sortAge{
	int age;
	string name;
}Age; // 나이와 이름을 가진 구조체 선언

bool compare(const Age & A, const Age &B){
	if(A.age < B.age){
		return true; //나이를 기준으로 오름차순 정렬
	}
	else{
		return false;
	}
} //sort 함수의 구조체를 넘겨줘야 함 또한 나이순으로 정렬



int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int testCase;
	cin >> testCase;
	int N = testCase;
	vector<Age>ans(testCase);
	int idx = 0;
	while(testCase--){
		int a;
		string n;
		cin >> a >> n;
		ans[idx].age = a;
		ans[idx++].name = n;
	}//while
	stable_sort(ans.begin(), ans.end(), compare); //위에 정의한 기준으로 정렬 + stable_sort를 사용함으로 값이 같다면 기존의 순서 유지

	for(int i=0; i<N; i++)
		cout << ans[i].age << " " << ans[i].name << "\n";
	return 0;
}

