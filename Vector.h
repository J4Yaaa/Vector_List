#pragma once
#include <stddef.h>

#define Max_Size 10

typedef int DataType;

class Vector
{
public:
    Vector();
    ~Vector();
    Vector(const Vector& v);
    Vector& operator=(const Vector& v);
    void Expand(int n);
    void Assignment(const Vector& v);
    void PushBack(DataType x);
    void PopBack();
    void Insert(size_t pos,DataType x);
    void Erase(size_t pos);
    size_t Find(DataType x);
    size_t Size() const;
    size_t Capacity() const;
    void PrintList();
private:
    DataType* _first;
    DataType* _finish;
    DataType* _endofstorage;
};
