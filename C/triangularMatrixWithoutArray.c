#include<stdio.h>

int main(){
	
  int i,j,n,tmp;
  int flagUp=1,flagDown=1;
  scanf("%d",&n);
  for(i=0;i<n;i++)
  	for(j=0;j<n;j++){
  		scanf("%d",&tmp);
  		printf("\n%d--%d\n",i,j);
  		if( i>j && flagUp==1 )
  			if(tmp == 0)
	  			flagUp=1;
	  		else
	  			flagUp=0;
  		if( i<j && flagDown==1 )
  			if( tmp == 0 )
	  			flagDown=1;
	  		else
	  			flagDown=0;
	  }
  if(flagUp || flagDown)
  	printf("yes");
  else
  	printf("no");
  return 0;
}
