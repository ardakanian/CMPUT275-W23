#include <iostream>
#include <iomanip>
#include <cassert>
#include "hash_table.h"

using namespace std;

struct StudentRecord {
  char name[20];
  unsigned int id;
  unsigned int grade;

  // returns a hash of the student struct
  // in this case, we simply return the id which seems very natural
  // as student IDs are (roughly) consecutive so they will be distributed
  // roughly evenly between buckets
  unsigned int hash() const;

  // two records with the same ID will be regarded as the same
  // remember, we only need the != operator for an entry being added
  // to the table
  bool operator!=(const StudentRecord& rhs) const;
};

unsigned int StudentRecord::hash() const {
  return id;
}


bool StudentRecord::operator!=(const StudentRecord& rhs) const {
  return id != rhs.id;
}


void printHashTable(const HashTable<StudentRecord>& table) {
  DynamicArray<StudentRecord> array = table.getItemsArray();

  cout << "Table size: " << table.size() << endl;
  for (int i = 0; i < array.size(); i++) {
    cout << setw(20) << left << array[i].name
         << setw(7) << array[i].id
         << setw(3) << array[i].grade << endl;
  }
}


int main() {
  // create a new table with 20 buckets
  HashTable<StudentRecord> table(20);

  StudentRecord students[] = {
    {"Zac",  12345, 89},
    {"Omid", 87654, 89},
    {"Alexa", 80000, 34},
    {"Siri",  55545, 84},
    {"Google Home", 11111, 84}
  };

  cout << "Inserting 4 entries" << endl;
  table.insert(students[0]);
  table.insert(students[2]);
  table.insert(students[3]);
  table.insert(students[4]);
  printHashTable(table);
  cout << endl;

  cout << "Checking Alexa is there but Omid is not" << endl;
  assert(table.contains(students[2]) == true);
  assert(table.contains(students[1]) == false);
  cout << endl;

  cout << "Removing Zac and adding Omid" << endl;
  table.remove(students[0]);
  table.insert(students[1]);
  printHashTable(table);
  cout << endl;

  cout << "Double-checking we removed and added them" << endl;
  assert(table.contains(students[0]) == false);
  assert(table.contains(students[1]) == true);
  cout << endl;

  cout << "Adding Zac again" << endl;
  table.insert(students[0]);
  assert(table.contains(students[0]) == true);
  printHashTable(table);
  cout << endl;

  cout << "Changing Siri's Grade" << endl;
  // should use the same ID number
  StudentRecord newSiri = {"Siri", 55545, 75};
  // this actually removes the old entry with Siri (i.e. the one with the
  // matching student ID)
  table.remove(newSiri);
  table.insert(newSiri);
  // notice Siri and Zac print in a different order this time,
  // so there really is no natural "ordering" to the entries
  printHashTable(table);
  cout << endl;

  return 0;
}
