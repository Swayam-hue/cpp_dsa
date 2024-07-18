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

struct node* del_at_posn(struct node *head, int pos){
    if (head == NULL){
        cout << "List is empty";
        exit(0);
    }
    
    struct node *ptr = head;

    if (pos == 1){
        head = ptr -> link;
        free(ptr);
        return head;
    }
    else{
        pos--;
        while (pos != 1){
            ptr = ptr -> link;
            pos--;
        }
        struct node *del_node = ptr -> link;
        ptr -> link = del_node -> link;
        free(del_node);
    }
    return head;
}

int main(){
    struct node *head = (struct node*)malloc(sizeof(struct node));
    head -> data = 45;
    head -> link = NULL;

    struct node *ptr = head;
    ptr = add_at_end(ptr, 67);
    ptr = add_at_end(ptr, 89);
    ptr = add_at_end(ptr, 90);
    ptr = add_at_end(ptr, 69);

    head = del_at_posn(head, 3);

    ptr = head;
    while (ptr != NULL){
        cout << ptr -> data << " ";
        ptr = ptr -> link;
    }
    return 0;
}