// FILE: queue4.h (part of the namespace
// TEMPLATE CLASS PROVIDED: queue<Item> (a queue of items)
//
// TEMPLATE PARAMETER, TYPEDEFS and MEMBER CONSTANTS for the stack<Item> class:
//   The template parameter, Item, is the data type of the items in the queue,
//   also defined as queue<Item>::value_type. It may be any of the C++ built-in
//   types (int, char, etc.), or a class with a default constructor, a copy
//   constructor, and an assignment operator. The definition
//   queue<Item>::size_type is the data type of any variable that keeps track of
//   how many items are in a queue.
// NOTE:
//   Many compilers require the use of the new keyword typename before using
//   the expressions queue<Item>::value_type and queue<Item>::size_type.
//   Otherwise the compiler doesn't have enough information to realize that it
//   is the name of a data type.
//
// CONSTRUCTOR for the queue<Item> template class:
//   queue( )
//     Postcondition: The queue has been initialized as an empty queue.
//
// MODIFICATION MEMBER FUNCTIONS for the queue<Item> template class:
//   Item& front( ) 
//     Precondition: size( ) > 0
//     Postcondition: The return value is a reference to the item at
//     the front of the queue (and the queue is unaltered).
//
//   void pop( )
//     Precondition: size( ) > 0.
//     Postcondition: The front item of the queue has been removed.
//
//   void push(const Item& entry)
//     Postcondition: A new copy of entry has been inserted at the rear of the
//     queue.
//
//   To be added by C243 student.
//   Item& dequeue()
//     Precondition: size() > 0.
//     Postcondition: The front item of the queue has been removed and returned.
//
//   To be added by C243 student.
//   void enqueue(const Item& entry)
//     Postcondition: A new copy of entry has been inserted at the rear of the
//     queue.
//
//   To be added by C243 student. Use an iterator here!
//   bool isInQ(const Item& entry)
//     Postcondition: The return value is true if the queue contains entry.  
//
// CONSTANT MEMBER FUNCTIONS for the queue<Item> template class:
//   bool empty( ) const
//     Postcondition: The return value is true if the queue is empty.
//
//   const Item& front( ) const
//     Precondition: size( ) > 0
//     Postcondition: The return value is a const reference to the item at
//     the front of the queue (and the queue is unaltered).
//
//   size_type size( ) const
//     Postcondition: The return value is the total number of items in the queue.
//
// VALUE SEMANTICS for the queue<Item> template class:
//   Assignments and the copy constructor may be used with queue<Item> objects.
//Modified by: Bryan Berkey

#ifndef MAIN_SAVITCH_QUEUE4_H     // Prevent duplicate definition
#define MAIN_SAVITCH_QUEUE4_H
#include <cstdlib>   // Provides std::size_t
#include "node2.h"   // Node template class

namespace main_savitch_8C
{
    template <class Item>
    class queue
    {
    public:
        // TYPEDEFS 
        typedef std::size_t size_type;
        typedef Item value_type;

        // Iterator code here taken from Main & Savitch, Data
        // Structures and Other Objects Using C++, 4th ed., p. 338.
        typedef main_savitch_6B::node_iterator<Item> iterator;
        typedef main_savitch_6B::const_node_iterator<Item> const_iterator;

        // Methods to provide iterators.
        iterator begin()
            { return iterator(front_ptr); }
        const_iterator begin() const
            { return const_iterator(front_ptr); }
        iterator end()  // Using the iterator's default constructor
            { return iterator(); }
        const_iterator end() const  // Using the default constructor
            { return const_iterator(); }

        // CONSTRUCTORS and DESTRUCTOR
        queue( );
	queue(const queue<Item>& source);
	~queue( );
        // MODIFICATION MEMBER FUNCTIONS
	Item& front( );
        void pop( );
        void push(const Item& entry);
	Item& dequeue();   // To be added by C243 student.
        void enqueue(const Item& entry);   // To be added by C243 student.
        bool isInQ(const Item& entry);     // To be added by C243 student.
        void operator =(const queue<Item>& source);
        // CONSTANT MEMBER FUNCTIONS
        bool empty( ) const { return (count == 0); }
	const Item& front( ) const;
	size_type size( ) const { return count; }
    private:
        main_savitch_6B::node<Item> *front_ptr;
        main_savitch_6B::node<Item> *rear_ptr; 
        size_type count;       // Total number of items in the queue
    };
}
#include "queue4.template" // Include the implementation
     
#endif
