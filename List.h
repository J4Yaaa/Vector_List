#pragma once

typedef int DataType;

struct ListNode
{
    DataType _data;
    ListNode* _next;
    ListNode* _prev;
    //Node的拷贝构造函数
    ListNode(DataType x):_data(x),_next(nullptr),_prev(nullptr)
    {}
};

class List
{
    typedef ListNode Node;
public:
    List();
    ~List();
    List(const List& l);
//    List& operator=(const List& l);
    List& operator=(List l);
    void PushBack(DataType x);
    void PushFront(DataType x);
    void PopBack();
    void PopFront();
    void Insert(Node* pos,DataType x);
    void Erase(Node* pos);
    void PrintList();
private:
    Node* _head;
};
