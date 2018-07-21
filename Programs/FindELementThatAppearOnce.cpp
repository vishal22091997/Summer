#include<iostream>
using namespace std;
int findElement(int a[], int low, int high){
	if(high == low){
		return a[low];
	}else{
		int mid = low + (high-low)/2;
		if(a[mid] == a[mid-1]){
			if((mid-1-low) % 2 == 0)
				return findElement(a, mid+1, high);
			else
				return findElement(a, low, mid-2);
		}else if(a[mid] == a[mid+1]){
			if ((mid-low)%2==0)
				return findElement(a, mid+2, high);
			else{
				return findElement(a, low, mid-1);
			}
		}else{
			return a[mid];
		}
	}
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n];
		for(int i = 0;i<n;i++){
			cin>>a[i];
		}
		int index = findElement(a, 0, n-1);
		cout<<index<<endl;
	}
}