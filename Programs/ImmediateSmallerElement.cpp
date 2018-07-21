
#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n];
		for(int i = 0 ;i<n;i++){
			cin>>a[i];
		}
		set<int> s;
		for(int i = 0;i<n;i++){
			s.insert(a[i]);
			int val = distance(s.find(a[i]), s.begin()) - 1;
			set<int> :: iterator it = s.begin();
			it += val;
			cout<<*(it)<<" ";
		}
		cout<<endl;
	}
}