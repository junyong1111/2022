#include <iostream>
#include <algorithm>
#define SIZE 8
using namespace std;



void Merge(int arr[], int start, int mid, int end){
	int i = start;
	int j = mid+1;
	int idx = start;
	int len = SIZE;
	int *temp = new int[len];

	while(i<=mid && j<=end){ // 둘 중 하나라도 끝날때까지
		if(arr[i] <= arr[j])
			temp[idx++] = arr[i++];
		else
			temp[idx++] = arr[j++];
		 
	}	//while	
	while(i<=mid)
		temp[idx++] = arr[i++]; // 앞쪽 데이터가 남아있다면
	while(j<=end)
		temp[idx++] = arr[j++]; // 뒤쪽 데이터가 남아있다면 

	for(int k=start; k<=end; k++)
		arr[k] = temp[k];
	delete[] temp;
}
void Merge_Sort(int arr[], int start,int end){
	if(start < end){ //시작보다 끝이 더 길어야 함 그게 아니라면 길이가 1개
		int mid = (start+end)/2; //시작과 끝의 중간지점
		Merge_Sort(arr, start, mid); //시작과 중간을 정렬
		Merge_Sort(arr, mid+1, end); // 중간과 끝을 정렬
		Merge(arr,start ,mid , end); // 합병 정렬
	}
}

int main(){
	int arr[] = {12,24,63,12,51,2,125,32};
	int start = 0;
	int end = SIZE-1;

	Merge_Sort(arr,start,end);
	for(int i=0; i<=end; i++)
		cout << arr[i] << " ";
	cout << endl;
	return 0;
}
