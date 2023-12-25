#ifndef __CUSTOM_VECTOR_H__
#define __CUSTOM_VECTOR_H__

template <typename T>
class Vector{
    private:
        int size; //Size of vector
        int capacity; //capacity of vector
        T *array; //Pointer to array
        /* Function to increase the size of vector */
        void expand(int newCapacity); 
    public: 
        /* Constructor of making vector, default 100 */
        Vector (int initCapacity = 100);
        /* Destructor */
        ~Vector();
        /* Operator overloading */
        Vector &operator=(Vector &rhs);
        T &operator[](int index);
        /* Size of vector */
        int vsize();
        /* Check for the empty vector */
        bool empty();
        /* Push element into the last of vector */
        void push_back(T newElement);
        /* Pop the last element of list */
        void pop_back();
        /* Add the element into the Position Pos*/
        void insert(int pos, T newElement);
        /* Check whether the vector is empty */
        void erase(int pos);
        /* Free all the vector */
        void clear();
};

#endif