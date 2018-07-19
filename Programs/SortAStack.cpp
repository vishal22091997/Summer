#include<iostream>
#include<stack>
using namespace std;
void sort(stack<int> &s, int n, int &max_val, bool &done_left){
	if(s.size() == n){
		return;
	}
	int val = s.top();s.pop();
	max_val = max(max_val, val);
	sort(s, n, max_val, done_left);
	if(val == max_val && done_left == false){
		done_left = true;
		return;
	}else{
		s.push(val);
		return;	
	}
	
}
void insert_at_bottom(stack<int> &s, int val){
	if(s.empty()){
		s.push(val);
		return;
	}else{
		int val2 = s.top();s.pop();
		insert_at_bottom(s, val);
		s.push(val2);
	}
}
void print(stack<int> s){
	if(s.empty()){
		return;
	}
	int val = s.top();s.pop();
	cout<<val<<endl;
	print(s);
	s.push(val);
}
int main(){
	int n;
	cout<<"Enter the number of elements in stack: ";
	cin>>n;
	stack<int> s;
	int x;
	for(int i = 0;i<n;i++){
		cin>>x;
		s.push(x);
	}
	for(int i = 0;i < n;i++){
		int max_val = 0;
		bool done_left = false;
		sort(s, i, max_val, done_left);
		insert_at_bottom(s, max_val);
	}
	print(s);
}
//6
//12 25 11 67 45 45