#include <stdio.h>
#define __LIBRARY__
#include <unistd.h>
_syscall1(int, iam, const char*, name);
int main(int argc, const char** args){
    int ret = -1;
    if (argc == 2)
    {
        ret = iam(args[1]);
        printf("%d\n", ret);
        printf("input name: %s\n", args[1]);
    }else{
        printf("iam [name]\n");
    }
    return ret;
}