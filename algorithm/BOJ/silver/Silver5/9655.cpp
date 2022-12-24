#include <iostream>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	// freopen("input.txt", "r", stdin);
	
	int number = 0;
	cin >> number;
	bool flag = true; // sk
	while(number>0)
	{
		if(number>=3){
			number = number -3;
			if(flag == true)
				flag = false;
			else
				flag = true; 
		}
		else
		{
			number --;
			if(flag == true)
				flag = false;
			else
				flag = true;
		}

	}
	if(flag == false){
		cout << "SK" << "\n";
	}
	else{
		cout << "CY" << "\n";
	}

	return 0;
}
