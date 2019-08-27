#include<iostream>
#include<math.h>
#include<string>
using namespace std;
float getVal(string x){
	int i, n = x.size();
	string tmp1, tmp2="0.0";
	bool isDecimal = false;
	for(i=0; i<n &&  x[i] != '/' && x[i] != '.'  ;i++) //go till end of string or till a '.' or '/' is encountered
		if( x[i] < 48 || x[i] > 57 ){ 
			cout<<"Wrong data: '"<<x[i]<<"'\n";	//character other than digit or '.' or '/'
			return -1.0;			//
		}
	tmp1 = x.substr(0,i); //1st substring
	if(x[i]=='.')
		isDecimal = true;
	tmp2 = x.substr(i+1,n); //2nd substring
	for(int j = i+1  ; j<n ; j++)
		if( x[j] < 48 || x[j] > 57 ){ 
			cout<<"Wrong data: '"<<x[i]<<"'\n";	//character other than digit or '.' or '/'
			return -1.0;			//
		}
	if(stof(tmp2)!=0.0 && i!=n ){
		if(isDecimal)
			return stof(x); 
		else 
			return stof(tmp1)/stof(tmp2);
	}
	return stof(tmp1);
}
int main(){
	string f;
	cin>>f;
	cout<<getVal(f);
}
