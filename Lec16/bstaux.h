/*
  Contains auxiliary classes for the binary search tree.

  BSTNode - models a single node in the binary search tree.
  BSTIterator - models an iterator for the binary search tree.

  ZAC'S COMMENT: There are some style differences from what we emphasized
  on the slides. Namely, some methods are implemented inline the class
  declaration.  We encourage you to continue supplying implementations
  outside of class declarations: this code is provided as-is.
*/

#ifndef _BST_AUX_H_
#define _BST_AUX_H_

// forward declaration of class, so BSTNode can establish it's "friends" :)
template <typename K, typename T> class BSTMap;
template <typename K, typename T> class BSTIterator;

/*
  Node for holding the key, item, and pointers for a node in the BST.
  Everything is private, only BSTMap abd BSTIterator have access.
*/
template <typename K, typename T>
class BSTNode {
private:
  BSTNode(const K& key, const T& item,
    BSTNode<K,T>* left, BSTNode<K,T>* right, BSTNode<K,T>* parent) {
      this->key = key;
      this->item = item;
      this->left = left;
      this->right = right;
      this->parent = parent;
  }

  // the destructor recursively deletes the left and right subtree, if they exist
  ~BSTNode() {
    if (this->left) {
      delete this->left;
    }
    if (this->right) {
      delete this->right;
    }
  }

  K key;
  T item;
  BSTNode<K,T> *left, *right, *parent;

  // give access to the BST map class itself and its iterators
  friend class BSTMap<K,T>;
  friend class BSTIterator<K,T>;
};

/*
  Iterator class for the BSTMap class.

  Supports:
  - key()
  - item(), as an l-value as well
  - prefix and postfix increment
  - == and !=
*/
template <typename K, typename T>
class BSTIterator {
public:
  const K& key() const {
    return this->node->key;
  }

  const T& item() const {
    return this->node->item;
  }

  // allows assignment to the item, eg. iter.item() = 17
  // this will update the item held at by the corresponding key
  T& item() {
    return this->node->item;
  }

  // prefix operator: ++iter
  BSTIterator<K,T> operator++() {
    advance();
    return *this;
  }

  // postfix operator: iter++
  BSTIterator<K,T>& operator++(int) {
    // uses the default copy constructor to copy this->node
    BSTIterator<K,T> tmp(*this);
    advance();
    return tmp;
  }

  bool operator==(const BSTIterator<K,T>& rhs) const {
    return node == rhs.node;
  }

  bool operator!=(const BSTIterator<K,T>& rhs) const {
    return node != rhs.node;
  }

private:
  // given the root of the tree, this finds the minimum-key item in the tree
  // to initialize this iterator
  BSTIterator(BSTNode<K,T> *root) {
    this->node = root;
    if (node != NULL) {
      // if the root of the tree is not empty, go to "leftmost" node
      while (this->node->left) {
        this->node = node->left;
      }
    }
  }

  void advance() {
    assert(node != NULL);
    if (this->node->right) {
      // if there is a right subtree, go to its leftmost/minimum-key node
      this->node = this->node->right;
      while (this->node->left) {
        this->node = this->node->left;
      }
    }
    else {
      // crawl up parent pointers while this node is the right child of the parent
      const BSTNode<K,T> *old;
      do {
        old = this->node;
        this->node = this->node->parent;
      } while (this->node != NULL && this->node->right == old);
    }
  }

  BSTNode<K,T> *node;

  // needed so BSTMap can access the constructor
  friend class BSTMap<K,T>;
};

#endif
