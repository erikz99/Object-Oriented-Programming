#pragma once

template <typename A>
class IntCounter {
private:
    A* ptr;
    int* counter;

    void add_reference();
    void remove_reference();
    void freeMemory();

    void redirectPointers(A* newPtr, int* newCounter);
    void redirectPointers(const IntCounter& rhs);

public:
    IntCounter();

    IntCounter(A* newPtr);
    IntCounter(const IntCounter& rhs);
    IntCounter& operator=(const IntCounter& rhs);
    ~IntCounter();

    int get_count() const;
    A get_value() const;
};

template <typename A>
IntCounter<A>::IntCounter() : ptr(nullptr), counter(new int(0)) {}

template <typename A>
void IntCounter<A>::add_reference() {
    *(this->counter) += 1;
}

template <typename A>
void IntCounter<A>::remove_reference() {
    *(this->counter) -= 1;
}

template <typename A>
void IntCounter<A>::freeMemory() {
    delete this->ptr;
    delete this->counter;
}

template <typename A>
void IntCounter<A>::redirectPointers(A* newPtr, int* newCounter) {
    this->ptr = newPtr;
    this->counter = newCounter;
}

template <typename A>
void IntCounter<A>::redirectPointers(const IntCounter<A>& rhs) {
    this->redirectPointers(rhs.ptr, rhs.counter);
}

template <typename A>
IntCounter<A>::IntCounter(A* newPtr) {
    this->redirectPointers(newPtr, new int(1));
    // this->ptr = ptr;
    // this->counter = new int(1);
}

template <typename A>
IntCounter<A>::IntCounter(const IntCounter<A>& rhs) {
    this->redirectPointers(rhs);
    this->add_reference();
}

template <typename A>
IntCounter<A>& IntCounter<A>::operator=(const IntCounter<A>& rhs) {
    // Two objects are the same if they have the same pointer int* ptr,
    // which is different from the usual check in operator=
    if (this->ptr != rhs.ptr) {
        // Remove reference from the old pointer and check if deletion is due
        this->remove_reference();
        if (this->get_count() == 0) {
            this->freeMemory();
        }

        // Point the variables to the new pointer and add a reference
        this->redirectPointers(rhs);
        this->add_reference();
    }
    return *this;
}

template <typename A>
IntCounter<A>::~IntCounter() {
    this->remove_reference();
    if (this->get_count() == 0) {
        this->freeMemory();
    }
}

template <typename A>
int IntCounter<A>::get_count() const {
    return *this->counter;
} 

template <typename A>
A IntCounter<A>::get_value() const {
    return *this->ptr;
}