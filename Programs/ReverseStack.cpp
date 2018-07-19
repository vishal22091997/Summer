#include<iostream>
#include<stack>
using namespace std;
void insert_at_bottom(stack<int> &s, int val){
	if(s.empty()){
		s.push(val);
		return;
	}
	int val2 = s.top();s.pop();
	insert_at_bottom(s, val);
	s.push(val2);
}
void reverse(stack<int> &s){
	if(s.empty()) return;
	else{
		int val = s.top();s.pop();
		reverse(s);
		insert_at_bottom(s, val);
	}
}
void print(stack<int> s){
	if(!s.empty()){
		int val = s.top();s.pop();
		print(s);
		cout<<val<<" ";
		s.push(val);
	}
}
int main(){
	int n ;
	cout<<"Enter the number of Elements: ";
	cin>>n;
	stack<int> s;
	int x;
	for(int i =0;i<n;i++){
		cin>>x;
		s.push(x);
	}
	print(s);
	cout<<endl;
	reverse(s);
	print(s);
	cout<<endl;
}