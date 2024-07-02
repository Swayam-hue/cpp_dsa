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

struct node* del_first(struct node* head){
    if (head == NULL)
        cout << "Linked List is already empty." << endl;
    else{
        struct node *temp = head;
        head = head -> link;
        free(temp);
        temp = NULL;
    }
    return head;
}

int main(){
    struct node *head = (struct node*)malloc(sizeof(struct node));
    head -> data = 45;
    head -> link = NULL;

    struct node *ptr = head;
    ptr = add_at_end(ptr, 78);
    ptr = add_at_end(ptr, 35);
    ptr = add_at_end(ptr, 3);

    head = del_first(head);

    ptr = head;
    while(ptr != NULL){
        cout << ptr -> data << " ";
        ptr = ptr -> link;
    }
    return 0;

}