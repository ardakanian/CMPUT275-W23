#include <iostream>
#include <cstring>

using namespace std;

int main() {
    char c[10];
    
    cin.getline(c, 10);
    
    cout << "You typed: " << c << endl;

    cout << "\nc[0] = " << c[0] << endl;
    cout << "c[1] = " << c[1] << endl;
    cout << "c[2] = " << c[2] << endl;
    cout << "c[3] = " << c[3] << endl;
    cout << "c[4] = " << c[4] << endl;
    cout << "c[5] = " << c[5] << endl;
    cout << "c[6] = " << c[6] << endl;
    cout << "c[7] = " << c[7] << endl;
    cout << "c[8] = " << c[8] << endl;
    cout << "c[9] = " << c[9] << endl;
    cout << "c[10] = " << c[10] << endl; // Going past array range.
    
    return 0;
}
