#include <iostream>
#include <iomanip>
#include <conio.h>
using namespace std;

//Node Class
template <typename T>
class Node
{
public:
    T data;
    Node* nextNode;
    //constructor
    Node(T data = 0, Node* nextNode = 0)
    {
        this->data = data;
        this->nextNode = nextNode;
    }
    //destructor
    ~Node()
    {
        cout<<"Destroying Node; DATA = <<"<<this->data<<"\n";
    }
};

template <typename T>
class OrderedLinkedList
{
private:
    //data members
    int totalNodes;
    Node<T> *head,*tail,*temp;
public:
    //constructor
    OrderedLinkedList()
    {
        head = tail = temp = 0;
        totalNodes = 0;
    }
    //destructor
    ~OrderedLinkedList()
    {
        temp = head;
        Node<T>* nextNodeptr = 0;
        cout<<"Destroying The List\n";
        while(temp != 0)
        {
            nextNodeptr = temp->nextNode;
            delete temp;
            temp = nextNodeptr;
        }
        cout<<"Done.\n";
    }

    //member functions 
    //insert function
    void insertNode()
    {
        temp = new Node<T>();
        cout<<"Enter the Data : ";cin>>temp->data;
        if(head == 0)
        {
            head = tail = temp;
            totalNodes++; 
        }
        else if(head->data == temp->data || tail->data == temp->data)
        {
            return;
        }
        else if(head->data > temp->data)
        {
            temp->nextNode = head;
            head = temp;
            totalNodes++;
        }
        else if(tail->data < temp->data)
        {
            tail->nextNode = temp;
            tail = temp;
            totalNodes++;
        }
        else
        {
            Node<T>* requiredNode = head;
            while(requiredNode->nextNode->data < temp->data)
            {
                requiredNode = requiredNode->nextNode;
            }
            if(requiredNode->nextNode->data == temp->data)
            {
                //beacuse the Node Already Exists
                return;
            }
            else
            {
                if(requiredNode->nextNode == tail)
                {
                    tail = temp;
                }
                temp->nextNode = requiredNode->nextNode;
                requiredNode->nextNode = temp;
                totalNodes++;
            }
            
        }
        temp = 0;
        
    }


    //delete function
    void deleteNode()
    {
        int loc;
        cout<<"Enter the Location : "; cin>>loc;
        if(totalNodes > 0)
        {
            if(loc < 0 || loc > totalNodes)
            {
                cout<<"INVALID\n";
                cout<<"Press Enter to Continue ";
                getch();
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
                temp = head;
                while(counter != (loc-1))
                {
                    temp = temp->nextNode;
                    counter++;
                }
                Node<T>* requiredNode = temp->nextNode;
                temp->nextNode = requiredNode->nextNode;
                if(requiredNode == tail)
                {
                    temp->nextNode = 0;
                    tail = temp;
                }
                delete requiredNode;
                temp = requiredNode = 0;
                totalNodes--;
            }
            
        }
    }
    //traverse function
    void traverse()
    {
        if(totalNodes > 0)
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
        else
        {
            cout<<"EMPTY\n";
        }
        
    }
};


int main()
{
    OrderedLinkedList<int>* A = new OrderedLinkedList<int>();
    int choice;
    char flag = 'y';
    do
    {
        cout<<"\n";
        cout<<setw(20)<<setfill(' ')<<"ORDERED LINKED LIST\n";
        cout<<setw(30)<<setfill('-')<<"\n";
        cout<<"LIST  : "; A->traverse();
        cout<<setw(30)<<setfill('-')<<"\n";
        cout<<"1. Insert \n"
            <<"2. Delete \n"
            <<"3. Exit\n";
        //getting user input
        cout<<"Enter What you want to do ? : ";
        cin>>choice;
        //switch cases
        switch (choice)
        {
        case 1:
            A->insertNode();
            break;
        case 2:
            A->deleteNode();
            break;
        case 3:
            flag = 'n';
            break;
        default:
            break;
        }
        system("CLS");

    }while(flag != 'n');


}