#include <iostream>
#include <cstdlib>
using namespace std;

struct node{
    int data;
    struct node *link;
};

struct node* add_at_end(struct node *ptr, int data){
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp -> data = data;
    temp -> link = NULL;

    ptr -> link = temp;
    return temp;
}

struct node* del_at_end(struct node *head){
    if (head == NULL) //No node in the list
        return NULL;
    if (head -> link == NULL){ //Only one node in te list
        free(head);
        return NULL;
    }
    struct node *temp = head;

    while (temp -> link -> link != NULL){ //Muliple nodes in the list
        temp = temp -> link; //temp = Second last node
    }
    struct node *last_node = temp -> link;
    free(last_node);
    temp -> link = NULL;
    return head;
}

int main(){
    struct node *head = (struct node*)malloc(sizeof(struct node));
    head -> data = 39;
    head -> link = NULL;

    struct node *ptr = head;
    ptr = add_at_end(ptr, 78);
    ptr = add_at_end(ptr, 89);

    head = del_at_end(head);

    ptr = head;
    while (ptr != NULL){
        cout << ptr -> data << " ";
        ptr = ptr -> link;
    }
}