#include <iostream>
#include <iomanip>
#include <stdlib.h>
using namespace std;

//Node Class
class Node
{
public:
    //data members
    int data;
    Node *nextNode;
    //constructor
    Node(int data = 0, Node *nextNode = 0)
    {
        this->data = data;
        this->nextNode = nextNode;
    }
    //destructor
    ~Node()
    {
        cout<<"\nDestroying Node ; Data = "<<this->data;
        this->nextNode = 0;
    }
};

//Singly Linked List
class SinglyLinkedList
{
private:
    //data members
    Node *head,*tail,*temp;
public:
    //constructor
    SinglyLinkedList()
    {
        //initializing the head and tail pointers of Linked List to Null Pointer
        head = tail = 0;
    }
    //destructor
    ~SinglyLinkedList()
    {
        system("CLS");
        temp = head;
        Node *nextNodePtr;
        cout<<"Destroying The List";
        while(temp != 0)
        {
            nextNodePtr = temp->nextNode;
            delete temp;
            temp = nextNodePtr;
        }
        cout<<"\nDone.\n";
    }
    //member functions
    void create();
    void insertAtEnd();
    void insertAtBegin();
    void insertAtLoc();
    void deleteAtEnd();
    void deleteAtBegin();
    void deleteAtLoc();
    void traverse();    //to print the output
};

//create function
void SinglyLinkedList :: create()
{
    char flag = 'y';
    do
    {
        //creating the temp Node object
        temp = new Node();
        cout<<"Enter the Data of New Node : "; 
        cin>>temp->data;
        temp->nextNode = 0;
        //adding the new Node accordingly
        if(head == 0)
        {
            head = tail = temp;
        }
        else
        {
            tail->nextNode = temp;
            tail = temp;        
        }
        temp = 0;
        
        //asking user if they want to add more Nodes
        cout<<"Do you want to add more Nodes?  (y/n): ";
        cin>>flag;

    } while (flag == 'y');

}

//traverse function
void SinglyLinkedList :: traverse()
{
    if(head == 0)
    {
        cout<<"List is EMPTY.\n";
    }
    else
    {
        temp = head;
        while(temp != 0)
        {
            cout<<temp->data<<" ";
            temp = temp->nextNode;
        }
        cout<<"\n";
        temp = 0;
    }
    
}


int main()
{
    SinglyLinkedList* A = new SinglyLinkedList();
    char flag = 'y';
    int choice;
    //menu
    do{
        system("CLS");
        cout<<setw(20)<<setfill(' ')<<"LINKED LIST\n";
        cout<<setw(30)<<setfill('-')<<"\n";
        cout<<"Linked List -> ";A->traverse();
        cout<<setw(30)<<setfill('-')<<"\n";
        cout<<"1. Create \n"
            <<"2. Insert a Node at the Beginning\n"
            <<"3. Insert a Node at the End\n"
            <<"4. Insert a Node at a Certain Location\n"
            <<"5. Delete a Node at the Beginning\n"
            <<"6. Delete a Node at the End\n"
            <<"7. Delete a Node at a Certain Location\n"
            <<"8.Exit\n";
        //getting user input
        cout<<"Enter What you want to do ? : ";
        cin>>choice;
        //switch cases
        switch (choice)
        {
            case 1:
                A->create();
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
            case 8:
                flag = 'n';
                break;
            default:
                break;
        }
    }
    while(flag == 'y');
    delete A;
    return 0;
}