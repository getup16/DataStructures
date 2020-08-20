// 13.	WAP to add two polynomials using linked list representation.
#include <iostream>
#include <iomanip>
using namespace std;

//Polynomial Class
template <typename T >
class Polynomial
{
public:
    T *polynomial;  //to save the polynomial in a array
    int n;  //highest power of the Polynomial
    //constructor
    Polynomial(int n)
    {
        n = n + 1;
        cout<<"Enter the Constants : \n";
        polynomial = new T[n];
        for(int i = 0; i < n; ++i)
        {
            cout<<"x^"<<i<<" : ";
            cin>>polynomial[i];
        }
    }
    ~Polynomial()
    {
        delete[] polynomial;
    }
};

//Polynomial Node Class
template <typename T>
class PolynomialNode
{
public:
    Polynomial<T> *polynomialObject;
    PolynomialNode *nextNode; 
    int largest_power;
    //constructor
    PolynomialNode(int largest_power = 0, Polynomial<T> *polynomialObject = 0, PolynomialNode *nextNode = 0)
    {   
        this->polynomialObject = polynomialObject;
        this->largest_power = largest_power;
        this->nextNode = nextNode;
    }
    //destructor
    ~PolynomialNode()
    {
        delete polynomialObject;
    }
    //print the node
    void printPolynomial()
    {
        T *temp = polynomialObject->polynomial;
        for(int i = 0; i < largest_power + 1; i++)
        {
            cout<<temp[i]<<"*x^"<<i;
            if(i < (largest_power))
            {
                cout<<" + ";
            }
        }
        cout<<" = 0 \n";
        temp = 0;
    }
    
};

template <typename T>
class PolynomialLinkedList
{
private:
    //data members
    PolynomialNode<T> *head,*tail,*temp;
    Polynomial<T> *tempPolynomial;
    int totalNodes;
public:
    //constructor
    PolynomialLinkedList()
    {
        //initializing the head and tail pointers of Linked List to Null Pointer
        head = tail = temp = 0;
        totalNodes = 0;
    }
    //destructor
    ~PolynomialLinkedList()
    {
        temp = head;
        PolynomialNode<T>* nextNodePtr;
        while(temp != 0)
        {
            nextNodePtr = temp->nextNode;
            delete temp;
            temp = nextNodePtr;
        } 
        cout<<"Done.\n";
    }
    //member functions

    //traverse function
    void traverse()
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
            temp->printPolynomial();
            temp = temp->nextNode;
        }
        temp = 0;
    }
    }
    //insert function
    void insert()
    {
        int n;
        cout<<"Enter the Highest Power of the Polynomial : ";
        cin>>n;
        tempPolynomial = new Polynomial<T>(n);
        temp = new PolynomialNode<T>(n,tempPolynomial);
        if(head != 0)
        {
            tail->nextNode = temp;
            tail = temp;
        }
        else
        {
            head = tail = temp;
        }
        tempPolynomial = 0;
        temp = 0;
        totalNodes++;
    }

};


int main()
{

    PolynomialLinkedList<int> *polyList = new PolynomialLinkedList<int>();
        char flag = 'y';
    int choice;
    //menu
    do{
        cout<<"\n";
        cout<<setw(20)<<setfill(' ')<<"POLYNOMIAL LINKED LIST\n";
        cout<<setw(30)<<setfill('-')<<"\n";
        polyList->traverse();
        cout<<setw(30)<<setfill('-')<<"\n";
        cout<<"1. Insert \n"
            <<"13. Exit\n";
        //getting user input
        cout<<"Enter What you want to do ? : ";
        cin>>choice;
        //switch cases
        switch (choice)
        {
            case 1:
                polyList->insert();
                break;
            case 13:
                flag = 'n';
                break;
            default:
                break;
        }
    }
    while(flag == 'y');
    cout<<"\n";
    system("CLS");
    delete polyList;
    return 0;
}