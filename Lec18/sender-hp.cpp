#include <iostream> 
#include <unistd.h> 
#include <fcntl.h> 
#include <sys/types.h> 
#include <sys/stat.h>
#include <string.h>
#define _MSG_MAX_LENGTH 100

using namespace std;

struct header {
  unsigned int len;	// ignoring byte ordering for now
};

// FIXME: check return values for mkfifo(), open(), and write()
int main() {
  const char * pipename = "./sharedch";

  // create a pipe that can be opened by all users
  // for read/write operations
  mkfifo(pipename, 0666);

  // open the write end of the pipe
  int fd = open(pipename, O_WRONLY);

  char msg[_MSG_MAX_LENGTH];
  struct header h = { 0 };
  ssize_t bytes_written;

  while(true){
    memset(msg, 0, _MSG_MAX_LENGTH);
    cin.getline(msg, _MSG_MAX_LENGTH);
    h.len = strlen(msg);
    bytes_written = write(fd, &h, sizeof(h)); // header
    bytes_written = write(fd, msg, h.len);    // payload

    if( strcmp(msg, "quit") == 0 ){
      break;
    }
  }  

  // close pipe from the write end 
  close(fd);
  // reclaim the backing file 
  unlink(pipename);

  return 0;
}

