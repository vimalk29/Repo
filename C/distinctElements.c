/*You are given a sorted (either in the increasing or in the decreasing order) sequence of numbers, ending with a -1. You can assume that are at least two numbers before the ending -1. 

Let us call the sequence x0  x1 ... xn -1.

You have to output the number of distinct elements in the sorted sequence.

Kindly do not use arrays in the code. */
#include<stdio.h>

int main(){
	int tmp,lastDigit=-1,count=0;
	while(1){
		scanf("%d",&tmp);
		if(tmp==-1)
			break;
		if(lastDigit!=tmp){
			lastDigit=tmp;
			count++;	
		}
	}
	printf("%d",count);
	return 0;
}
