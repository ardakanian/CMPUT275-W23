#include <iostream>
#include <fstream>

using namespace std;

int main() {
	fstream fs;
    string msg, msg1, msg2;
	fs.open("misc.txt", ios::in);
	fs >> msg >> msg1 >> msg2;
    cout << msg << " " << msg1 << " " << msg2 << endl;
       
    fs.close();

	return 0;
}
