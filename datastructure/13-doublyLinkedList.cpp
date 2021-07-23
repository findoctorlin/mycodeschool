#include <iostream>
#include <string>

struct Node
{
  int data;
  Node *next;
  Node *prev;
};

struct Node *head;
//(调用了heap区)
struct Node *get_new_node(int x)
{
  Node *new_node_pointer = new Node();
  new_node_pointer->data = x;
  new_node_pointer->prev = NULL;
  new_node_pointer->next = NULL;
  return new_node_pointer;
  delete new_node_pointer;         //不要忘记!
}
//返回Node的引用(局部变量法)
// struct Node *get_new_node(int x)
// {
//   Node newNode;
//   newNode.data = x;
//   newNode.prev = NULL;
//   newNode.next = NULL;
//   return &newNode;
// }

void insert_at_head(int x)
{
  struct Node *new_node = get_new_node(x);
  if (head == NULL)
  {
    head = new_node;
    return;
  }
  head->prev = new_node;
  new_node->next = head;
  head = new_node;
}

void insert_at_tail(int x)
{
  struct Node *new_node = get_new_node(x);

  struct Node *temp = head;
  while (temp->next != NULL)
  {
    temp = temp->next;
  }

  temp->next = new_node;
  new_node->prev = temp;
}

void print()
{
  struct Node *temp = head;
  printf("Forward: ");
  while (temp != NULL)
  {
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

void reverse_print()
{
  struct Node *temp = head;
  if (temp == NULL)
    return;

  while (temp->next != NULL)
  {
    temp = temp->next;
  }

  printf("Reverse: ");
  while (temp != NULL)
  {
    printf("%d ", temp->data);
    temp = temp->prev;
  }
  printf("\n");
}

int main(void)
{
  head = NULL;
  insert_at_head(2);
  print();
  reverse_print();
  insert_at_head(4);
  print();
  reverse_print();
  insert_at_tail(6);
  print();
  reverse_print();
  return 0;
}
