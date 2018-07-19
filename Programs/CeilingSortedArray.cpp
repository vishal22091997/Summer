#include<iostream>
#include<vector>
using namespace std;
int ceil_in_array(std::vector<int> v, int low, int high, int n){
	// we need to output the number which is equal or greater than the one which is given
	if(v[high] < n){
		return -1;
	}else if(v[low] >= n){
		return v[low];
	}else{
		int mid = low + (high - low)/2;
		if(v[mid] == n){
			return v[mid];
		}else if(v[mid] < n){
			if(mid + 1 <= high && v[mid+1] >= n){
				return v[mid + 1];
			}else{
				return ceil_in_array(v, mid+1, high, n);
			}
		}else{
			if(mid - 1 >= low && v[mid-1] > n){
				return v[mid-1];
			}else{
				return ceil_in_array(v, low, mid-1, n);
			}
		}
	}
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		std::vector<int> v(n);
		for(int i =0;i<n;i++){
			cin>>v[i];
		}
		// it is the sorted array which I will be getting.
		int x;
		
		while(true){
			cin>>x;
			cout<<ceil_in_array(v, 0, v.size()-1, x);	
		}
	}
}