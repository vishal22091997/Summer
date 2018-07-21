#include<iostream>
#include<map>
using namespace std;
struct Node{
	int data;
	Node* parent;
	int rank;
};
Node* makeSet(int data){
	Node* newNode = new Node();
	newNode->data = data;
	newNode->parent = newNode;
	newNode->rank = 0;
	return newNode;
}
Node* parent(Node* curNode){
	if(curNode->parent == curNode){
		return curNode;
	}
	curNode->parent = parent(curNode->parent);
	return curNode->parent;
}
void union_(map<int, Node*> m, int d1, int d2){
	Node* cur1 = parent(m[d1]);
	Node* cur2 = parent(m[d2]);
	if(cur1 == cur2){
		return; 
	}
	else{
		if(cur1->rank > cur2->rank){
			cur2->parent = cur1;
		}else if(cur1->rank < cur2->rank){
			cur1->parent = cur2;
		}else{
			cur1->rank = cur1->rank+1;
			cur2->parent = cur1;
		}
	}
}
int main(){
	int n = 10;
	map<int, Node*> m;
	for(int i = 0 ;i<10;i++){
		m[i] = makeSet(i);
	}
	union_(m, 0, 4);
	union_(m, 3, 5);
	union_(m, 0, 3);
	cout<<parent(m[0])->data<<endl;
	cout<<parent(m[4])->data<<endl;
	cout<<parent(m[3])->data<<endl;
	cout<<parent(m[5])->data<<endl;
	cout<<parent(m[0])->data<<endl;
	cout<<parent(m[4])->data<<endl;
	cout<<parent(m[3])->data<<endl;
	cout<<parent(m[5])->data<<endl;

}