#include <iostream>
#include <errno.h>      // errno
#include <cstring>      // strerrno
#include <unistd.h>     // read, write, unlink, usleep
#include <fcntl.h>      // open and oflags
#include <sys/types.h>  // mkfifo
#include <sys/stat.h>   // mkfifo

// #define MSG_SIZE 5

using namespace std;

int main() {
    cout << "Writer started..." << endl;
    
    const char * pipe_pathname = "./pipe";
    // Don't create a pipe in a shared folder between multipass and host OS 
    // You will get the "Operation not permitted" error

    if (mkfifo(pipe_pathname, 0666) == -1) {
        cout << "Cannot make a pipe! Check the pathname." << endl;
        cout << errno << ": " << strerror(errno) << endl << flush;
        exit(1);    // terminate the process
    }
    cout << "Named pipe created" << endl;

   
    int fd = open(pipe_pathname, O_WRONLY); // oflag for write-only access
    if (fd == -1) {
        cout << "Pipe open failed" << endl; // errno is set so we can check it
        cout << errno << ": " << strerror(errno) << endl << flush;
        exit(1);
    }
    cout << "Named pipe opened for writing..." << endl;

    char first[] = "msg1";
    char second[] = " and msg2";
	
    int bytes_written;

    // writes up to MSG_SIZE bytes from the buffer to fd
    // bytes_written = write(fd, first, MSG_SIZE);

    // subtract one from the size if you don't want the null character to be written
    bytes_written = write(fd, first, sizeof first);
    cout << bytes_written << " bytes are written to the pipe: " << first <<  endl;

    /* suspend execution for microsecond intervals */
    // usleep(1000); 
    sleep(2); // 2 seconds
    bytes_written = write(fd, second, sizeof second);
    cout << bytes_written << " bytes are written to the pipe: " << second <<  endl;

    // cout << write(fd, second, MSG_SIZE) << endl;
    cout << "Finished writing bytes to the pipe..." << endl << flush;

    // close pipe from the write end
    close(fd);

    // reclaim the backing file
    unlink(pipe_pathname);
    
    return 0;
}
