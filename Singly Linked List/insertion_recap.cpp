#include <bits\stdc++.h>
using namespace std;
struct Node
{
    char data;
    Node *next;
};
Node *start = NULL;

void traverse()
{
    Node *ptr = start;
    while (ptr != NULL)
    {
        cout << (*ptr).data << " ";
        ptr = (*ptr).next;
    }
    cout << endl;
}

void insert_at_beg()
{
    Node *newnode = new Node;
    if (newnode == NULL)
    {
        exit(1);
    }
    else
    {
        cin >> (*newnode).data;
        (*newnode).next = NULL;
        (*newnode).next = start;
        start = newnode;
    }
}

void insert_at_end()
{
    Node *newnode = new Node;
    if (newnode == NULL)
    {
        exit(1);
    }
    cin >> (*newnode).data;
    (*newnode).next = NULL;

    Node *ptr = start;
    while ((*ptr).next != NULL)
    {
        ptr = (*ptr).next;
    }
    (*ptr).next = newnode;
}

void insert_at_pos()
{
    char ch;
    cin >> ch;
    Node *newnode = new Node;
    if (newnode == NULL)
    {
        exit(1);
    }

    cin >> (*newnode).data;
    (*newnode).next = NULL;
    Node *ptr=start;
    while((*ptr).data !=ch){
        ptr = (*ptr).next;
    }
    (*newnode).next=(*ptr).next;
    (*ptr).next=newnode;
}

void insert_in_sort(){
    char ch;
    cin>>ch;
    Node *newnode = new Node;
    if (newnode == NULL)
        exit(1);
    newnode->data = ch;
    newnode->next = NULL;
    Node *ptr = start;
    Node *save;
    while((*ptr).data<ch){
        save=ptr;
        ptr=(*ptr).next;
    }
    (*newnode).next=(*save).next;
    (*save).next=newnode;
}

int main()
{
    int n;
    cin>>n;
    Node *save;
    for(int i=1;i<=n;i++){
        Node *newnode = new Node;
        cin >> (*newnode).data;
        (*newnode).next = NULL;
        if(i==1)start=newnode;
        else{
            (*save).next=newnode;
        }
        save=newnode;
    }
    traverse();
    insert_at_beg();
    traverse();
    insert_at_end();
    traverse();
    insert_at_pos();
    traverse();
    insert_in_sort();
    traverse();
}