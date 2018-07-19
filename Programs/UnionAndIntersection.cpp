#include<iostream>
using namespace std;
vector<int> union_of_vectors(vector<int> a, vector<int> b){
	int i = 0, j = 0;
	vector<int> ans;
	while(i < a.size() && j < b.size()){
		if(a[i] < b[j]){
			ans.push_back(a[i]);
			i++;
		}else if(a[i] > b[j]){
			ans.push_back(b[j]);
			j++;
		}else{
			ans.push_back(a[i]);
			i++;j++;
		}
	}
	while(i < a.size()){
		ans.push_back(a[i]);
		i++;
	}
	while(j < b.size()){
		ans.push_back(b[j]);
		j++;
	}
	return ans;
}
vector<int> intersection_of_vectir(vector<int> a, vector<int> b){
	int i = 0, j = 0;
	vector<int> ans;
	while(i < a.size() && j < b.size()){
		if(a[i] > b[j]){
			j++;
		}else if(a[i] < b[j]){
			i++;
		}else{
			ans.push_back(a[i]);
			i++;j++;
		}
	}
	return ans;
}
int main(){
	
}