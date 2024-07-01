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

void add_at_posn(struct node* head, int data, int pos){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp -> data = data;
    temp -> link = NULL;

    struct node* ptr = head;
    pos--;
    while(pos != 1){
        ptr = ptr -> link;
        pos--; 
    }

    temp -> link = ptr -> link;
    ptr -> link = temp;
}

int main(){
    struct node *head = (struct node*)malloc(sizeof(struct node));
    head -> data = 35;
    head -> link = NULL;
    struct node *ptr = head;
    ptr = add_at_end(ptr, 67);
    ptr = add_at_end(ptr, 90);
    ptr = add_at_end(ptr, 11);
    ptr = add_at_end(ptr, 38);
    ptr = add_at_end(ptr, 87);

    int d = 69, pos = 4;

    add_at_posn(head, d, pos);

    ptr = head;
    while(ptr != NULL){
        cout << ptr -> data << " ";
        ptr = ptr -> link;
    }
    return 0;
}