#include <stdio.h>
#include <stdlib.h>

#define debug(expr) printf(#expr " = %d\n", expr)

// node
typedef struct node{
  int val;
  struct node * next;
}node_t;

// print all
void print_list(node_t * head){
  while(head!=NULL){
    printf("%d\n", head->val);
    head = head->next;
  }
}

// add node to the end of list
void insert_node_last(node_t * head, int val){
  node_t * p = head;
  while(p->next != NULL){
    p = p->next;
  }

  p->next = (node_t*)malloc(sizeof(node_t));
  p->next->next = NULL;
  p->next->val = val;
}

// add node at the start of the list
void add_first(node_t ** head, int val){
  node_t * p;
  p = (node_t*)malloc(sizeof(node_t));
  p -> val = val;
  p -> next = * head;
  *head = p;
}

// insert node at the particular position
int insert_node(node_t ** head, int pos, int val){
  if(pos == 0){
    add_first(*head, val);
    return 1;
  }

  node_t * p = *head;
  node_t * q = *head;

  for(int i = 0; i < pos; i++){
    if(p==NULL){
      return 0;
    }
    p = p->next;
  }

  q = (node_t*)malloc(sizeof(node_t));
  q -> val = val;
  q -> next = p->next;
  p -> next = q;
  return 1;
}

// delete fisrt node
int pop_first(node_t **head){
  node_t * p = NULL;
  int pop = 0;

  if(*head == NULL){
    return -1;
  }

  if((*head)->next==NULL){
    free(*head);
    *head = NULL;
  }

  p = (*head)->next;
  pop = (*head)->val;
  free(*head);
  *head = p;

  return pop;
}

// delete particular node
int delete_node(node_t **head, int val){
  int pop = -1;
  node_t * p = *head;
  node_t * q = NULL;

  if ((*head)->next == NULL) {
    pop_first(*head);
  }

  while (p -> next -> val != val) {
    if (p == NULL) return pop;
    p = p -> next;
  }

  q = p -> next -> next;
  pop = p -> next -> val;
  free(p -> next);
  p -> next = q;
  return pop;

}


int main(){
  // init linked list
  node_t * head = NULL;
  head = (node_t*)malloc(sizeof(node_t));
  head ->next = NULL;
  head->val = 23;
  insert_node_last(head, 293);
  insert_node(&head, 1, 37434);
  insert_node(&head, 1, 3);
  delete_node(&head, 3);
  insert_node(&head, 2, 2132);
  print_list(head);

}
