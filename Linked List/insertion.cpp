#include <iostream>
#include <cstdlib>
using namespace std;

struct node
{
    int data;
    struct node *link;
};

void count_of_nodes(struct node *head){
    int count = 0;
    if (head == NULL){
        cout << "Linked lIst is empty" << endl;
        exit(0);
    }
    struct node *ptr;
    ptr = head;
    while (ptr != NULL){
        count ++;
        ptr = ptr -> link;
    }
    cout << count;
}

void print_data(struct node *head){
    if (head == NULL){
        cout << "Linked list is empty." << endl;
        exit(0);
    }
    struct node *ptr = NULL;
    ptr = head;
    while (ptr != NULL){
        cout << ptr -> data << " ";
        ptr = ptr -> link;
    }
}

add_at_end(struct node *head, int data){
    struct node *ptr, *temp;
    ptr = head;
    temp = (struct node*)malloc(sizeof(struct node));
    temp -> data = data;
    temp -> link = NULL;

    while(ptr -> link != NULL){
        ptr = ptr -> link;
    }
    ptr -> link = temp;
}

int main(){
    struct node *head = (struct node*)malloc(sizeof(struct node)); //head = 1000 //1st node
    head -> data = 45;
    head -> link = NULL;

    add_at_end(head, 67);
    add_at_end(head, 90);
    add_at_end(head, 100);
    print_data(head);
}