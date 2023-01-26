/*
  A simple demonstration of how to use unordered maps.

  Course: CMPUT 275
  Zac Friggstad, 2021
*/

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
  unordered_map<string, int> my_dict = {
    {"Zac", 7}, {"Omid", -11}, {"Ray", 9},
    {"Ragur", 5}, {"Rebecca", 9}, {"Saidur", 0}
  };

  // printing the contents of the map
  // using a C++11 range-based for loop
  // OBSERVE: the order they are printed does not correspond to
  // the order they were inserted
  for (auto items : my_dict) {
    cout << items.first << ": " << items.second << endl;
  }
  cout << endl;

  if (my_dict.find("Omid") == my_dict.end()) {
    cout << "key Omid not found" << endl;
  }
  else {
    cout << "key Omid found" << endl;
  }

  cout << "Now erasing Omid" << endl;
  my_dict.erase("Omid");

  if (my_dict.find("Omid") == my_dict.end()) {
    cout << "key Omid not found" << endl;
  }
  else {
    cout << "key Omid found" << endl;
  }
  cout << endl;

  my_dict["Zac"] = 44;
  for (auto items : my_dict) {
    cout << items.first << ": " << items.second << endl;
  }
  cout << endl;

  cout << "Number of entries: " << my_dict.size() << endl << endl;



  cout << "Another map keyed by pointers" << endl;
  unordered_map<const char*, int> ptr_map;

  const char* testing = "Testing";
  const char* testing_again = "Is this thing on?";

  ptr_map[testing] = 123;
  ptr_map[testing_again] = 456;


  for (auto items : ptr_map) {
    // remember, cout will print the actual string if the pointer is of type
    // char* or const char* (whereas it prints the memory address for other pointer types)
    cout << items.first << ": " << items.second << endl;
  }
  cout << endl;


  return 0;
}
