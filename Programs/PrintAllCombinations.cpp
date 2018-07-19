#include<iostream>
#include<vector>
using namespace std;
void printAllCombos(std::vector<int> v, int r, int i, vector<int> temp, vector<vector<int> > &ans){
	if(i > v.size() || temp.size() > r)
		return;
	if(temp.size() == r){
		ans.push_back(temp);
		return;
	}else{
		temp.push_back(v[i]);
		printAllCombos(v, r, i+1, temp, ans);
		temp.pop_back();
		printAllCombos(v, r, i+1, temp, ans);
	}
}
void print(std::vector<int> v){
	for(int i = 0;i<v.size();i++){
		cout<<v[i]<<" ";
	}
	cout<<endl;
}
int main(){
	int n, r;
	cin>>n>>r;
	vector<int> v(n);
	for(int i = 0;i<n;i++){
		cin>>v[i];
	}
	std::vector<int> temp;
	std::vector<std::vector<int> > ans;
	printAllCombos(v, r, 0, temp, ans);
	for(int i =0;i<ans.size();i++){
		print(ans[i]);
	}
}