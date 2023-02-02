#include <iostream>
#include "linked_list.h"

using namespace std;

// Checks the linked list for proper structure.
// Uses asserts
void checkList(LinkedList<int>& list) {
  ListNode<int> *first = list.getFirst(), *last = list.getLast();

  if (list.size() == 0) {
    // if the list has size zero, the first and last better be null
    assert(first == NULL && last == NULL);
    return;
  }

  // otherwise, assert the first and last pointers behave properly
  assert(first != NULL && last != NULL);
  assert(first->prev == NULL && last->next == NULL);
  if (list.size() == 1) {
    assert(first == last);
    return;
  }

  // if we get here, the list has size >= 2, presumably
  ListNode<int> *node = first;
  unsigned int nodeCount = 0; // number of nodes we have iterated past
  while (node != last) {
    // as long as we are not at the last node, this "node"" should point ahead to another
    // list node and that node should point back to this "node"
    assert(node->next != NULL && node->next->prev == node);
    node = node->next;
    ++nodeCount;

    assert(nodeCount < list.size());
  }

  assert(nodeCount+1 == list.size());

}

void checkAndPrint(LinkedList<int>& list) {
  checkList(list);

  cout << "List size: " << list.size() << endl;
  cout << "Contents:";

  for (ListNode<int> *node = list.getFirst(); node != NULL; node = node->next) {
    cout << ' ' << node->item;
  }

  cout << endl << endl;
}

int main() {

  LinkedList<int> list;

  int insertList[] = {2, 5, 3, 1, 7, 14, 1, 5, 1};

  cout << "Inserting some values" << endl << endl;
  for (int i = 0; i < 8; i++) {
    list.insertBack(insertList[i]);
  }

  checkAndPrint(list);

  cout << "Creating a copy via copy constructor" << endl << endl;
  LinkedList<int> listCopy(list);

  ListNode<int> *ptr = list.find(8);

  assert(ptr == NULL);

  cout << "Finding and removing the first 5" << endl << endl;

  ptr = list.find(5);
  assert(ptr != NULL && ptr->item == 5);

  list.removeNode(ptr);

  cout << "Creating a 2nd copy via assignment operator" << endl << endl;
  LinkedList<int> listCopy2;
  listCopy2 = list;

  checkAndPrint(list);

  cout << "Fiding and removing another 5" << endl << endl;
  ptr = list.find(5);
  assert(ptr != NULL && ptr->item == 5);
  list.removeNode(ptr);

  checkAndPrint(list);

  // should have removed all 5s by now
  assert(list.find(5) == NULL);

  cout << "Inserting 17 before 14" << endl;
  ptr = list.find(14);
  assert(ptr != NULL);
  list.insertBefore(17, ptr);

  checkAndPrint(list);

  cout << "Removing all but the first value by repeatedly calling removeBack()" << endl;
  while (list.size() > 1) {
    list.removeBack();
  }

  checkAndPrint(list);

  cout << "Finding 2 and removing it" << endl;
  ptr = list.find(2);
  assert(ptr != NULL && ptr->item == 2);
  list.removeNode(ptr);

  checkAndPrint(list);

  cout << "The first copy we made earlier" << endl;
  checkAndPrint(listCopy);
  cout << "The second copy we made earlier" << endl;
  checkAndPrint(listCopy2);

  cout << "The next check should crash the program." << endl;
  list.removeFront();
  checkAndPrint(list);

  return 0;
}
