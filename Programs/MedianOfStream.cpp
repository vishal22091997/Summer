#include<set>
#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	set<int> s;
	int x;
	for(int i = 1;i <= n;i++){
		cin>>x;
		s.insert(x);
		if(i%2==0){
			int first = i/2 - 1, second = (i/2);
			set<int> :: iterator it1 = s.begin() + first, it2 = s.begin() + second;
			int val = *(it1) + *(it2);
			cout<<(float)val/2.0<<endl;
		}else{
			int one = (i+1)/2 - 1;
			int val = *(s.begin()+one);
			cout<<val<<endl;
		}

	}
}