#include <stdio.h>
#define __LIBRARY__
#include <unistd.h>
_syscall2(int, whoami, char*, name, unsigned int, size);

int main(){
    char name[24];
    char ret = whoami(name, 24);
    printf("%d\n", ret);
    if (ret > 0) printf("%s\n ret=%d", name);
    return 0;
}