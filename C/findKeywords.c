#include<stdio.h>
#include<stdlib.h>
#include<string.h>

const char *allKeyword[32] = { "auto", "double", "int", "struct", "break","else","long","switch",
"case", "enum",	"register","typedef",
"char",	"extern", "return",	"union",
"const",	"float",	"short",	"unsigned",
"continue",	"for",	"signed",	"void",
"default",	"goto",	"sizeof",	"volatile",
"do",	"if",	"static",	"while" };

int isKeyword(char s[]){
	int i;
	for(i=0;i<32;i++)
		if(strcmp(s,allKeyword[i]) == 0)
			return 1;
	return 0;
}

int main(){
	int count=0;
	char file_name[20],ch;
	FILE *fp;
	gets(file_name);
	fp = fopen(file_name, "r");
	if(!fp){
		perror("Error Opening File ");
		return 1;
	}
	int i =0;
	
	while( 1 ){
		char s[100];
		if (fscanf(fp, "%s", s) != 1)
            break;
        printf("%s", s);
        if(isKeyword(s))
        	count++;
	}
	printf("\nCount is %d",count);
	fclose(fp);
	return 0;
}
