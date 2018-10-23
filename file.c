#include<sys/types.h>
#include <sys/stat.h>
#include <fcntl.h> // for open
#include <unistd.h> // for close
#include <stdlib.h>
#include <stdio.h>

int main()
{
    // char c;
    /*
    O_RDONLY: read only, O_WRONLY: write only, O_RDWR: read and write,
    O_CREAT: create file if it doesn’t exist, O_EXCL: prevent creation if it already exists
    */
    size_t filedesc = open("testfile.txt", O_RDWR | O_CREAT);
    if(filedesc > 0)
        printf("file has been opened\n");

    // size_t read (int fd, void* buf, size_t cnt);
    // printf("%lu\n", read (filedesc, "hello", 40000) );

    // size_t write(int filedesc, const void *buf, size_t nbytes);
    // printf("%lu\n", write(filedesc, "hello", 40000) );

    filedesc = close(filedesc);
    printf("%lu\n", filedesc);
    if(! filedesc)
        printf("file has been closed\n");

    return 0;

}
