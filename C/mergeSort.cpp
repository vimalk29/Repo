//wap to sort given elements using merge sort
#include<iostream>
using namespace std;
void combineArray(int a[], int low, int mid, int high){				
	int temp[ high-low + 1 ];
	int i=low,j=mid+1,k=0;
	
	while(i<mid+1 && j<high+1){
		if(a[i]<a[j]){
			temp[k++]=a[i++];
		}else{
			temp[k++]=a[j++];
		}
	}
	while(i<mid+1)
		temp[k++]=a[i++];
			
	while(j<high+1)
		temp[k++]=a[j++];
		
	for(int i=low,k=0;i<=high;i++)
		a[i]=temp[k++];													
}

void mergeSort(int arr[],int low, int high){		
	if(low<high){
		int mid = (low+high)/2;
		mergeSort(arr,low,mid);
		mergeSort(arr,mid+1,high);
		
		combineArray(arr, low, mid, high);
	}
}
int main(){
	int len;
	cout<<"Enter length of array: ";
	cin>>len;
	int arr[len];
	cout<<"Enter elements of array:\n";
	for(int i=0;i<len;i++)
		cin>>arr[i];
	mergeSort(arr, 0, len-1);
	
	for(int i=0;i<len;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
	return 0;
}
