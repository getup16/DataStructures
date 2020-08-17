#include <iostream>
#include <iomanip>
using namespace std;

//Node class
class Node
{
public:
    //data members
    int data;
    Node* nextNode;
    Node* prevNode;
    //constructor
    Node(int data = 0, Node* nextNode = 0, Node* prevNode = 0)
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

//Circular Doubly Linked List Class
class CirDoublyLinkedList
{
private:
    int totalNodes;
    Node *head,*temp;
public:
    //constructor
    CirDoublyLinkedList()
    {
        totalNodes = 0;
        head = temp = 0;
    }
    //destructor
    ~CirDoublyLinkedList()
    {
        system("CLS");
        temp = head;
        Node *nextNodePtr;
        cout<<"Destroying The List\n";
        while(temp->nextNode != head)
        {
            nextNodePtr = temp->nextNode;
            delete temp;
            temp = nextNodePtr;
        }
        delete temp;
        cout<<"\nDone.\n";
    }

    //member functions
    void search();
    void insertAtBegin();
    void insertAtEnd();
    void insertAtLoc();
    void deleteAtBegin();
    void deleteAtEnd();
    void deleteAtLoc();
    void traverse();
    int isEmpty();
};

//search function
void CirDoublyLinkedList :: search()
{
    if(isEmpty())
    {
        //taking input from user
        int query = 0;
        cout<<"Enter the data (*type - 'int') you want to Search : "; cin>>query;
        //searching for the element
        temp = head;
        int counter = 1;
        do
        {
            if(temp->data == query)
            {
                cout<<"Data found @ "<<counter<<" index\n";
                return;
            }
            temp = temp->nextNode;
            counter++;
        }while (temp != head);
        cout<<"Data not found :/ \n";
    }
    else
    {
        cout<<"List is Empty\n";
    }
}

//insert the Node at the beginning of the List
void CirDoublyLinkedList :: insertAtBegin()
{
    //taking input from the user
    temp = new Node();
    cout<<"Enter the Data of New Node : ";
    cin>>temp->data;
    //inserting the node
    if(head == 0)
    {
        head = temp;
        head->nextNode = head;
        head->prevNode = head;
        temp = 0;
    }
    else
    {
        temp->nextNode = head;
        temp->prevNode = head->prevNode;
        head->prevNode->nextNode = temp;
        head = temp;
        temp = 0;
    }
    totalNodes++;
    
}

//insert the node at the end of the List
void CirDoublyLinkedList :: insertAtEnd()
{
    //taking input from the user
    temp = new Node();
    cout<<"Enter the Data of New Node : ";
    cin>>temp->data;
    //inserting the node
    if(head == 0)
    {
        head = temp;
        head->nextNode = head;
        head->prevNode = head;
        temp = 0;
    }
    else
    {
        temp->nextNode = head;
        temp->prevNode = head->prevNode;
        head->prevNode->nextNode = temp;
        head->prevNode = temp;
        temp = 0;
    }
    totalNodes++;
}
//inserting a Node at the n-th position in List
void CirDoublyLinkedList :: insertAtLoc()
{
    //taking input from the user
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
    else
    {
        if(loc == 1)
        {
            temp->nextNode = head;
            temp->prevNode = head->prevNode;
            head->prevNode->nextNode = temp;
            head = temp;
            temp = 0;  
        }
        else
        {
            int counter = 1;
            Node* requiredNode = head;
            while(counter != (loc-1))
            {
                temp = temp->nextNode;
                counter++;
            }
            temp->nextNode = requiredNode->nextNode;
            temp->prevNode = requiredNode;
            requiredNode->nextNode->prevNode = temp;
            requiredNode->nextNode = temp;
        }
        totalNodes++;
    }
}

//delete at the beginning of list
void CirDoublyLinkedList :: deleteAtBegin()
{
    if(totalNodes > 0)
    {
        if(totalNodes == 1)
        {
            temp = head;
            delete temp;
            head = temp = 0;
        }
        else
        {
            temp = head;
            temp->nextNode->prevNode = temp->prevNode;
            temp->prevNode->nextNode = temp->nextNode;
            head = head->nextNode;
            delete temp;
            temp = 0;
        }
        totalNodes--;
        
    }
    else
    {
        cout<<"The List is Empty\n";
    }
    
}

//delete a node at the end of the list 
void CirDoublyLinkedList :: deleteAtEnd()
{
    if(totalNodes > 0)
    {
        if(totalNodes == 1)
        {
            temp = head;
            delete temp;
            head = temp = 0;
        }
        else
        {
            temp = head->prevNode;
            temp->nextNode->prevNode = temp->prevNode;
            temp->prevNode->nextNode = temp->nextNode; 
            delete temp;
            temp = 0;
        }
        totalNodes--;
    }    
    else
    {
        cout<<"List is Empty\n";
    }
    
}

//delete a node at the n-th location
void CirDoublyLinkedList :: deleteAtLoc()
{
    //taking location input
    int loc;
    cout<<"Enter Location : ";
    cin>>loc;
    if(loc < 0 || loc > totalNodes)
    {
        cout<<"Invalid Location\n";
    }
    else
    {
        if(loc == 1)
        {
            temp = head;
            if(totalNodes == 1)
            {
                head = 0;
            }
            else
            {
                temp->nextNode->prevNode = temp->prevNode;
                temp->prevNode->nextNode = temp->nextNode;
                head = head->nextNode;
            }
            delete temp;
            temp = 0;
        }
        else
        {
            int counter = 1;
            temp = head;
            while(counter != loc)
            {
                temp = temp->nextNode;
                counter++;
            }
            temp->prevNode->nextNode = temp->nextNode;
            temp->nextNode->prevNode = temp->prevNode;
            if(temp->nextNode == head)
            {
                head->prevNode = temp->prevNode;
            }
            delete temp;
            temp = 0;
        }
        totalNodes--;
    }
    
}

//traverse function
void CirDoublyLinkedList :: traverse()
{
    if(head == 0)
    {
        cout<<"List is Empty\n";
    }
    else
    {
        temp = head;
        do
        {
            cout<<temp->data<<" ";
            temp = temp->nextNode;
        }
        while(temp != head);
        cout<<"\n";
        temp = 0;
    }
}

//isEmpty() function
int CirDoublyLinkedList :: isEmpty()
{
    if(totalNodes)
    {
        return totalNodes;
    }
    return 0;
}



int main()
{
    CirDoublyLinkedList* A = new CirDoublyLinkedList();
    char flag = 'y';
    int choice;
    //menu
    do{
        // system("CLS");
        cout<<setw(20)<<setfill(' ')<<"CIRCULAR DOUBLY LINKED LIST\n";
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
            <<"9. Exit\n";
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