#include <iostream>
#include <cstdlib>
using namespace std;

struct node{
    int data;
    struct node *link;
};

struct node* add_at_beginning(struct node* head, int data){
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp -> data = data;
    temp -> link = NULL;
    temp -> link = head;
    head = temp;
    return head;
}

int main(){
    struct node *head = (struct node*)malloc(sizeof(struct node));
    head -> data = 35;
    head -> link = NULL;

    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    ptr -> data = 45;
    ptr -> link = NULL;
    head -> link = ptr;
    int d = 3;
    head = add_at_beginning(head, d);
    ptr = head;
    while(ptr != NULL){
        cout << ptr -> data << " ";
        ptr = ptr -> link;
        }
}