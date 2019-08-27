/*When you keep track of stock prices, or your weight during a diet
programme, the daily prices or weights fluctuate a lot. One way to
identify the general trend is to keep track of the average over the
last 3 days, for example. This technique often smooths out the
fluctuations, and makes the trend clearer. This technique is called
"moving average".

In this question, you have to output the "moving average" of a
sequence of non-negative numbers. The moving average is the sequence
of averages of the last 3 entries. For the first 2 numbers, no average
is output.

For example, if the sequence of numbers is

a1, a2, a3, a4, a5

and k=3, then the 3-moving average is

(a3+a2+a1)/3, (a4+a3+a2)/3, (a5+a4+a3)/3.


Input
-----

The input is a sequence of non-negative floating point numbers,
terminated by a -1. The -1 is not part of the sequence. There will be
at least 3 numbers in the sequence.

Output
------
You have to output the moving average of the sequence. The output
should be printed correct to one digit after the decimal. 

Sample Input 1
--------------
70.8 70.9 71.2 70.7 70.2 -1

Sample Output 1
---------------
71.0 70.9 70.7 */
 
 // 1 2 3
 // 2 3 4 
 // 3 4 5
#include<stdio.h>
/*int movingAverage(){
	int val,n=0, lastTaken=3,count=0;
	float a,b,c;
	int *arr;
	while(1){
		scanf("%d",arr);
		arr++;
		count++;
	}
	
	return -1;
}*/

int main(){
	int *arr,count=0, i,tmp=100000;
	arr = &tmp;
	while(tmp--){
		printf("%d",*(arr+count*sizeof(count)) );
		count++;
	}
	return 0;
}
