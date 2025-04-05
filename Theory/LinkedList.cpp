#include <iostream>

//Declare node
struct Node
{
    int data;
    Node* next;
};


//Declare head as a global variable
Node* head = NULL;

//Insert at the begining
void insertAtBegining(int newData)
{
    //create new node and assign the value
    Node* newNode = new Node();
    newNode->data = newData;

    newNode->next = head;
    head = newNode;
}

//Insert at a given position
void insertAtGivenPosition(int newData, int position)
{
    //create new node and assign the value
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->next = NULL;

    // Insert at the beginning if position is 0
    if (position == 0) 
    {
        newNode->next = head;
        head = newNode;
        return;
    }

    //create temp head at given position
    Node* tempHead = head;
    for (int i = 0; tempHead != NULL && i < position-1; ++i)
    {
        tempHead = tempHead->next;
    }

    if (tempHead != NULL)
    {
        newNode->next = tempHead->next;
        tempHead->next = newNode;
    }
    else
    {
        std::cout << "Invalid Position.\n";
    }
}

//Insert at the end
void insertAtEnd(int newData)
{
    //create new node and assign the value
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->next = NULL;

    // If the list is empty, make the new node the head
    if (head == NULL) 
    {
        head = newNode;
        return;
    }

    //create temp head at given position
    Node* tempHead = head;
    while(tempHead->next != NULL)
    {
        tempHead = tempHead->next;
    }

    tempHead->next = newNode;
}

void display()
{
    Node* tempHead = head;
    while(tempHead != NULL)
    {
        std::cout << tempHead->data << "\n";
        tempHead = tempHead->next;
    }
}

int main() 
{
    struct Node* head = NULL;  // Initialize an empty linked list
    // Inserting elements into the linked list
    insertAtBegining(6);
    insertAtBegining(5);
    insertAtBegining(4);
    insertAtBegining(3);
    insertAtBegining(2);
    insertAtBegining(1);
 
    std::cout << "Initial list: \n";
    display();  // Initially, the list is empty
 
    insertAtEnd(7);
    std::cout << "List after insertion at the end: \n";
    display();  // Display the linked list after inserting at the end
    

    insertAtGivenPosition(8,3);
    std::cout << "List after insertion: \n";
    display();

    return 0;
 }