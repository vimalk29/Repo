#include<iostream>
using namespace std;
int main(){
  int a[5],max=0,count=0;
  for(int i=0;i<5;i++){
    cin>>a[i];
    if(max<a[i])
    	max = a[i];
  }
  int x[5][max];
  
  for(int i=0;i<5;i++)
    for(int j=0;j<a[i];j++)
    	cin>>x[i][j];
    	
    	
		cout<<endl;
		cout<<endl;
		cout<<endl;
  for(int i=0;i<5;i++){
  	for(int j=0;j<a[i];j++){
  		int tmp=x[i][j];
  		count=0;
			for(int k=0;k<5;k++)
				if(k!=i){
					for(int l=0;l<a[i];l++){
				  		if(tmp==x[k][l])
				  			count++;
				  		//cout<<x[k][l]<<" ";
					}
					cout<<endl;
				}
		if(count>=3)
			cout<<tmp<<"\n";
		cout<<endl;
	}
		cout<<endl;
  }
  return 0;
}
