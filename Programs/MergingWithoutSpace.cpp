#include<iostream>
using namespace std;
void merging(int a[], int fs, int fe, int ss, int se){
	int b[se - fs + 1];
	int i = fs, j = ss, k = 0;
	while(i<=fe && a[i] < 0){
		b[k++] = a[i++];
	}
	while(j<=se && a[j] < 0){
		b[k++] = a[j++];
	}
	while(i<=fe){
		b[k++] = a[i++];.
	}
	while(j<=se){
		b[k++] = a[j++];
	}
	for(int i = fs, k = 0;i<=se;i++){
		a[i] = b[k++];
	}
}
void merge(int a[], int low, int high){
	if(low<high){
		int mid = low + (high-low)/2;
		merge(a, low, mid);
		merge(a, mid+1, high);
		merging(a, low, mid, mid+1, high);
	}
}
int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i =0;i<n;i++){
		cin>>a[i];
	}
	merge(a, 0, n-1);
	for(int i = 0;i<n;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
}