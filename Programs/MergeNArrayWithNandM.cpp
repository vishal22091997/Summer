#include<iostream>
using namespace std;

int main(){
	int n, m;
	cin>>n>>m;
	int a[n+m], b[n];
	for(int i=0;i<n+m;i++){
		cin>>a[i];
	}
	for(int i =0;i<n;i++){
		cin>>b[i];
	}
	int i = 0, j = 0, k = 0;
	while(i<n+m && j<n){
		if(a[i] < b[j]){
			a[k] = a[i];
			k++;
			i++;	
			while(i<n+m && a[i] == -1){
				i++;
			}
		}else{
			a[k] = b[j];
			k++;
			j++;
		}
	}
	while(j<n){
		a[k] = b[j];
		k++;j++; 
	}
	for(int i =0;i<n+m;i++){
		cout<<a[i] << " ";
	}
	cout<<endl;
}