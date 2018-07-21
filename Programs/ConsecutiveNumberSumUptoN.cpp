#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int i = 0, j = 0, sum = 0;
	while(i <= n/2 && j <= n/2){
		
		if(sum == n){
			cout<<i<<" "<<j<<endl;
			sum = 0;
			i = j+1;j = i;
		}else if(sum > n){
			sum -= i;
			i++;
		}else{
			sum += j;
			j++;
		}
	}	
}
