#include <stdio.h>  
#include <sys/types.h>  
#include <sys/stat.h>  
#include <fcntl.h>  
#include <unistd.h>  
#include <linux/ioctl.h>  
#include <string.h>  
#include <errno.h>  
#include "./hello_mod_ioctl.h"  
  
int main()  
{  
    char outbuf[512];  
    char * myname = "tishion";  
    lang_t langtype = english;  
    int fd = open("/dev/hello", O_RDWR, S_IRUSR|S_IWUSR);  
    if(fd != -1)  
    {  
        write(fd, myname, strlen(myname)+1);  
        langtype = chinese;  
        ioctl(fd, HELLO_IOCTL_SETLANG, &langtype);  
        read(fd, outbuf, 512);  
        printf("langtype=chinese:%s/n", outbuf);  
        memset(outbuf, 0, 512);  
        langtype = pinyin;  
        ioctl(fd, HELLO_IOCTL_SETLANG, &langtype);  
        read(fd, outbuf, 512);      
        printf("langtype=pinyin:%s/n", outbuf);  
        memset(outbuf, 0, 512);  
        ioctl(fd, HELLO_IOCTL_RESETLANG, &langtype);      
        read(fd, outbuf, 512);  
        printf("langtype=english:%s/n", outbuf);  
    }  
    else  
    {  
        perror("Failed at open():");  
    }  
    return 0;  
}  
