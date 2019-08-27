#include<iostream>
using namespace std;

void quicksort(int arr[],int low,int high){	// low = starting index, high = ending index
	if(low<high){
		int pivot= low, index;
		int toPart = 2;
		while(toPart != 0){//stop loop only when pivot is at the desired position
			toPart = 0;
			index=-1;
			for(int i = high ; i > pivot; i--) // getting smallest element from R to L till pivot
				if(arr[i] < arr[pivot])
					index=i;
			if(index!=-1){
				swap(arr[index], arr[pivot]);
				pivot = index;
				toPart++;
				index=-1;
			}
			for(int i = low; i < pivot; i++)// getting largest element from L to R till pivot
				if(arr[i] > arr[pivot])
					index=i;	
			if(index!=-1){
				swap(arr[index], arr[pivot]);
				pivot = index;
				toPart++;
			}
		}
		quicksort(arr, low, pivot-1); // quicksort left side array
		quicksort(arr, pivot+1, high);//quicksort right side array
	}
}
int main(){
	int arr[] = {5,4,3,2,1};
	int n=sizeof(arr)/sizeof(arr[0]);
	quicksort(arr, 0 , n-1);
	
	for(int i = 0; i<n; i++)
		cout<<arr[i]<<" ";
	return 0;
}
