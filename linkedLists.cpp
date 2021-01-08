/*

 All Linked List Operations!!

*/


#include <iostream>
#include <string>
#include<string.h>
#include<algorithm>
#include <sstream>
using namespace std;


class Node{
public:

   Node(){data_ =0;next =nullptr;}

   //insert operations
   Node* insertNodeatBegining(int data, Node *head);
   void insertNodeatLast(int data, Node *head);
   void insertNodeAfter(int data, int newdata, Node *head);
   void insertNodeInMiddle(int data, int list_length, Node *head);

   //delete operations
   void deleteLastNode(Node *head);
   void deleteNodeAfter(int data, Node *head);
   void deleteNodeInMiddle(int list_length, Node *head);
   Node * deletetheFirstNode(Node *head);
   void deletetheGivenNode(int data, Node *head);
   Node* deleteAllNodes(Node *head);

   //list list's contents
   void displayList(Node *head);

   //is list circular?
   bool isListCircular(Node *head);

   //reverse the list
   Node * reverseList(Node *head);

   //get length of list
   int listLength(Node *head);

private:

   int data_;
   Node * next;
};

Node* Node::insertNodeatBegining(int data, Node *head)
{
    class Node *newnode = new Node();
    if (head == nullptr)
    {
        newnode->data_ =data;
        newnode->next =nullptr;
        head = newnode;

    }
    else
    {
        newnode->data_ = data;
        newnode->next = head;
        head = newnode;

    }
    return head;

}

void Node::insertNodeatLast(int data, Node *head)
{
    class Node *newnode = new Node();
    class Node * tmp;
    tmp = head;
    while(tmp->next != nullptr)
    {
        tmp = tmp->next;
    }

    newnode->next =nullptr;
    newnode->data_ = data;
    tmp->next = newnode;

}

void Node::insertNodeAfter(int data, int newdata, Node *head)
{
    class Node *newnode = new Node();
    class Node * currentNode;
    currentNode = head;

    while(currentNode->data_ != data)
    {
        currentNode = currentNode->next;
    }
    newnode->data_ = newdata;
    newnode->next = currentNode->next;
    currentNode->next = newnode;

}

void Node::insertNodeInMiddle(int data, int list_length, Node *head)
{
    auto listcounter = 1;
    class Node *currentNode = head;
    while(listcounter < (list_length/2) )
    {
        currentNode = currentNode->next;
        listcounter++;

    }

    class Node * newnode = new Node();
    newnode->data_ = data;
    newnode->next  = currentNode->next;

    currentNode->next =newnode;

}


void Node::deleteLastNode(Node *head)
{
    class Node * previousNode;
    class Node * currentNode = new Node();
    previousNode = head;

    while(previousNode->next->next != nullptr)
    {
        previousNode = previousNode->next;
    }

     //copy last node to current node
     currentNode->data_ = previousNode->next->data_;
     currentNode->next = previousNode->next->next;

     previousNode->next = nullptr;

     //delete current node
     delete currentNode;


}


void Node::deleteNodeAfter(int data, Node *head)
{

    class Node * previousNode;
    class Node * tmpNode;
    tmpNode = head;

    while(tmpNode != nullptr && tmpNode->data_ != data)
    {
        previousNode = tmpNode;
        tmpNode= tmpNode->next;
    }

     previousNode->next = tmpNode->next;

     //delete tmp node
     delete tmpNode;
}


void Node::deleteNodeInMiddle(int list_length, Node *head)
{
    class Node * previousNode;
    auto listcounter = 1;
    int loop_range;
    class Node * currentNode = new Node();
    previousNode = head;

    if(list_length/2 ==0)
    {
        loop_range = list_length/2 + 1;
    }
    else
    {
        loop_range = list_length/2 + 1;
    }

    while(listcounter < loop_range )
    {
        previousNode = previousNode->next;
        listcounter++;

    }

    //copy last node to current node
     currentNode->data_ = previousNode->next->data_;
     currentNode->next = previousNode->next->next;

     previousNode->next = currentNode->next;

     //delete current node
     delete currentNode;

}


