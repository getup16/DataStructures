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
        cout<<"Destroying Node ; Data = "<<this->data<<"\n";
    }
};

//Singly Linked List
class SinglyLinkedList
{
private:
    //data members
    Node *head,*tail,*temp;
    int totalNodes;
public:
    //constructor
    SinglyLinkedList()
    {
        //initializing the head and tail pointers of Linked List to Null Pointer
        head = tail = temp = 0;
        totalNodes = 0;
    }
    //destructor
    ~SinglyLinkedList()
    {
        system("CLS");
        temp = head;
        Node *nextNodePtr;
        cout<<"Destroying The List\n";
        while(temp != 0)
        {
            nextNodePtr = temp->nextNode;
            delete temp;
            temp = nextNodePtr;
        }
        cout<<"\nDone.\n";
    }
    //member functions
    void insertAtEnd();
    void insertAtBegin();
    void insertAtLoc();
    void deleteAtEnd();
    void deleteAtBegin();
    void deleteAtLoc();
    void traverse();    //to display the list
    void search();
    int isEmpty();
    void reverse();
};


//isEmpty Function
int SinglyLinkedList :: isEmpty()
{
    if(totalNodes == 0)
    {
        return 0;
    }
    return totalNodes;
}

//search function
void SinglyLinkedList :: search()
{
    if(isEmpty())
    {
        //getting data value from User
        int query;
        int counter = 1;
        cout<<"Enter the data (*type - 'int') you want to Search : ";
        cin>>query;
        temp = head;
        while(temp != 0)
        {
            if(temp->data == query)
            {
                cout<<"Found @ Index - "<<counter<<"\n";
                return;
            }
            temp = temp->nextNode;
            counter++;
        }
        cout<<"Not Found\n";
    }
    else
    {
        cout<<"List Is Empty\n";
    }
    
}

//insert at beginnig
void SinglyLinkedList :: insertAtBegin()
{
    //creating a new Node Object
    temp = new Node();
    cout<<"Enter the Data of New Node : "; 
    cin>>temp->data;
    temp->nextNode = 0;
    if(head != 0)
    {
        temp->nextNode = head;
        head = temp;
    }
    else
    {
        head = tail = temp;
    }
    temp = 0;
    totalNodes++;
}

//insert at end
void SinglyLinkedList :: insertAtEnd()
{
    //creating a new Node Object
    temp = new Node();
    cout<<"Enter the Data of New Node : "; 
    cin>>temp->data;
    temp->nextNode = 0;
    if(head != 0)
    {
        tail->nextNode = temp;
        tail = temp;
    }
    else
    {
        head = tail = temp;
    }
    temp = 0;
    totalNodes++;
}

//insert a node at n-th position
void SinglyLinkedList :: insertAtLoc()
{
    //creating a new Node Object
    temp = new Node();
    cout<<"Enter the Data of New Node : "; 
    cin>>temp->data;
    temp->nextNode = 0;
    //taking location input
    int loc;
    cout<<"Enter Location : ";
    cin>>loc;
    if(loc < 0 || loc > totalNodes)
    {
        cout<<"Invalid Location\n";
    }
    else if(loc == 1)
    {
        temp->nextNode = head;
        head = temp;
        totalNodes++;
    }
    else
    {
        int counter = 1;
        Node *requiredNode = head;
        //traversing to the Node of given location
        while(counter != (loc-1))
        {
            requiredNode = requiredNode->nextNode;
            counter++;
        }
        //linking the "temp" Node in the linked list at the asked "loc"
        temp->nextNode = requiredNode->nextNode;
        requiredNode->nextNode = temp;
        totalNodes++;
    }
    temp = 0;
    
}

//delete at beginning
void SinglyLinkedList :: deleteAtBegin()
{
    if(totalNodes > 0)
    {
        temp = head;
        head = head->nextNode;
        delete temp;
        temp = 0;
        totalNodes--;
    }
    else
    {
        cout<<"Invalid\n";
    }
    
}

//delete at end
void SinglyLinkedList :: deleteAtEnd()
{
    if(totalNodes > 0)
    {
        if(head == tail)
        {
            delete head;
            head = tail = temp = 0;
            totalNodes--;
        }
        else
        {       
            temp = head;
            while (temp->nextNode != tail)
            {
                temp = temp->nextNode;
            }
            delete tail;
            temp->nextNode = 0;
            tail = temp;
            temp = 0;
            totalNodes--;
        }
    }
    else
    {
        cout<<"Invalid\n";
    }
    
}

//delete at location
void SinglyLinkedList :: deleteAtLoc()
{
    //taking location input
    int loc;
    cout<<"Enter the location you want to enter the Node : ";
    cin>>loc;
    if(loc < 0 || loc > totalNodes)
    {
        cout<<"Invalid Location\n";
    }
    else if(loc == 1)
    {
        temp = head;
        if(totalNodes == 1)
        {
            head = tail = 0;
        }
        else
        {
            head = head->nextNode;
        }
        delete temp;
        temp = 0;
        totalNodes--;
        
    }
    else
    {
        int counter = 1;
        Node *requiredNode = head;
        //traversing to the Node of given location
        while(counter != (loc-1))
        {
            requiredNode = requiredNode->nextNode;
            counter++;
        }
        temp = requiredNode->nextNode;
        requiredNode->nextNode = temp->nextNode;
        //checking if the entered location is a tail
        if(temp == tail)
        {
            tail = requiredNode;
            requiredNode->nextNode = 0;
        }
        delete temp;
        temp = 0;
        totalNodes--; 
    }
    
}

//traverse function
void SinglyLinkedList :: traverse()
{
    if(head == 0)
    {
        cout<<"EMPTY.\n";
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

//reverse the linked list
void SinglyLinkedList :: reverse()
{
    if (isEmpty())
    {
        temp = head;
        Node *previous = 0;
        Node *next = 0;
        while(temp != 0)
        {
            next = temp->nextNode;
            temp->nextNode = previous;
            previous = temp;
            temp = next;  
        }
        tail = head;
        head = previous;
        temp = 0;
    }
    else
    {
        cout<<"The List is EMPTY\n";
    }
    
}

int main()
{
    SinglyLinkedList* A = new SinglyLinkedList();
    char flag = 'y';
    int choice;
    //menu
    do{
        // system("CLS");
        cout<<setw(20)<<setfill(' ')<<"LINKED LIST\n";
        cout<<setw(30)<<setfill('-')<<"\n";
        cout<<"List -> ";A->traverse();
        cout<<setw(30)<<setfill('-')<<"\n";
        cout<<"1. Search \n"
            <<"2. Insert a Node at the Beginning\n"
            <<"3. Insert a Node at the End\n"
            <<"4. Insert a Node at a Certain Location\n"
            <<"5. Delete a Node at the Beginning\n"
            <<"6. Delete a Node at the End\n"
            <<"7. Delete a Node at a Certain Location\n"
            <<"8. Display Count\n"
            <<"9. Reverse Linked List\n"
            <<"10. Exit\n";
        //getting user input
        cout<<"Enter What you want to do ? : ";
        cin>>choice;
        //switch cases
        switch (choice)
        {
            case 1:
                A->search();
                break;
            case 2:
                A->insertAtBegin();
                break;
            case 3:
                A->insertAtEnd();
                break;
            case 4:
                A->insertAtLoc();
                break;
            case 5:
                A->deleteAtBegin();
                break;
            case 6:
                A->deleteAtEnd();
                break;
            case 7:
                A->deleteAtLoc();
                break;
            case 8:
                cout<<A->isEmpty()<<"\n";
                break;
            case 9:
                A->reverse();
                break;
            case 10:
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