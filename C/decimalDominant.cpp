#include<iostream>
using namespace std;
void sort(int arr[],int n){
	for(int i=0;i<n;i++)
		for(int j=0;j<n-1;j++)
			if(arr[j]>arr[j+1])
				swap(arr[j],arr[j+1]);
}
void decimalDominant(int arr[],int n){
	sort(arr,n);
	
	int lastDigit=arr[0];
	int count=0, check= ( n % 10 >0 ? n/10 + 1 : n/10 );
	
	for(int i =0; i<n;i++)
	 	cout<<arr[i]<<" ";
	 	cout<<endl;
	for(int i =1; i<n;i++){
		if(arr[i]==lastDigit){
			count++;
		}else if( count!=0 && (count+1) >= check ){
				cout<<lastDigit<<" "<<count+1<<endl;
			count=0;
		}else{
			lastDigit = arr[i];
			count = 0;
		}
	}
}
int main(){
	int arr[]={1,2,3,4,5,6,7,8,9,1,3,5,7,9,12,13,8,1,6,20};
	int n=sizeof(arr)/sizeof(arr[0]);
	decimalDominant(arr,n);
	return 0;
}
