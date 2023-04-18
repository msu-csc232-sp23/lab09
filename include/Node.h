/** @file Node.h
    Listing 4-1 */
#ifndef NODE_
#define NODE_

template<class ItemType>
class Node {
private:
    ItemType item; // A data item
    Node<ItemType> *next; // Pointer to next node

public:
    explicit Node(const ItemType &anItem = ItemType{}, Node<ItemType> *nextNodePtr = nullptr);

    void setItem(const ItemType &anItem);

    void setNext(Node<ItemType> *nextNodePtr);

    ItemType getItem() const;

    Node<ItemType> *getNext() const;
}; // end Node

#endif