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
int main(){
    struct node *head = (struct node*)malloc(sizeof(struct node)); //head = 1000 //1st node
    head -> data = 45;
    head -> link = NULL;

    struct node *current = (struct node*)malloc(sizeof(struct node)); //current = 2000 //2nd node
    current -> data = 98;
    current -> link = NULL;
    head -> link = current; //head - link = current = 2000

    current  = (struct node*)malloc(sizeof(struct node)); //current = 3000 //3rd node
    current -> data = 3;
    current -> link = NULL;
    head -> link -> link = current; //2nd node link = 3000

    current = (struct node*)malloc(sizeof(struct node));//4th node
    current -> data = 67;
    current -> link = NULL;
    head -> link -> link -> link = current;

    cout << "The number of nodes is : ";
    count_of_nodes(head);
    cout << endl;
    cout << "The data of the linked list are : ";
    print_data(head);
}
