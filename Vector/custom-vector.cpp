#include "custom-vector.h"

template <typename T>
Vector<T>::Vector(int initCapacity) 
    : capacity{initCapacity}, size{0} {
    array = new T[capacity];
}

template <typename T>
void Vector<T>::expand(int newCapacity){
    if (newCapacity > size){
        T *old = array;
        /* Assign into new memory*/
        array = new T[newCapacity];
        /* Copy the old content */
        for(int i = 0; i < size; i++)
            array[i] = old[i];
        /* Delete old memory and assign new capacity */
        delete[] old;
        capacity = newCapacity;
    }
}

/* Push element into the last of vector */
template <typename T>
void Vector<T>::push_back(T newElement){
    /* Double the size of vector whenever full */
    if (size == capacity){
        expand(2 * size);
    }
    /* Add the new element into the last*/
    array[size] = newElement;
    /* Increase the size */
    size++;
}

/* Add element into the list at specific position */
template <typename T>
void Vector<T>::insert(int pos, T newElement){
    /* Double the size of vector whenever full */
    if (size == capacity){
        expand(2 * size);
    }

    /* Shift elements into right from the pos-th element */
    for (int i = size; i > pos; i--){
        array[i] = array[i-1];
    }

    /* Assign the new element */
    array[pos] = newElement;

    /* Increase the size of vector*/
    size++;
}

/* Pop the last element of list */
template <typename T>
void Vector<T>::pop_back(){
    size--;
}

/* Eliminate element on specific pos */
template <typename T>
void Vector<T>::erase(int pos){
    /* Shift element from position pos + 1 to left */
    for (int i = pos; i < size - 1; i++){
        array[i] = array[i+1];
    }
    /* Decrease the size of vector */
    size--;
}

/* reset the vector size to 0*/
template <typename T>
void Vector<T>::clear(){
    size = 0;
}

/* Vector destruction*/
template <typename T>
Vector<T>::~Vector(){
    delete[] array;
}

/* Check for the size of vector */
template <typename T>
int Vector<T>::vsize(){
    return size;
}

/* Check whether the vector is empty */
template <typename T>
bool Vector<T>::empty(){
    return (size == 0);
}

/* Assignment operator overloading */
template <typename T>
Vector<T>& Vector<T>::operator= (Vector<T> &rhs){
    /* Prevent from moving itself*/
    if (this != &rhs){
        /* Delete the current array (if available) */
        delete[] array;
        /* Set the new information */
        size = rhs.size;
        capacity = rhs.capacity;
        array = new T[capacity];

        /* Copy the content */
        for (int i = 0; i < size; i++){
            array[i] = rhs.array[i];
        }
    }
    return this;
}

template <typename T>
/* Access the element of vector */
T& Vector<T>::operator[] (int index){
    return array[index];
}
