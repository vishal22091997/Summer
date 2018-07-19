#include<iostream>
using namespace std;
int partition(int a[], int low, int high){
	int i = low, j = low;
	int pivot = a[high];
	while(i<=high){
		if(a[i] < pivot){
			swap(a[i], a[j]);
			i++;j++;
		}else{
			i++;
		}
	}
	swap(a[j], a[high]);
	return j;
}
int finder(int a[], int n){
	int low = 0, high = n-1;
	while(high - low + 1 > k){
		int mid = partition(a, low, high);
		int left = mid - low + 1;
		if(left == k){
			return mid;
		}else if(left > k){
			high = mid - 1;
		}else{
			k -= left;
			low = mid +1;
		}
	}
}
int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i = 0;i<n;i++){
		cin>>a[i];
	}



}