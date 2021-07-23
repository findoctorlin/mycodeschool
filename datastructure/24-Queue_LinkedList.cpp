/*Queue - Linked List implementation*/
/* Deque????*/
#include<iostream>
using namespace std;

struct Node {
	int data;
	Node* next;
};
// Two glboal variables to store address of front and rear nodes. 使用智能指针防止内存泄漏
Node* front = NULL;
Node* rear = NULL;

// To Enqueue an integer
void Enqueue(int x) {
	Node* temp = new Node();
	temp->data =x; 
	temp->next = NULL;
	if(front == NULL && rear == NULL){
		front = rear = temp;
		return;
	}
	rear->next = temp;
	rear = temp;
    delete temp;
    temp = NULL;
}

// To Dequeue an integer.
void Dequeue() {
    Node* temp = front;
	if(front == NULL) {
		cout << "Queue is Empty" << endl;
		return;
	}
	if(front == rear) {
		front = rear = NULL;
	}
	else {
		temp = temp->next;
	}
    front = temp;
    delete temp;
    temp = NULL;
}

int Front() {
	if(front == NULL) {
		printf("Queue is empty\n");
		return 1;
	}
	return front->data;
}

void Print() {
    Node* temp = front;
    temp = front;
	while(temp != NULL) {
		printf("%d ",temp->data);
		temp = temp->next;
	}
	printf("\n");
    delete temp;
    temp = NULL;
}

int main(){
	/* Drive code to test the implementation. */
	// Printing elements in Queue after each Enqueue or Dequeue 
	Enqueue(2); Print(); 
	Enqueue(4); Print();
	Enqueue(6); Print();
	Dequeue();  Print();
	Enqueue(8); Print();
}