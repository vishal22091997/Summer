#include<iostream>
#include<vector>
using namespace std;
void merge(vector<int> &a, int low, int mid, int high, int &inversions){
	vector<int> ans(high - low + 1);
	int i = 0, j = mid+1, k = 0;
	while(i<=mid && j<=high){
		if(a[i] < a[j]){
			ans[k++] = a[i];
			i++;
		}else if(a[i] > a[j]){
			ans[k++] = a[j];
			inversions += (mid + 1 - i);
			j++;
		}else{
			ans[k++] = a[i];
			i++;j++;
		}
	}
}
void merge_sort(vector<int> &a, int low, int high, int &inversions){
	if(low <= high){
		int mid = low + (high - low)/2;
		merge_sort(a, low, mid, inversions);
		merge_sort(a, mid+1, high, inversions);
		merge(a, low, mid, high, inversions);
	}
}
int main(){
	int n;
	cin>>n;
	std::vector<int > v(n);
	for(int i = 0;i<n;i++){
		cin>>v[i];
	}

	int inversions = 0;
	merge_sort(v, 0, v.size()-1, inversions);
	for(int i=0;i<v.size();i++){
		cout<<v[i]<<" "; 
	}
	cout<<endl;
	cout<<"Inversions are: "<<inversions<<endl;

}