Node * Node::deletetheFirstNode(Node *head)
{
    class Node * currentNode;

    currentNode = head->next;
    delete head;

    return currentNode;


}

Node * Node::reverseList(Node *head)
{

    Node *prev = nullptr;
    Node *fut = nullptr;

    Node *curr = head;

    while(curr != nullptr)
    {
        fut = curr->next;
        curr->next = prev;

        prev = curr;
        curr = fut;

    }

    head = prev;
    return head;

}

void Node::displayList(Node *head)
{
    if(head != nullptr)
    {
        class Node * tmp;
        tmp = head;
        while(tmp != nullptr)
        {
            cout << tmp->data_  << ": " <<& (tmp->data_)<< ":--> " << tmp->next << endl;

            tmp = tmp->next;
        }
    }
    else
    {
        cout << "list is empty " <<endl;
    }

}

void Node::deletetheGivenNode(int data, Node *head)
{
    class Node * previousNode;
    class Node * currentNode = new Node();
    previousNode = head;

    while(previousNode->next->data_ != data)
    {
        previousNode = previousNode->next;
    }

     //copy last node to current node
     currentNode->data_ = previousNode->next->data_;
     currentNode->next = previousNode->next->next;

     previousNode->next = currentNode->next;

     //delete current node
     delete currentNode;

}


Node* Node::deleteAllNodes(Node *head)
{
    class Node * cureentNode;
    class Node * nextNode = new Node();
    cureentNode = head;

    while(cureentNode != nullptr)
    {

       //copy next node
       nextNode->data_ = cureentNode->next->data_;
       nextNode->next = cureentNode->next->next;

       delete cureentNode;
       cureentNode = nextNode->next;

    }

   head = nullptr;
   return head;

}

int Node::listLength(Node *head)
{
    class Node * current = head;
    int listLength = 0;
    while(current != nullptr)
    {
        listLength++;
        current = current->next;
    }
    return listLength;
}

bool Node::isListCircular(Node *head)
{
    Node *current = head->next;
    while((current !=head) && (current !=nullptr))
    {
        current = current->next;
    }
    if(current ==head)
    {
        return true;
    }
    else{return false;}
}


int main(void) {

    Node * newhead =nullptr;

    Node node;

    //Add Node in beginning
    newhead = node.insertNodeatBegining(500, newhead);
    newhead = node.insertNodeatBegining(400, newhead);
    newhead = node.insertNodeatBegining(300, newhead);
    newhead = node.insertNodeatBegining(200, newhead);
    newhead = node.insertNodeatBegining(100, newhead);  //first Node

    //Add Node in last
    node.insertNodeatLast(600,newhead);
    node.insertNodeatLast(700,newhead);
    node.insertNodeatLast(800,newhead);
    node.insertNodeatLast(900,newhead);  //Last Node

    //insert node after data
    node.insertNodeAfter(300,400,newhead);


    //Delete last node
    node.deleteLastNode(newhead);

    //Delete node after data
    node.deleteNodeAfter(500, newhead);

    //check length of list
    int list_length =  node.listLength(newhead);

    //insert node in middle
    node.insertNodeInMiddle(350, list_length,newhead);
    node.insertNodeInMiddle(450, list_length,newhead);
    node.insertNodeInMiddle(550, list_length,newhead);

    //delete node in middle
    node.deleteNodeInMiddle(list_length,newhead);

    //delete first node
    newhead = node.deletetheFirstNode(newhead);

    //delete the given node
    node.deletetheGivenNode(350,newhead);

    //display list
    node.displayList(newhead);


    //reverse the list
    newhead = node.reverseList(newhead);

    //check if list is circular
    bool circular_list = node.isListCircular(newhead);
    if(circular_list)
    {
        cout << "list is circular" << endl;
    }
    else{
        cout << "single linked list" << endl;
    }


    //display list
    node.displayList(newhead);

    //Delete all Nodes
    newhead = node.deleteAllNodes(newhead);

    //display list
    node.displayList(newhead);

  return 0;

}
