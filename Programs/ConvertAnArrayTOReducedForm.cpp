#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class compare{
public:
	bool operator()(pair<int, int> a, pair<int, int> b){
		return a.first < b.first;
	}
};
int main(){
	int n;
	cin>>n;
	vector<pair<int, int> > v(n);
	int a[n];
	for(int i = 0;i<n;i++){
		cin>>a[i];
	}
	for(int i = 0;i<n;i++){
		v[i] = make_pair(a[i], i);
	}
	sort(v.begin(), v.end(), compare());
	for(int i = 0;i<n;i++){
		a[i] = v[i].second;
	}
	for(int i = 0;i<n;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
}