#include <fcntl.h> // for open
#include <unistd.h> // for close
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
    char * c = "hello";
    /*
    O_RDONLY: read only, O_WRONLY: write only, O_RDWR: read and write,
    O_CREAT: create file if it doesn’t exist, O_EXCL: prevent creation if it already exists
    */
    size_t filedesc = open("testfile.txt", O_RDWR | O_CREAT);
    if(filedesc > 0){
        printf("file has been opened\n");
    }
    else{
      printf("error opening file\n");
    }

    // size_t write(int filedesc, const void *buf, size_t nbytes);
    if(write (filedesc, c, strlen(c)) >= 0){
      printf("file has been written\n");
    }
    else{
      printf("error writing file\n");
    }

    // size_t read (int fd, void* buf, size_t cnt);
    if(read (filedesc, c, strlen(c)) >= 0){
      printf("file has been read\n");
    }
    else{
      printf("error reading file\n");
    }

    if(close(filedesc) == 0){
      printf("file has been closed\n");
    }
    else{
      printf("error closing file\n");
    }
    return 0;

}
