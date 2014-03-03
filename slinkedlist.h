#ifndef SLINKEDLIST_H
#define SLINKEDLIST_H

#include "tdalist.h"
#include "dllnode.h"

class SLinkedList : public TDAList
{
protected:
    DLLNode* head;
public:
    SLinkedList();
    virtual ~SLinkedList();
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

#endif // SLINKEDLIST_H
