#include "object.h"
#include "tdalist.h"
#include "varraylist.h"

#include <iostream>
using std::cout;
using std::endl;
// Constructor
VArrayList::VArrayList(int aCapacity, int aGrowth) {
    capacity = aCapacity;
    growth = aGrowth;
    data = new Object*[capacity];
}
// Destructor

VArrayList::~VArrayList() {

}

bool VArrayList::insert(Object *element, int index) {
    if (index < 0 || index > size) {
        return false;
    }
    if (size == capacity) {
        Object **temp = data;
        capacity += growth;
        data = new Object*[capacity];
        for (int i = 0; i < size; ++i) {
            data[i] = temp[i];
        }
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

int VArrayList::indexOf(Object *element) const {
    for (int i = 0; i < size; i++) {
        if (data[i] == element) {
            return i;
        }
    }
    return -1;
}

Object *VArrayList::get(unsigned int index) const {
    return data[index];
}


int VArrayList::prev(int) const {
    return -1;
}

int VArrayList::next(int) const {
    return -1;
}


Object *VArrayList::first() const {
    if (!isEmpty()) {
        return data[0];
    }
    return NULL;
}

Object *VArrayList::last() const {
    if (!isEmpty()) {
        return data[size - 1];
    }
    return NULL;
}

void VArrayList::print() const {
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

bool VArrayList::isFull() const {
    if (size == capacity) {
        return false;
    }
}

Object *VArrayList::remove(int index)  {
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

void VArrayList::clear()  {
    int temp = size;
    for (int i = 0; i < temp; ++i) {
        delete data[i];
        size--;
    }
    delete[] data;
}
