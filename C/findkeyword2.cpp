#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;

const string allKeyword[32] = { "auto", "double", "int", "struct", "break","else","long","switch",
"case", "enum",	"register","typedef",
"char",	"extern", "return",	"union",
"const",	"float",	"short",	"unsigned",
"continue",	"for",	"signed",	"void",
"default",	"goto",	"sizeof",	"volatile",
"do",	"if",	"static",	"while" };

int isKeyword(string s){
	int i;
			//cout<<"t\t\tCount!!!!!!!!!!!!!!!!!!!!!!!\t"<<s<<endl;
	for(i=0;i<32;i++)
		if(s.compare(allKeyword[i])==0){
			cout<<"Increasing Count!!!!\t"<<s<<endl;
			return 1;
		}
	return 0;
}
//strcmp(s, allKeyword[i]) == 0
int generatePossibleStrings(string s){
	cout<<endl;
	int count=0;
	for(int i=0; i<s.length(); i++)
		for(int j=s.length(); j>=i ;j--){
			string tmp=s.substr(i,j);
			cout<<tmp<<endl;
			if(isKeyword(tmp)){
				count++;
				i+=tmp.length()-1;
			}
		}
    return count;
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
		char s[200];
		if (fscanf(fp, "%s", s) != 1)
            break;
        cout<<s<<" ";
        if(generatePossibleStrings(s))
        	count++;
	}
	printf("\nCount is %d",count);
	fclose(fp);
	return 0;
}
