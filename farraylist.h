#ifndef FARRAYLIST_H
#define FARRAYLIST_H

#include "tdalist.h"
#include "object.h"

class FArrayList : public TDAList
{
	int capacity;
	Object** data; 
  public:
    FArrayList(int);
    virtual ~FArrayList();
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
#endif
