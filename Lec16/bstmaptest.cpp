/*
  Test file for the BSTMap data structure.

  The BSTMap will associate grades (integers) to distinct names (strings).

  The input will be read from standard input. Either type "help" (or any
  other invalid command) or see the cout<< statements below for the types
  of operations supported in this test.
*/



#include <iostream>
#include <string>
#include "bstmap.h"

/*
  Prints all entries of the tree (name/grade).
  Only works for this specific type of map (i.e. <string, int>).
*/
void printTree(const BSTMap<string, int>& tree) {
  for (BSTIterator<string, int> iter = tree.begin(); iter != tree.end(); ++iter) {
    cout << iter.key() << ' ' << iter.item() << endl;
  }
}

int main() {
  BSTMap<string, int> tree;

  // Read a command, see the bottom-most cout<< statements for the types
  // of commands that are supported.
  while (true) {
    char cmd;
    string name;
    int grade;

    cin >> cmd;
    if (cmd == 'S') {
      cout << tree.size() << endl;
    }
    else if (cmd == 'U') {
      cin >> name >> grade;
      tree[name] = grade;
    }
    else if (cmd == 'F') {
      cin >> name;
      if (tree.hasKey(name)) {
        cout << name << " found with grade " << tree[name] << endl;
      }
      else {
        cout << name << " not found" << endl;
      }
    }
    else if (cmd == 'R') {
      cin >> name;
      if (!tree.hasKey(name)) {
        cout << name << " not found" << endl;
      }
      else {
        tree.remove(name);
      }
    }
    else if (cmd == 'P') {
      printTree(tree);
    }
    else if (cmd == 'Q') {
      cout << "stopping" << endl;
      break;
    }
    else {
      cout << "invalid command" << endl;
      cout << "Possible Commands:" << endl
      << "S - print the size of the map" << endl
      << "U <name> <grade> - update the grade for the name" << endl
      << "F <name> - check if the name is in the tree, prints the grade" << endl
      << "R <name> - remove the entry with the given name" << endl
      << "P - print all entries in the tree, ordered by key" << endl
      << "Q - stop" << endl;

      // eat up the rest of the line
      getline(cin, name);
    }
  }

  return 0;
}
