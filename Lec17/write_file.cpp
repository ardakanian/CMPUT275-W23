#include <iostream>
#include <fstream>

using namespace std;

int main() {
    fstream fs;
    fs.open("misc.txt", ios::out);
    fs << "msg1" << " and msg2";

    fs.close();

    return 0;
}
