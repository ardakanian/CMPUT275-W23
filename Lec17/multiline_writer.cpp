#include <iostream>
#include <cstring>		// strlen, strcmp
#include <unistd.h>		// read, write, close
#include <fcntl.h>		// open and oflags
#include <sys/types.h>
#include <sys/stat.h>

using namespace std;

#define MAX_SIZE 1024

int main() {
    const char * inpipe = "pipe1";
    const char * outpipe = "pipe2";

    // create a backing fifo file
    if (mkfifo(inpipe, 0666) == -1) {
        cerr << "Error: fifo creation failed." << endl;
        return 1;
    }
    // create a backing fifo file
    if (mkfifo(outpipe, 0666) == -1) {
        cerr << "Error: fifo creation failed." << endl;
        return 1;
    }

    /*	
    	open as write-only; a file descriptor that refers to 
    	the file description table is returned 
    */
    int ofd = open(outpipe, O_WRONLY);
    if (ofd == -1) {
        cerr << "Error: cannot open the named pipe." << endl;
        
        // reclaim the backing files
        unlink(inpipe);
        unlink(outpipe);
        return 1;
    }

    /*  
        open as read-only; a file descriptor that refers to 
        the file description table is returned 
    */
    int ifd = open(inpipe, O_RDONLY);
    if (ifd == -1) {
        cerr << "Error: cannot open the named pipe." << endl;
        
        // reclaim the backing files
        unlink(inpipe);
        unlink(outpipe);
        return 1;
    }

    char writerbuf[MAX_SIZE] = {0};
    char readerbuf[MAX_SIZE] = {0};

	cout << "Writer started..." << endl;
    cout << "Enter the first line of your message" << endl;
    while (true) {
    	cin.getline(writerbuf, MAX_SIZE);

        // getline stores a null character into the next available location in the buffer array
    	if (write(ofd, writerbuf, strlen(writerbuf)+1) == -1)
    	    cerr << "Error: write operation failed!" << endl;
    	if (strcmp("Quit", writerbuf) == 0)
    		break;

        int bytesread = read(ifd, readerbuf, MAX_SIZE);
        if (bytesread == -1)
            cerr << "Error: read operation failed!" << endl;
        if (strcmp("RECEIVED", readerbuf) != 0) {
            cerr << "Error: message corrupted!" << endl;
            break;
        }
        cout << "Enter the next line" << endl;
    }

    // close the file descriptors
    close(ifd);
    close(ofd);

    // reclaim the backing files
    unlink(inpipe);
    unlink(outpipe);

	return 0;
}
