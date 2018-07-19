#include<iostream>
using namespace std;
int find(int a[], int low, int high){
	if(low > high){
		return -1;
	}
	if(a[low] == low) { return low;}
	else if(a[high] == high) return high;
	int mid = low + (high-low)/2;
	if(a[mid] == mid) return mid;
	else if(a[mid] > mid){
		return find(a, low, mid -1);
	}else{
		return find(a, mid+1, high);
	}
}
int main(){
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i = 0 ;i<n;i++){
		cin>>a[i];
	}
	int low = 0, high = n-1;

}