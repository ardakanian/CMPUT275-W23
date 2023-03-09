#include <vector>
#include <algorithm>

// Suppose the key type, K, is comparable with respect to '<'
template <class T, class K>
struct HeapItem {
  T item;
  K key;
};

template <class T, class K>
class BinaryHeap {
public:
  // constructor is not provided because the only "initialization" required is
  // done by the constructor of the "heap" attribute which is called by default

  // return the minimum-key item
  HeapItem<T, K> min() const;

  // insert an item with the given key
  // if the item is already in the heap, 
  // it will still insert a new copy with this key
  void insert(const T& item, const K& key);

  // pop the minimum-key item from the heap
  void popMin();

  // return the number of items in the heap
  int size() const;

private:
  // dynamic array holding heap items
  std::vector< HeapItem<T, K> > heap;

  // fix the heap ordering property at index i and recurse with its parent
  void fixHeapUp(int i);

  // fix the heap ordering property at index i and recurse with the child
  // that had a smaller key
  void fixHeapDown(int i);
};


template <class T, class K>
HeapItem<T, K> BinaryHeap<T, K>::min() const {
  // assume min() is not called on empty heaps
  return heap[0];
}

template <class T, class K>
void BinaryHeap<T, K>::insert(const T& item, const K& key) {
  HeapItem<T, K> node = {item, key};

  // add the new item to the end of the heap
  heap.push_back(node);

  // then fix the heap ordering property
  // heap.size() - 1 is the index of the last heap item
  fixHeapUp(heap.size() - 1);
}

template <class T, class K>
void BinaryHeap<T, K>::popMin() {
  // move the last heap item (in the last layer) to the top
  // if the heap size is 1, this will just pop that item
  heap[0] = heap.back();
  heap.pop_back();

  // if there are items left in the heap, fix the heap property
  if (heap.size() > 0) {
    fixHeapDown(0);
  }
}

template <class T, class K>
int BinaryHeap<T, K>::size() const {
  return heap.size();
}

template <class T, class K>
void BinaryHeap<T, K>::fixHeapUp(int i) {
  while (i > 0) {
    int pi = (i-1)>>1; // the parent's index is (i-1)/2

    // if item i's key is smaller than its parent's key, 
    // swap them and go up
    if (heap[i].key < heap[pi].key) {
      // note std::swap is a function template so it works for HeapItems too
      std::swap(heap[i], heap[pi]);
      i = pi;
    }
    else {
      // no more fixing needs to be done
      return;
    }
  }
}

template <class T, class K>
void BinaryHeap<T, K>::fixHeapDown(int i) {
  while (true) {
    // get the index of child nodes
    int lchild = (i<<1)+1; // the left child's index is 2i+1
    int rchild = (i<<1)+2; // the right child's index is 2i+2

    // if there's no children, do nothing
    if (lchild >= int(heap.size())) {
      return;
    }

    int min_child;
    // identify the child with the minimum key, being careful
    // to handle the case where there is no right child
    if (rchild >= int(heap.size()) || heap[lchild].key <= heap[rchild].key) {
      min_child = lchild;
    }
    else {
      min_child = rchild;
    }

    // if the heap ordering property is violated for i, 
    // swap that item with the heap item held by 
    // the minimum-key child and repeat with this child
    if (heap[min_child].key < heap[i].key) {
      // note std::swap is a function template so it works for HeapItems too
      std::swap(heap[i], heap[min_child]);
      i = min_child;
    }
    else {
      return;
    }
  }
}

