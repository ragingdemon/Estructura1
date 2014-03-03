#ifndef VARRAYLIST_H
#define VARRAYLIST_H

#include "tdalist.h"
#include "object.h"

class VArrayList : public TDAList
{
    int capacity;
    int growth;
    Object** data;
public:
    VArrayList(int,int=1);
    virtual ~VArrayList();
    virtual bool insert(Object*, int);
    virtual int indexOf(Object*)const;
    virtual Object* get(unsigned)const;
    virtual Object* remove(int);
    virtual int prev(int) const;
    virtual int next(int) const;
    virtual void clear();
    virtual Object* first()const;
    virtual Object* last()const;
    virtual void print()const;
    virtual bool isFull()const;
};

#endif // VARRAYLIST_H
