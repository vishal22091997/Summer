#include<bits/stdc++.h>
#define for0(x) for(int i=0;i<x;i++)
#define for1(x) for(int i=1;i<=x;i++)
using namespace std;
typedef long long int ll;
typedef map<int, int> mapii;
typedef map<char, int> mapci;
typedef map<string, int> mapsi;
typedef map<int, string> mapis;
typedef map<int, char> mapic;
int find(vector<int> a, int low, int high){
	if(low == high){
		return a[low];
	}
	int mid = low + (high-low)/2;
	if(mid + 1 <= high && mid - 1 >=  low){
		if(a[mid]>a[mid-1] && a[mid] > a[mid+1]){
			return a[mid];
		}else if(a[mid] > a[mid-1] && a[mid+1] > a[mid]){
			return find(a, mid+1, high);
		}else{
			return find(a, low, mid-1);
		}
	}else if(mid+1 <= high){
		if(a[mid] > a[mid+1]){
			return a[mid];
		}else{
			return a[mid+1];
		}
	}else if(mid - 1 >= low){
		if(a[mid] > a[mid-1]){
			return a[mid];
		}else{
			return a[mid-1];
		}
	}else{
		return a[mid];
	}
}
int main()
 {
	//code
        int t;
        cin>>t;
        while(t--){
        	int n;
        	cin>>n;
        	std::vector<int> v(n);
        	for(int i  =0 ;i<n;i++){
        		cin>>v[i];
        	}
        	int val = find(v, 0, n-1);
        	cout<<val<<endl;
        }
	return 0;
}