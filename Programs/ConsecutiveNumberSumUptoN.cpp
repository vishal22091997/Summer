#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int i = 1, j = n/2, sum = (n * (n+2))/8;
	while(i<j){
		if(sum == n){
			cout<<i<<" "<<j<<endl;
			i++;
			j--;
		}else if(sum > n){
			j--;
		}else{
			i++;
		}
	}	
}
