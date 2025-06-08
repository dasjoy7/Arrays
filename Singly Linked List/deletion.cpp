#include <iostream>
using namespace std;

// Structure creation for Linked list
struct Node
{
    char data;
    Node *next;
};
Node *start = NULL;

// Traversing
void traverse()
{
    Node *ptr = start;
    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;
}

void delete_from_beg(){
    Node *temp =start;
    start = (*start).next;
    delete temp;
}

void delete_from_end(){
    Node *ptr = start;
    Node *save;
    while((*ptr).next !=NULL){
        save = ptr;
        ptr = (*ptr).next;
    }
    delete ptr;
    (*save).next= NULL;
}

void delete_from_any_pos(char ch){
    Node *ptr =start;
    Node *save;
    while((*ptr).data!=ch){
        save = ptr;
        ptr = (*ptr).next;
    }
    (*save).next = (*ptr).next;
    delete ptr;
}

// Main function
int main()
{
    int n;
    cin >> n;
    Node *save;
    for (int i = 1; i <= n; ++i)
    {
        Node *newnode = new Node;
        cin >> newnode->data;
        newnode->next = NULL;
        if (i == 1)
        {
            start = newnode;
        }
        else
        {
            save->next = newnode;
        }
        save = newnode;
    }
    traverse();
    delete_from_beg();
    traverse();
    delete_from_end();
    traverse();
    delete_from_any_pos('C');
    traverse();
}