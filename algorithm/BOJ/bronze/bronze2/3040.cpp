#include <iostream>
#include <vector>
#include <algorithm>
#define MAX_SIZE 9

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	// freopen("input.txt","r", stdin);

	vector<int>V(MAX_SIZE, 0);
	int sum = 0;
	for(int i=0; i<MAX_SIZE; i++){
		cin >> V[i];
		sum += V[i];
	}
	
	int indexi = 0;
	int indexj = 0;
	for(int i=0; i<MAX_SIZE-1; i++){
		int temp = sum-V[i];
		for(int j=i+1; j<MAX_SIZE; j++){
			if(temp - V[j] == 100){
				indexi = i;
				indexj = j;
			} 
		}
	}

	for(int i=0; i<MAX_SIZE; i++){
		if(i==indexi || i==indexj){
			continue;
		}
		else{
			cout << V[i] << "\n";
		}
	}
	return 0;
}	
