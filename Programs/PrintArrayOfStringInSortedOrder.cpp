#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
struct Node{
	int num;
	int count;
	int pos;
};
bool comp(Node* a, Node* b){
	if(a->count > b->count){
		return true;
	}else if(b->count > a->count){
		return false;
	}else{
		if(a->pos < b->pos){
			return true;
		}else{
			return false;
		}
	}
}
int main(){
	int n;
	cin>>n;
	Node* a[n];
	for(int i = 0;i<n;i++){
		a[i] = new Node();
		int x;
		cin>>x;
		int count = 2;
		for(int j = 2;j<=sqrt(x);j++){
			cout<<j<<" ";
			if(x%j == 0){
				count++;
				if((x%(x/j) == 0 && (x/j) != j)){
					count++;
				}
			} 
		}
		a[i]->num = x;
		a[i]->count = count;
		a[i]->pos = i;
	}
	sort(a, a+n, comp);
	for(int i = 0;i<n;i++){
		cout<<a[i]->num<<" "<<a[i]->count<<" "<<a[i]->pos<<endl;
	}
}