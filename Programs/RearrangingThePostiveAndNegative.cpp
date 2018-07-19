#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i = 0;i<n;i++){
		cin>>a[i];
	}
	int j = 0, i = 0;
	while(i<n){
		if(a[i] < 0){
			swap(a[i], a[j]);
			j++;	
		}
		i++;
	}
	for(int i =0;i<n;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
}