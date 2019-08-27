#include<iostream>
#include<math.h>
#include<string>
using namespace std;

struct data{
	char c;
	float value;
	string code;
};

void sort(struct data x[], n){
	for(int i = 0; i<n;i++)
		for(int j = 0; j<n-1;j++ )
			if(x[i].value > x[i+1].value)
				swap( x[i], x[i+1] );
}

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

int divideAt(float arr[],low,high){
	int i,flag;
	float sum=0.0, dif=1.0;
	for(i=low;i<high-1;i++){
		sum+=arr[i];
		if( dif > fabs( 2 * sum - 1 ) ){
			dif = fabs( 2 * sum - 1 );
			flag = i;
		}
	}
	return i;
}
void shanonFano(float arr[],n){
	string codes[n];
	int i,divideHere,flag =0;
	int low = 0, high = n-1;
	while(!flag){
		divideHere=divideAt(arr,low,high);
		for(i=low;i<=divideHere;i++)
			strcat(codes[i],"0");
		for(  ;i<=high;i++)
			strcat(codes[i],"1");
	}
	
}

void coding(float arr[], string codes[],int low,int high,int n){
	if(low!=high){
		
	}
	
}

int main(){
	int n, M;
	string tmp;
	cout<<"Enter no. of symbols: ";
	cin>>n;
	cout<<"Enter levels (M=?): ";
	cin>>M;
	struct data d[n];
	float sum=0.0;					//array of n size
	cout<<"Enter Probabilities:\n";
	for(int i=0;i<n;i++){
		cout<<"x"<<i+1<<": ";
		cin>>x;			//taking all probabilities
		d[i].value=getVal(x);
		if(d[i].value==-1.0){
			cout<<"Please Enter another value with a pattern of either 8/9 or 7.5:\n";
			i--;
		}else
			sum+=d[i].value;
	}
	if(sum!=1.0){
		cout<<"Sum of the probabilities is: "<<sum<<"\nClosing program!!!\n";
		return 0;
	}
	cout<<"\nProbabilities are: \n";
	for(int i=0;i<n;i++){
		cout<<"x"<<i+1<<": "<<d[i].value;			//taking all probabilities
	}
	sort(d,n);
	//shanonFano(arr,n);
	return 0;
}


/*
1 2 3 4 
1 9
3 7
6 4
*/
