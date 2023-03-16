#include <iostream>
#include <errno.h>      // errno
#include <cstring>      // strerrno
#include <unistd.h>     // read, write
#include <fcntl.h>      // open and oflags

#define MSG_SIZE 1024

using namespace std;

int main() {
    cout << "Reader started..." << endl;
    
    const char * pipe_pathname = "./pipe";
   
    int fd = open(pipe_pathname, O_RDONLY); // oflag for read-only access
    if (fd == -1) {
        cout << "Pipe open failed" << endl; // errno is set so we can check it
        cout << errno << ": " << strerror(errno) << endl << flush;
        exit(1);
    }
    cout << "Named pipe opened for reading..." << endl;
    
    char line[MSG_SIZE] = {0};

    int bytes_read;
    
    // reads up to MSG_SIZE bytes from fd into the buffer
    // note that you might read data written by multiple calls to write
    // so if you expect to receive a certain number of bytes it's better 
    // not to use a large MSG_SIZE
    bytes_read = read(fd, line, MSG_SIZE);
    cout << bytes_read << " bytes are read from the pipe: " << line <<  endl;
    
    // sleep(10);
    
    // bytes_read = read(fd, line + bytes_read, MSG_SIZE);
    bytes_read = read(fd, line, MSG_SIZE);
    cout << bytes_read << " bytes are read from the pipe: " << line <<  endl;
    cout << "Finished reading bytes from the pipe..." << endl;

    // writes up to MSG_SIZE bytes from the buffer to fd
    // write(fd, first, MSG_SIZE);   	
    // write(fd, second, MSG_SIZE);

    // close pipe from the write end
    close(fd);
   
    return 0;
}
