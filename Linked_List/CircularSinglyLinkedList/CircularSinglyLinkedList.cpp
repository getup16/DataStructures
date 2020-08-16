#include <iostream>
#include <iomanip>
using namespace std;

//Node Class
class Node
{
public:
    //data memebers
    int data;
    Node* nextNode;
    //constructor
    Node(int data = 0, Node* nextNode = 0)
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

//Circular Singly Linked List
class CirSinglyLinkedList
{
private:
    int totalNodes;
    Node *head,*temp; 
public:
    //constructor
    CirSinglyLinkedList()
    {
        head = temp = 0;
        totalNodes = 0;
    }
    //destructor
    ~CirSinglyLinkedList()
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
    void reverse();
    void traverse();
    int isEmpty();
};
//search function
void CirSinglyLinkedList :: search()
{
    if(isEmpty())
    {
        //getting data value from User
        int query;
        int counter = 1;
        cout<<"Enter the data (*type - 'int') you want to Search : ";
        cin>>query;
        temp = head;
        do
        {
            if(temp->data == query)
            {
                cout<<"Found @ Index - "<<counter<<"\n";
                return;
            }
            temp = temp->nextNode;
            counter++;
        }while(temp != head);
        cout<<"Not Found\n";
    }
    else
    {
        cout<<"List Is Empty\n";
    }
    
}

//insert at begin
void CirSinglyLinkedList :: insertAtBegin()
{
    //taking input from the user
    temp = new Node();
    cout<<"Enter the Data of New Node : ";
    cin>>temp->data;
    //checking for empty list
    if(head == 0)
    {
        head = temp;
        head->nextNode = head;
        temp = 0;
    }
    else
    {
        //getting the tail
        Node *tail = head;
        while(tail->nextNode != head)
        {
            tail = tail->nextNode;
        }
        //inserting the new node before head
        temp->nextNode = head;
        //changing head and tail
        head = temp;
        tail->nextNode = head;
        temp = tail = 0;
    }
    totalNodes++;  
}

//insert at end function
void CirSinglyLinkedList :: insertAtEnd()
{
    //taking input from the user
    temp = new Node();
    cout<<"Enter the Data of New Node : ";
    cin>>temp->data;
    //checking for empty list
    if(head == 0)
    {
        head = temp;
        head->nextNode = head;
        temp = 0;
    }
    else
    {
        //finding the tail of Linked List
        Node* tail = head;
        while(tail->nextNode != head)
        {
            tail = tail->nextNode;
        }
        //inserting the Node at the End
        tail->nextNode = temp;
        tail->nextNode->nextNode = head;
        temp = tail = 0;
    }
    totalNodes++;
}

//insert at n-th location function
void CirSinglyLinkedList :: insertAtLoc()
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
    else if(loc == 1)
    {
        Node* tail = head;
        while(tail->nextNode != head)
        {
            tail = tail->nextNode;
        }
        temp->nextNode = head;
        head = temp;
        tail->nextNode = head;
        tail = temp = 0;
        totalNodes++;
    }
    else
    {
        int counter = 1;
        Node* requiredNode = head;
        while(counter != (loc-1))
        {
            requiredNode = requiredNode->nextNode;
            counter++;
        }
        temp->nextNode = requiredNode->nextNode;
        requiredNode->nextNode = temp;
        requiredNode = temp = 0;
        totalNodes++;
    }
}

//delete at begin
void CirSinglyLinkedList :: deleteAtBegin()
{
    if(totalNodes > 0)
    {
        if(head->nextNode == head)
        {
            temp = head;
            delete temp;
            head = temp = 0;
        }
        else
        {
            //get tail
            Node* tail = head;
            while(tail->nextNode != head)
            {
                tail = tail->nextNode;
            }
            temp = head;
            head = head->nextNode;
            tail->nextNode = head;
            delete temp;
            temp = 0;
        }
        totalNodes--;
    }
    else
    {
        cout<<"List is EMPTY\n";
    }
}

//delete at the end
void CirSinglyLinkedList :: deleteAtEnd()
{
    if(totalNodes > 0)
    {
        if(head->nextNode == head)
        {
            temp = head;
            delete temp;
            head = temp = 0;
        }
        else
        {
            //get that node behind the tail --->
            temp = head;
            while(temp->nextNode->nextNode != head)
            {
                temp = temp->nextNode;
            }
            delete temp->nextNode;
            temp->nextNode = head;
            temp = 0;
        }
        totalNodes--;
    }
    else
    {
        cout<<"List is EMPTY\n";
    }
    
}

//delete the n-th location function
void CirSinglyLinkedList :: deleteAtLoc()
{
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
        temp = head;
        //finding tail
        Node* tail = head;
        while (tail->nextNode != head)
        {
            tail = tail->nextNode;
        }
        //checking if the list has more than one item
        if(totalNodes == 1)
        {
            head = 0;
        }
        else
        {
            head = head->nextNode;
            tail->nextNode = head;
        }
        delete temp;
        totalNodes--;
    }
    else
    {
        int counter = 1;
        Node* requiredNode = head;
        while (counter != (loc-1))
        {
            requiredNode = requiredNode->nextNode;
            counter++;
        }
        temp = requiredNode->nextNode;
        //checking if the next node is tail or not
        if(temp->nextNode == head)
        {
            requiredNode->nextNode = head;
        }
        requiredNode->nextNode = temp->nextNode;
        delete temp;
        temp = requiredNode = 0;
        totalNodes--;
    }
    
}

//reverse function
void CirSinglyLinkedList :: reverse()
{
    if(!isEmpty())
    {
        cout<<"List is Empty\n";
    }
    else
    {
        temp = head;
        Node* next = 0;
        Node* previous = 0;
        do
        {
            next = temp->nextNode;
            temp->nextNode = previous;
            previous = temp;
            temp = next;
        }while (temp != head);
        head->nextNode = previous;
        head = previous;
        temp = 0;
    }
}
//traverse function
void CirSinglyLinkedList :: traverse()
{
    //setting temp equal to head 
    //checking whether the List is Empty or Not
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

//isEmpty() function -> to check the number of Nodes in the Linked List
int CirSinglyLinkedList :: isEmpty()
{
    if(totalNodes)
    {
        return totalNodes;
    }
    return 0;
}


int main()
{
    CirSinglyLinkedList* A = new CirSinglyLinkedList();
    char flag = 'y';
    int choice;
    //menu
    do{
        // system("CLS");
        cout<<setw(20)<<setfill(' ')<<"CIRCULAR LINKED LIST\n";
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