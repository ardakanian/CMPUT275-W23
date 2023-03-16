#include <iostream>
#include <cstring>		// strlen

#include <unistd.h>		// read/write lib functions
#include <fcntl.h>		// open and oflags

#include <sys/types.h>
#include <sys/stat.h>

using namespace std;

#define MAX_SIZE 1024

int main() {
	const char * inpipe = "pipe2";
    const char * outpipe = "pipe1";

    /*	
    	open as write-only; a file descriptor that refers to 
    	the open file description is returned 
    */
    int ifd = open(inpipe, O_RDONLY);
    if (ifd == -1) {
        cerr << "Error: cannot open the named pipe." << endl;
        
        // reclaim the backing file
        unlink(inpipe);
        return 1;
    }

    int ofd = open(outpipe, O_WRONLY);
    if (ofd == -1) {
        cerr << "Error: cannot open the named pipe." << endl;
        
        // reclaim the backing file
        unlink(outpipe);
        return 1;
    }


    char buffer[MAX_SIZE];
    char ack[] = "RECEIVED";
    
    cout << "Reader started..." << endl;
    while (true) {
        int bytesread = read(ifd, buffer, MAX_SIZE);
        if (bytesread == -1)
            cerr << "Error: read operation failed!" << endl;
        if (strcmp("Quit", buffer) == 0)
            break;
        cout << buffer << endl;
        write(ofd, ack, sizeof ack);
        // sleep(10);
    }

    // close both file descriptors
    close(ifd);
    close(ofd);

	return 0;
}