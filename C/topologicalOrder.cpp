//Topological order implementation
#include<iostream>
using namespace std;

void topologicalOrder(int arr[][], int n){
	
}

int main(){
	int arr[20][20];
	int n;
	cout<<"Enter no. of Vertices: ";
	cin>>n;
	cout<<"Enter the adjacency matrix of the graph:\n";
	
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin>>arr[i][j];
	
	topologicalOrder(arr,n);
}
