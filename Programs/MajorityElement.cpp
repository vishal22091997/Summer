#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int a[n];
	int count = 0, last = -1;
	for(int i =0;i<n;i++){
		cin>>a[i];
		if(count == 0){
			last =  a[i];
			count++;
		}else{
			if(last == a[i]){
				count++;
			}else{
				count--;
			}
		}
	}
	if(count <= 0){
		cout<<"NO Majority Element"<<endl;
	}else{
		count = 0;
		for(int i = 0;i<n;i++){
			if(a[i] == last){
				count++;
			}
		}
		if(count > n/2){
			cout<<last<<endl;
		}else{
			cout<<"NO Majority Element"<<endl;
		}
	}

}