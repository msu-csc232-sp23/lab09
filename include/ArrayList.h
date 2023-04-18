/** ADT list: Array-based implementation.
    Listing 9-1.
    @file ArrayList.h */

#ifndef ARRAY_LIST_
#define ARRAY_LIST_

#include "ListInterface.h"
#include "PrecondViolatedExcep.h"

template<class ItemType>
class ArrayList : public ListInterface<ItemType> {
private:
    static const int DEFAULT_CAPACITY = 5; // Small capacity to test for a full list
    ItemType items[DEFAULT_CAPACITY + 1];  // Array of list items (not using element [0]
    int itemCount;                          // Current count of list items
    int maxItems;                           // Maximum capacity of the list

public:
    ArrayList();

    // TODO: Task 1.2 - Erase this comment and replace it with Doxygen comments that fully document this constructor.
    ArrayList(ItemType srcItems[], int numItems);

    // Copy constructor and destructor are supplied by compiler

    [[nodiscard]] bool isEmpty() const;

    [[nodiscard]] int getLength() const;

    bool insert(int newPosition, const ItemType &newEntry);

    bool remove(int position);

    void clear();

    /** @throw PrecondViolatedExcep if position < 1 or
                                       position > getLength(). */
    ItemType getEntry(int position) const noexcept(false);

    /** @throw PrecondViolatedExcep if position < 1 or
                                       position > getLength(). */
    void replace(int position, const ItemType &newEntry) noexcept(false);
};

// end ArrayList


#endif 
