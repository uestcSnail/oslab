#include <stdio.h>
#define __LIBRARY__
#include <unistd.h>
_syscall2(int, whoami, char*, name, unsigned int, size);

int main(){
    char name[24];
    char ret = whoami(name, 24);
    if (ret > 0)
    {
        printf("%s\n", name);
    }
    return 0;
}