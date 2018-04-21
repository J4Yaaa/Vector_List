#include "Vector.h"
#include <iostream>
using namespace std;

size_t Vector::Size()const
{
    return _finish - _first;
}

size_t Vector::Capacity()const
{
    return _endofstorage - _first;
}

Vector::Vector():_first(NULL),_finish(NULL),_endofstorage(NULL)
{}

Vector::~Vector()
{
    delete[] _first;
    _first = NULL;
    _finish = NULL;
    _endofstorage = NULL;
}

//开辟一个和v等大的空间,并将_first,_finish,_endofstorage
//还有新空间的内容都更新
void Vector::Assignment(const Vector& v)
{
    size_t capacity = v.Capacity();
    size_t size = v.Size();
    DataType* new_List = new DataType[capacity];
    _first = new_List;
    _finish = _first + size;
    _endofstorage = _first + capacity;
    DataType* cur1 = _first;
    DataType* cur2= v._first;
    while(cur2 != _finish)
    {
        *cur1++ = *cur2++;
    }
}

Vector::Vector(const Vector& v)
{
    Assignment(v);
}

Vector& Vector::operator=(const Vector& v)
{
    Assignment(v);
    return *this;
}

void Vector::Expand(int n)
{
    DataType* new_head = new DataType[n];
    DataType* new_cur = new_head;
    DataType* cur = _first;
    while(cur != _finish)
    {
        *new_cur++ = *cur++;
    }
    _first = new_head;
    _finish = new_cur;
    _endofstorage = _first + n;
}

void Vector::PushBack(DataType x)
{
    if(_finish == _endofstorage)
    {
        Expand(2 * Capacity() + 1);
    }
    *_finish++ = x;
}

void Vector::PopBack()
{
    if(_first == _finish)
    {
        return;
    }
    --_finish;
}

void Vector::Insert(size_t pos,DataType x)
{
    if(_first + pos > _finish)
    {
        return;
    }
    if(_finish == _endofstorage)
    {
        Expand(2 * Capacity() + 1);
    }
    size_t end = Size() - 1;
    while((int)end >= (int)pos)
    {
        _first[end + 1] = _first[end];
        --end;
    }
    _first[pos] = x;
    ++_finish;
}

void Vector::Erase(size_t pos)
{
    if(pos >= Size())
    {
        return;
    }
    size_t i = pos;
    for(; i < Size() - 1; ++i)
    {
        _first[i] = _first[i+1];
    }
    --_finish;
}

size_t Vector::Find(DataType x)
{
    DataType* cur = _first;
    while(cur != _finish)
    {
        if(*cur == x)
        {
            return cur - _first;
        }
        ++cur;
    }
    return (size_t)-1;
}

void Vector::PrintList()
{
    DataType* cur = _first;
    while(cur != _finish)
    {
        cout<<*cur<<" ";
        ++cur;
    }
    cout<<endl;
    cout<<"size = "<<Size()<<endl;
    cout<<"capa = "<<Capacity()<<endl;
}

//////////////////////TEST_CODE///////////////////////

#if 1

int main()
{
    Vector v1;
    v1.PushBack(9);
    v1.PushBack(8);
    v1.PushBack(7);
    v1.PushBack(6);
    v1.PrintList();
    v1.Insert(0,0);
    v1.PrintList();
    v1.Insert(2,2);
    v1.PrintList();
    v1.Insert(6,6);
    v1.PrintList();
    v1.Erase(6);
    v1.PrintList();
    v1.Erase(2);
    v1.PrintList();
    v1.Erase(0);
    v1.PrintList();
    return 0;
}


#endif
