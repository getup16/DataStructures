#include <iostream>
#include <iomanip>
using namespace std;

//Node Class
class Node
{
public:
    //data members
    int data;
    Node *nextNode;
    Node *prevNode;
    //constructor
    Node(int data = 0, Node *nextNode = 0, Node *prevNode = 0)
    {
        this->data = data;
        this->nextNode = nextNode;
        this->prevNode = prevNode;
    }
    //destructor
    ~Node()
    {
        cout<<"Destroying Node ; Data = "<<this->data<<"\n";
    }
};


//Doubly Linked List Class
class DoublyLinkedList
{
private:
    //data members
    Node *head,*tail,*temp;
    int totalNodes;
public:
    //constructor
    DoublyLinkedList()
    {
        tail = head = temp = 0;
        totalNodes = 0;
    }
    //desctructor
    ~DoublyLinkedList()
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
    int isEmpty();
    void insertAtBegin();
    void insertAtEnd();
    void insertAtLoc();
    void deleteAtBegin();
    void deleteAtEnd();
    void deleteAtLoc();
    void traverse();    //to display the list
    void search();
    void reverse();
};

//isEmpty() function
int DoublyLinkedList :: isEmpty()
{
    if(totalNodes)
    {
        return totalNodes;
    }
    return 0;
}

//insert at the begin
void DoublyLinkedList :: insertAtBegin()
{
    //taking input from User
    temp = new Node();
    cout<<"Enter the Data : ";
    cin>>temp->data;
    //checking if the list is Empty or not and Adding a Node Object accordingly
    if(head != 0)
    {
        head->prevNode = temp;
        temp->nextNode = head;
        head = temp;
    }
    else
    {
        head = tail = temp;
    }   
    totalNodes++;
    temp = 0;
}

//insert at the end
void DoublyLinkedList ::insertAtEnd()
{
    //taking input from User
    temp = new Node();
    cout<<"Enter the Data : ";
    cin>>temp->data;
    //checking if the list is Empty or not and Adding a Node Object accordingly
    if(head != 0)
    {
        tail->nextNode = temp;
        temp->prevNode = tail;
        tail = temp;
    }
    else
    {
        head = tail = temp;
    }
    totalNodes++;
    temp = 0;

}

//insert at n-th location
void DoublyLinkedList :: insertAtLoc()
{
    //taking input from User
    temp = new Node();
    cout<<"Enter the Data : ";
    cin>>temp->data;
    //asking user for Loaction or Index they want to insert Node
    int loc;
    cout<<"Enter Location : "; cin>>loc;
    if(loc < 0 || loc > totalNodes)
    {
        cout<<"Invalid Location\n";
    }
    else if(loc == 1)
    {
        head->prevNode = temp;
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
        temp->prevNode = requiredNode;
        requiredNode->nextNode->prevNode = temp;
        requiredNode->nextNode = temp;
        totalNodes++;
    }
    temp = 0;
}

//delete at the beginning
void DoublyLinkedList :: deleteAtBegin()
{
    if(isEmpty())
    {
        temp = head;
        head = head->nextNode;
        head->prevNode = 0;
        delete temp;
        temp = 0;
    }
    else
    {
        cout<<"Invalid\n";
    }
}

//delete at the end
void DoublyLinkedList :: deleteAtEnd()
{
    if(isEmpty())
    {
        if(head == tail)
        {
            delete head;
            head = tail = temp = 0;
        }
        else
        {
            temp = tail;
            tail = tail->prevNode;
            tail->nextNode = 0;
            delete temp;
            temp = 0;
        }
        totalNodes--;
    }
    else
    {
        cout<<"Invalid\n";
    }

}

//delete at n-th location
void DoublyLinkedList :: deleteAtLoc()
{
    //asking user for Loaction or Index they want to insert Node
    int loc;
    cout<<"Enter Location : "; cin>>loc;
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
            head->prevNode = 0;
        }
        delete temp;
        temp = 0;
        totalNodes--;
        
    }
    else
    {
        int counter = 1;
        temp = head;
        while (counter != loc)
        {
            temp = temp->nextNode;
            counter++;
        }
        //checking if the entered location is a tail
        if(temp == tail)
        {
            tail = temp->prevNode;
            tail->nextNode = 0;
        }
        else
        {
            temp->prevNode->nextNode = temp->nextNode;
            temp->nextNode->prevNode = temp->prevNode;
        }
        delete temp;
        temp = 0;
        totalNodes--;
        
    }
}

//traverse function
void DoublyLinkedList :: traverse()
{
    if(head != 0)
    {
        temp = head;
        while(temp != 0)
        {
            cout<<temp->data<<" ";
            temp = temp->nextNode;
        }
        temp = 0;
        cout<<"\n";
    }
    else
    {
        cout<<"EMPTY\n";
    }   
}

//search function
void DoublyLinkedList :: search()
{
    if(isEmpty())
    {
        //query from user
        int query;
        cout<<"Enter the Element You want to Search"; cin>>query;
        temp = head;
        int counter = 1;
        while(temp != 0)
        {
            if(temp->data == query)
            {
                cout<<"Found at Index : "<<counter<<"\n";
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

//reverse function
void DoublyLinkedList :: reverse()
{
    if(isEmpty())
    {
        temp = head;
        Node *next = 0; //node to store next Node pointer
        while(temp != 0)
        {
            next = temp->nextNode;
            temp->nextNode = temp->prevNode;
            temp->prevNode = next;
            temp = next;
        }
        temp = tail;
        tail = head;
        head = temp;
        temp = 0;
    }
    else
    {
        cout<<"The List is EMPTY\n";
    }
     
}


int main()
{
    DoublyLinkedList* A = new DoublyLinkedList();
    char flag = 'y';
    int choice;
    //menu
    do{
        // system("CLS");
        cout<<setw(20)<<setfill(' ')<<"DOUBLY LINKED LIST\n";
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
    return 0;
}