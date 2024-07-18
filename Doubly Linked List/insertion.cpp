#include <iostream>
#include <cstdlib>
using namespace std;

struct node{
    int data;
    struct node *next;
    struct node *prev;
};

struct node* add_to_empty(int data, struct node *head){
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp -> prev = NULL;
    temp -> data = data;
    temp -> next = NULL;
    head = temp;

    return head;
}

struct node* add_at_begin(int data, struct node *head){
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp -> prev = NULL;
    temp -> data = data;
    temp -> next = NULL;

    temp -> next = head;
    head -> prev = temp;
    head = temp;

    return head;
}

struct node *add_at_end(int data, struct node *head){
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp -> prev = NULL;
    temp -> data = data;
    temp -> next = NULL;

    struct node *tp = head;
    while(tp -> next != NULL)
        tp = tp -> next;
    
    tp -> next = temp;
    temp -> prev = tp;
    return head;
}

struct node *add_after_posn(int data, int posn, struct node *head){
    if (head == NULL || posn < 1){
        cout << "Invalid position.\n";
        return head;
    }
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp -> prev = NULL;
    temp -> data = data;
    temp -> next = NULL;

    struct node *temp1 = head;
    while(posn != 1){
        temp1 = temp1 -> next;
        posn --;
    }
    
    temp -> prev = temp1;
    temp -> next = temp1 -> next;
    temp1 -> next -> prev = temp;
    temp1 -> next = temp;

    return head;
}

int main(){
    struct node *head = (struct node*)malloc(sizeof(struct node));
    struct node *ptr = NULL;
    head = add_to_empty(45, head);
    head = add_at_begin(55, head);
    head = add_at_begin(89, head);
    head = add_at_end(90, head);
    head = add_after_posn(76, 2, head);
    
    ptr = head;
    while(ptr != NULL){
        cout << ptr -> data << " ";
        ptr = ptr -> next;
    }
}