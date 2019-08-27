#include<stdio.h>
#include<stdlib.h>
int main(){
	FILE *f1, *f2;
	char c, fileName[30];
	int stringFlag=0;
	printf("Enter file name: ");
	gets(fileName);
	f1=fopen(fileName,"r+");
	f2=fopen("tmpFile.txt", "w+");
	if(f1 == NULL || f2 == NULL){
		perror("Error Opening File\n");
		exit(0);
	}
	while( (c = fgetc(f1)) != EOF ){
		if( c == 34 )						//true if character is a double quote
			stringFlag++;
		if(stringFlag % 2 == 0){			//true if character is not a part of a string
			if(c == '/'){					//true if character is '/'
				c = fgetc(f1);				// getting next character to check
				if( c == '/' )				//true if next character is '/', single line comment
					while( (c = fgetc(f1)) != '\n' && c != EOF); //
				else if( c == '*' ){		//true if next character is '*', multi line comment
					jump:
						while( (c = fgetc(f1)) != '*' && c != EOF); //when a '*' is encountered and is not EOF
						if(c == EOF)	//if reaches end of file
							break; // End making changes 
						else if( (c = fgetc(f1)) != '/' ) //if next char is not '/' meaning not the end of multi line comment
							goto jump; // continue while loop
					
				}else{					//when next char is neither '/' nor '*' 
					fputc('/', f2);		// put '/' as it is in f2
					fputc(c, f2);		// insert the character as it is in f2
				}
			}else
				fputc(c, f2); 			// if character is not '/', insert it in f2
		}
		else //part of string needs to be saved no matter the character
			fputc(c, f2);
		
	}
	fclose(f1);	//close files before deletion
	fclose(f2);	//close file before renaming
	int status = remove(fileName);		//delete original
	if(status == 0){
		rename("tmpFile.txt", fileName);	//rename tmpFile to original file
		printf("Comments Removed Succesfully\n");
	}else
		perror("Error Occured while deleting original file.\nCopy of Original file is generated without comments.\n");
	return 0;
}
