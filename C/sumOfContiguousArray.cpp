//Kadane's algo
#include<iostream> 
using namespace std; 
int maxSumOfSubArray(int arr[], int size){ 
    int max_sum = arr[0], sum = 0; 
  
    for (int i = 0; i < size; i++) { 
        sum = sum + arr[i]; //adding value of element to sum
        if (max_sum < sum) 
            max_sum = sum;  // the max sum value got until now
  
        if (sum < 0) //set sum to 0 if value goes below 0
            sum = 0; 
            
    } 
    return max_sum; 
} 
int main(){ 
    int arr[] = {-1, 3, -4, 4, -3, 1, 5, -3}; //array where max_sum is of 4, -3, 1, 5
    int n = sizeof(arr)/sizeof(arr[0]); //size of array
    cout << "Maximum contiguous sum is " << maxSumOfSubArray(arr, n); 
    return 0; 
} 
