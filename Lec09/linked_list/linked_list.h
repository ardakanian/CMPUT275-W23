/*
  Linked list implementation.

  Course: CMPUT 275
  Zac Friggstad, 2021

  IMPORTANT NOTE
  There are const methods that do not return pointers to const instances
  of ListNode. This is because we may want to later delete a node that we found
  via the find() method, but we could not do that if it was const.

  CAVEAT
  The user could get a pointer to a node and then redirect the node's
  prev and next pointers, thereby destroying the linked list structure.

  SOLUTION
  Iterators. Iterators are sort of an enhanced pointer that we have
  to define ourselves that allow us to hide *just* the right details. Think,
  they are a class/struct on their own that points to a node, allows us to
  go up or down the list, even allows us to update the item stored in a node,
  but do not let us destroy the integrity of the list (i.e. actually change
  the prev and next pointers).

  For the sake of time, we do not delve into details of creating your own
  iterators for a class. But feel free to look it up if you are curious.
*/

#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

#include <cassert>

using namespace std;

// struct for holding an item and pointers to the next and previous node
template <typename T>
struct ListNode {
  // constructor, while we generally don't add to much functionality to a struct
  // (because it maybe should have been a class in that case), simple constructors
  // are perfectly fine
  // NOTE: there is more convenient syntax if a constructor just copies parameters
  // to its attributes, feel free to look it up if you are curious
  ListNode(const T& l_item, ListNode<T>* l_prev, ListNode<T>* l_next);

  T item;
  ListNode<T> *prev, *next;
};

template <typename T>
ListNode<T>::ListNode(const T& l_item, ListNode<T>* l_prev, ListNode<T>* l_next) {
  item = l_item;
  prev = l_prev;
  next = l_next;
}


// A linked list, just as discussed in the slides.
template <typename T>
class LinkedList {
public:
  LinkedList();

  // copy constructor
  LinkedList(const LinkedList<T>& rhs);

  ~LinkedList();

  // assignment operator
  LinkedList<T>& operator=(const LinkedList& rhs);

  // insert a new item to the front
  void insertFront(const T& item);

  // insert a new item to the back
  void insertBack(const T& item);

  // remove the first node
  void removeFront();

  // remove the last node
  void removeBack();

  // makes the linked list empty (deletes all nodes)
  void clear();

  // assumes the node is in this list
  // will insert the item just before this node in the list
  void insertBefore(const T& item, ListNode<T>* node);

  // assumes the node is in this list
  void removeNode(ListNode<T>* node);

  // obviously returns the size of the list
  unsigned int size() const;

  // SEE COMMENT AT THE TOP OF THE FILE STATING WHY THESE DO NOT
  // RETURN const ListNode<T>* pointers.

  // Get ListNode pointers to the first and last items in the list,
  // respectively. Both return a pointer to NULL if the list is empty.
  ListNode<T>* getFirst() const;
  ListNode<T>* getLast() const;

  // Find and return a pointer to the first node with the item.
  // Returns the NULL pointer if the item is not in the list.
  ListNode<T>* find(const T& item) const;

private:
  ListNode<T> *first, *last;
  unsigned int listSize;
};

template <typename T>
LinkedList<T>::LinkedList() {
  first = last = NULL;
  listSize = 0;
}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList& rhs) {
  // first initialize this to an empty list
  first = last = NULL;
  listSize = 0;

  // and then just use the assignment operator
  *this = rhs;
}

template <typename T>
LinkedList<T>::~LinkedList() {
  // the clear method will delete all dynamically-allocated memory
  clear();
}

template <typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& rhs) {
  // empty out this list
  clear();

  // loop through all items in the rhs list and insert the item to the end
  // of this list
  for (ListNode<T>* node = rhs.first; node != NULL; node = node->next) {
    insertBack(node->item);
  }

  return *this;
}

template <typename T>
void LinkedList<T>::insertFront(const T& item) {
  // get a new ListNode to hold the item
  // it points back to NULL and ahead to the first node in current list
  ListNode<T> *node = new ListNode<T>(item, NULL, first);

  // if the list is not empty, have the first node point back to the new node.
  if (first != NULL) {
    first->prev = node;
  }
  else {
    // otherwise, this new node is also the last node
    last = node;
  }

  // update the first node
  first = node;
  listSize++;
}


template <typename T>
void LinkedList<T>::insertBack(const T& item) {
    ListNode<T> *node = new ListNode<T>(item, last, NULL);

    // if the list is not empty, have the last node point to the new node.
    if (last != NULL) {
      last->next = node;
    }
    else {
      // otherwise this new node is also the first node
      first = node;
    }

    // update the last node
    last = node;
    listSize++;
}

template <typename T>
void LinkedList<T>::clear() {
  // just iteratively remove the last node until the list is empty
  while (listSize > 0) {
    removeBack();
  }
}

template <typename T>
void LinkedList<T>::insertBefore(const T& item, ListNode<T> *link) {
  // if the link is the start of the list, just call insertFront
  if (link == first) {
    insertFront(item);
    return;
  }

  // get a new node to hold this item
  ListNode<T> *node = new ListNode<T>(item, link->prev, link);

  // redirect surrounding links, the order you do this is important!
  link->prev->next = node;
  link->prev = node;
  listSize++;
}

template <typename T>
void LinkedList<T>::removeFront() {
  assert(first != NULL);

  ListNode<T> *toDelete = first;

  // if this is not the only item in the list, redirect
  // the prev pointer of the 2nd item to NULL
  if (first != last) {
    first->next->prev = NULL;
  }
  else {
    // otherwise, the list will become empty
    last = NULL;
  }

  // works even if the list had size 1
  first = first->next;

  delete toDelete;
  listSize--;
}

template <typename T>
void LinkedList<T>::removeBack() {
  assert(first != NULL);

  ListNode<T> *toDelete = last;

  // if this is not the only item in the list, redirect
  // the next pointer of the 2nd last item to NULL
  if (first != last) {
    last->prev->next = NULL;
  }
  else {
    // the list will become empty
    first = NULL;
  }

  // works even if the list had size 1
  last = last->prev;

  delete toDelete;
  listSize--;
}


template <typename T>
void LinkedList<T>::removeNode(ListNode<T>* node) {
  // if we are removing the first or the last item, call that function
  if (node == first) {
    removeFront();
    return; // something followed the first node
  }

  if (node == last) {
    removeBack();
    return; // nothing followed the last node
  }

  // bypass the node we are deleting by redirecting pointers of surrounding nodes
  node->prev->next = node->next;
  node->next->prev = node->prev;

  delete node;
  listSize--;
}

template <typename T>
unsigned int LinkedList<T>::size() const {
  return listSize;
}

template <typename T>
ListNode<T>* LinkedList<T>::getFirst() const {
  return first;
}

template <typename T>
ListNode<T>* LinkedList<T>::getLast() const {
  return last;
}

template <typename T>
ListNode<T>* LinkedList<T>::find(const T& item) const {
  // crawl along the list until the item is found
  ListNode<T>* node = first;
  while (node != NULL && node->item != item) {
    node = node->next;
  }

  // returns NULL if the item was not found
  return node;
}

#endif
