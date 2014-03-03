#include "object.h"
#include "tdalist.h"
#include "farraylist.h"

#include <iostream>
using std::cout;
using std::endl;
// Constructor
FArrayList::FArrayList(int aCapacity) {
    capacity = aCapacity;
    data = new Object*[capacity];
    for (int i = 0; i < capacity; ++i) {
        data[i] = NULL;
    }
}
// Destructor

FArrayList::~FArrayList() {

}

bool FArrayList::insert(Object *element, int index) {
    if (index < 0 || index > size) {
        return false;
    }
    if (size == capacity) {
        return false;
    }
    if (index != size) {
        for (int i = size - 1; i >= index; --i) {
            data[i + 1] = data[i];
        }
    }
    data[index] = element;
    size++;
    return true;
}

int FArrayList::indexOf(Object *element) const {
    for (int i = 0; i < size; i++) {
        if (data[i] == element) {
            return i;
        }
    }
    return -1;
}

Object *FArrayList::get(unsigned int index) const {
    return data[index];
}


int FArrayList::prev(int) const {
    return -1;
}

int FArrayList::next(int) const {
    return -1;
}


Object *FArrayList::first() const {
    if (!isEmpty()) {
        return data[0];
    }
    return NULL;
}

Object *FArrayList::last() const {
    if (!isEmpty()) {
        return data[size - 1];
    }
    return NULL;
}

void FArrayList::print() const {
    for (int i = 0; i < size; i++) {
        if (i == 0) {
            cout<<'['<<data[i]->toString()<<',';
        } else if (i == size - 1) {
            cout<<data[i]->toString()<<']';
        }else{
           cout<<data[i]->toString()<<',';
        }
    }
}

bool FArrayList::isFull() const {
    if (size == capacity) {
        return false;
    }
}

Object *FArrayList::remove(int index)  {
    if (index < 0 || index > size) {
        return NULL;
    }
    if (isEmpty()) {
        return NULL;
    }
    Object *temp = data[index];
    for (int i = index; i < size; ++i) {
        data[i] = data[i + 1];
    }
    size--;
    return temp;
}

void FArrayList::clear()  {
    int temp = size;
    for (int i = 0; i < temp; ++i) {
        delete data[i];
        size--;
    }
    delete[] data;
}
