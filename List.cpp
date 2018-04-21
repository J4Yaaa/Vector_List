#include "List.h"
#include <iostream>
using namespace std;

List::List():_head(new Node(DataType()))
{
    _head->_next = _head;
    _head->_prev = _head;
}

List::~List()
{
    Node* cur = _head->_next;
    while(cur != _head)
    {
        Node* next = cur->_next;
        delete cur;
        cur = next;
    }
    delete _head;
    _head = nullptr;
}

List::List(const List& l):_head(new Node(DataType()))
{
    _head->_next = _head;
    _head->_prev = _head;
    Node* cur = l._head->_next;
    while(cur != l._head)
    {
        PushBack(cur->_data);
        cur = cur->_next;
    }
}

List& List::operator=(List l)
{
    swap(_head,l._head);
    return *this;
}

void List::PushBack(DataType x)
{
//    Node* tail = _head->_prev;
//    Node* new_node = new Node(x);
//    tail->_next = new_node;
//    new_node->_prev = tail;
//    new_node->_next = _head;
//    _head->_prev = new_node;
    Insert(_head->_prev,x);
}

void List::PushFront(DataType x)
{
    Insert(_head,x);
}

void List::PopBack()
{
    Erase(_head->_prev);
}

void List::PopFront()
{
    Erase(_head->_next);
}

void List::Insert(Node* pos,DataType x)
{
    Node* new_node = new Node(x);
    Node* prev_node = pos;
    Node* next_node = pos->_next;

    prev_node->_next = new_node;
    new_node->_prev = prev_node;

    new_node->_next = next_node;
    next_node->_prev = new_node;
}

void List::Erase(Node* pos)
{
    Node* prev_node = pos->_prev;
    Node* next_node = pos->_next;

    delete pos;

    prev_node->_next = next_node;
    next_node->_prev = prev_node;
}

void List::PrintList()
{
    Node* cur = _head->_next;
    while(cur != _head)
    {
        cout<<cur->_data<<" -> ";
        cur = cur->_next;
    }
    cout<<"nullptr"<<endl;
}

//////////////////////////TEST_CODE///////////////////////

#if 1

int main()
{
    List l1;
    l1.PushBack(1);
    l1.PushBack(2);
    l1.PushBack(3);
    l1.PushBack(4);
    l1.PrintList();
    List* l2 = new List();
    *l2 = l1;
    (*l2).PrintList();
    return 0;
}

#endif
