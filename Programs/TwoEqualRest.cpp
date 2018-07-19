#include<iostream>
#include<map>
using namespace std;
int main(){
	int n, sum = 0;
	cin>>n;
	int a[n];
	map<int, int> m;
	for(int i = 0;i<n;i++){
		cin>>a[i];
		m[a[i]] ++;
		sum += a[i];
	}
	for(int i = 0;i<n;i++){
		int req = (sum - 2*a[i]);
		if(req % 2 == 0){
			if(req/2 == a[i]){
				if(m[req] >= 2){
					cout<<a[i]<<" "<<req<<endl;
					break;
				}
			}else if(m.find(req)!=m.end()){
				cout<<a[i]<<" "<<req<<" ";
				break;
			}
		}
	}
	cout<<"Done ! ! !";
}