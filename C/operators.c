#include<stdio.h>
#include<stdlib.h>
#include<string.h>

const char *allOperator[33] = { "+","-","=","*","/","%","++","--","==","!=","<=",">=","<",">","&&","||","!",
						"<<",">>","~","&","^","|", "=","+=","-=","/=","%=","<<=",">>=","&=","^=","|="
						};
						//sizeof()
						//?:
						//NOT IMPLEMENTED

int isOperator(char s[]){
	
	
        printf("\n\n\n%s\n\n\n", s);
        
        
	int i,j,k,index,count=0;
	char tmp[3];
	for(j = 0;j<strlen(s);j++){
		index=0;
		tmp[0]='\0';
		tmp[1]='\0';
		tmp[2]='\0';
		for(k=j;k<strlen(s)&&k<j+3;k++){
			tmp[index] = s[k];
			index++;
        printf("%s\n", tmp);
			for(i=0;i<33;i++)
				if(strcmp(tmp,allOperator[i]) == 0){
					printf("\t Value is: %s matched with %s\n",tmp,allOperator[i]);
					count++;
					break;	
				}
				
//			if(i<33)
//				j = j+ strlen(allOperator[i]);

		}		
	}
	return count;
}

int main(){
	int count=0,tmp;
	char file_name[20],ch;
	FILE *fp;
	printf("Enter File Name: ");
	gets(file_name);
	fp = fopen(file_name, "r");
	if(!fp){
		perror("Error Opening File ");
		return 1;
	}
	while( 1 ){
		char s[100];
		if (fscanf(fp, "%s", s) != 1)
            break;
        if((tmp=isOperator(s))!=0)
        	count+=tmp;
	}
	printf("\nCount is %d",count);
	fclose(fp);
	return 0;
}
