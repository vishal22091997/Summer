#include<iostream>
#include<vector>
#include<set>
#include<iterator>
using namespace std;
int number_of_inversions_using_set(vector<int> v){
	set<int> s;
	int inversions = 0;
	for(int i =0;i<v.size();i++){
		s.insert(v[i]);
		set<int> :: iterator it = s.find(v[i]); 
		inversions += distance(it ,s.end()) - 1;
	}
	return inversions;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int> v(n);
		for(int i = 0;i<n;i++){
			cin>>v[i];
		}
		cout<<number_of_inversions_using_set(v);
	}
}