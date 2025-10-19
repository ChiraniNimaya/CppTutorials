#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
#include <list>
#include <set>
#include <map>

//a linked list is a data structure which every node holds a valu and a pointer which ho;ds the next node address

//Implementation
struct Node{
    int value;
    Node* nextNode;
};

class LinkedList{
    Node* head;

    public:
    //Constructor
    LinkedList() {
        head = nullptr;
    }

    //display method - traversing
    void display()
    {
        Node* temp = head;
        while (temp->nextNode != nullptr)
        {
            std::cout << temp->value << std::endl;
            temp = temp->nextNode;
        }
    }

    //insert at the end
    void insertAtEnd(int newValue)
    {
        Node* newNode = new Node();
        newNode->value = newValue;
        if (head->nextNode == nullptr)
        {
            head = newNode;
        }
        else
        {
            Node* temp = head;
            while (temp->nextNode != nullptr)
            {
                temp = temp->nextNode;
            }
            temp->nextNode = newNode;
        }
    }

    //delete by value
    void deleteByValue(int deleteValue)
    {
        if (head == nullptr)
            return;
        Node* temp = head;
        if (head->value == deleteValue)
        {
            head = head->nextNode;
            delete temp;
            return;
        }
        while (temp->nextNode && temp->nextNode->value != deleteValue)
        {
            temp = temp->nextNode;
        }
        if (temp->nextNode)
        {
            Node* nodeToDelete = temp->nextNode;
            temp->nextNode = temp->nextNode->nextNode;
            delete nodeToDelete;
        }
    }

    //reverse the linked list
    void reverseLinkedList()
    {
        Node* prevptr = nullptr;
        Node* currptr = head;
        Node* nextptr;
        while(currptr != nullptr){
            nextptr = currptr->nextNode;
            currptr->nextNode = prevptr;
            prevptr = currptr;
            currptr = nextptr;
        }
        head = prevptr;
    }

    //destructor
    ~LinkedList() {
        Node* temp;
        while (head)
        {
            temp = head;
            head = head->nextNode;
            delete temp;
        }
    }
};

int main()
{
    return 0;
}