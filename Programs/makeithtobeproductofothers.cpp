#include<iostream>
#include<vector>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		// In this we are given N numbers for which we need to change them with the numbers which are equal to the product of remaining numbers.
		std::vector<int> v(n), left(n), right(n);
		for(int i=0;i<n;i++){
			cin>>v[i];
		}
		int left_prod = 1;
		for(int i =0;i<n;i++){
			left[i] = left_prod;
			left_prod *= v[i];
		}
		int right_prod = 1;
		for(int i =n-1;i>=0;i--){
			right[i] = right_prod;
			right_prod *= v[i];
		}
		for(int i=0;i<n;i++){
			v[i] = left[i] * right[i];
			cout<<v[i]<<" ";
		}
		cout<<endl;


	}
}