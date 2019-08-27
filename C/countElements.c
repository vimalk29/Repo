//wap to count no. of char, words and lines
#include<stdio.h>
#include<conio.h>
int main(){
	int wCount=0, cCount=0, lCount=0;
	FILE *f1;
	char c, fileName[30];
	printf("Enter file name: ");
	gets(fileName);
	f1=fopen(fileName,"r+");
	if(f1 == NULL){
		perror("Error Opening File\n");
		return 0;
	}
	while( ( c = fgetc(f1) )!=EOF ){
		if(c==' ')
			wCount++;
		else if(c=='\n')
			lCount++;
		else
			cCount++;
	}
	printf("No. of chars: %d\nNo. of words: %d\nNo. of Lines: %d\n",cCount,wCount,lCount);
	fclose(f1);
	return 0;
}
