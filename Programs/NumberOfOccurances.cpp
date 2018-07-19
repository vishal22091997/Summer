#include<iostream>
using namespace std;

int leftMost(int a[], int low, int high, int x){
    if(a[low] > x || a[high] < x){
        return -1;
    }if(a[low] == x){
        return low;
    }
    int mid = low + (high - low)/2;
    if(a[mid] == x){
        if(mid - 1 >= low && a[mid -1 ] != x){
            return mid;
        }
        return leftMost(a, low, mid-1, x);
    }else if(a[mid] > x){
        return leftMost(a, low, mid-1, x);
    }else{
        return leftMost(a, mid+1, high, x);
    }
}
int rightMost(int a[], int low, int high, int x){
	if(a[low] > x || a[high] < x){
		return -1;
	}else if(a[high] == x){
		return high;
	}else{
		int mid = low + (high-low)/2;
		if(a[mid] == x){
			if(mid+1 <=high && a[mid+1] != x){
				return mid;
			}
			return rightMost(a, mid+1, high, x);
		}else if(a[mid] > x){
			return rightMost(a, low, mid-1, x);
		}else{
			return rightMost(a, mid+1, high, x);
		}
	}
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n, x;
		cin>>n>>x;
		int a[n];
		for(int i = 0;i<n;i++){
			cin>>a[i];
		}
		int left_find = leftMost(a, 0, n-1, x);
		int right_find = rightMost(a, 0, n-1, x);
		if(left_find == -1 || right_find == -1){
			cout<<0<<endl;
		}else{
			cout<<right_find - left_find + 1<<endl;
		}
	}
}