#include<bits/stdc++.h>
using namespace std;
void find(vector<int> v, int vSum, int leftSum, vector<int> temp, vector<int> &ans, int n, int &minDiff, int i){
	if(i >= n){
		return;
	}
	if(temp.size() == n/2){
		int tentDiff = abs(leftSum - vSum);
		if(minDiff > tentDiff){
			minDiff = tentDiff;
			ans = temp;
		}
		return;
	}else{
		temp.push_back(v[i]);
		find(v, vSum + v[i], leftSum - v[i], temp, ans, n, minDiff, i+1);
		temp.pop_back();
		find(v, vSum, leftSum, temp, ans, n, minDiff, i+1);
	}
}
int main(){
	int n;
	cin>>n;
	vector<int> v(n);
	int sum = 0;
	for(int i = 0;i<n;i++){
		cin>>v[i];
		sum += v[i];
	}
	vector<int> temp;
	vector<int> ans;
	int min_val = INT_MAX;
	find(v, 0, sum, temp, ans, n, min_val, 0);	
	for(int i = 0;i<ans.size();i++){
		cout<<ans[i]<<" ";
	}
	cout<<endl;
}