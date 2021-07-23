/*思想: always insert/delete in one end of the linked list, 但是从tail插入或删除，时间复杂度为O(n)
但是堆栈的push pop的是O(1),因此选择从head插入/删除Node*/
#include <iostream>
using std::cout;
using std::endl;

struct Node
{
  int data;
  struct Node* link;
};

Node* top = NULL;       //最初stack为空

void Push(int x)
{
  Node* temp = new Node();
  temp->data = x;
  temp->link = top;     //先让temp指向原先的那个top
  top = temp;           //最后才改变top指针
  delete temp;          
}

void Pop()
{
  struct Node *temp;
  if (top == NULL) return;
  temp = top;           //temp相当于原头部节点的遥控器，temp指向原top
  top = top->link;
  free(temp);
}

bool isEmpty()
{
  return top == NULL;
}