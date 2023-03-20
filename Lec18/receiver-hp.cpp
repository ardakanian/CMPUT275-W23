#include <iostream> 
#include <unistd.h> 
#include <fcntl.h> 
#include <sys/types.h> 
#include <sys/stat.h>
#include <string.h>
#define _MSG_MAX_LENGTH 100

using namespace std;

struct header {
  unsigned int len;     // ignoring byte ordering for now
};

// FIXME: check return values for mkfifo(), open(), and read()
int main() {

  const char * pipename = "./sharedch";

  // mkfifo(pipename, 0666); // all users can read and write 
  int fd = open(pipename, O_RDONLY); // open for read-only access

  char msg[_MSG_MAX_LENGTH];
  struct header h = { 0 };

  while(true){
    memset(msg, 0, _MSG_MAX_LENGTH);

    read(fd, &h, sizeof(h));   // header
    read(fd, msg, h.len);      // payload
    cout << msg << endl;
    if( strcmp(msg, "quit") == 0 ){
      break;
    }
  }

  // close pipe from the write end 
  close(fd);

  // reclaim the backing file 
  // unlink(pipename);

  return 0;
}

