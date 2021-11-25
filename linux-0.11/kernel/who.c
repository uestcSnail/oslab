#include <errno.h>
#include <string.h>
#include <asm/segment.h>

#define MAX_SIZE 23

char identity[MAX_SIZE + 1] = "";
char name_size = 0;

int sys_iam(const char* name) {
  int i = 0, count = 0;
  for (count = 0; get_fs_byte(name + count); ++count);
  if (count > MAX_SIZE) return -EINVAL;
  name_size = count;
  for (i = 0; i < count; ++i) identity[i] = get_fs_byte(name + i);
  return name_size;
}

int sys_whoami(char* name, unsigned int size){
  int i = 0;
  if (size < name_size) return -EINVAL;
  for (i = 0; i < name_size; ++i) put_fs_byte(identity[i], name + i);
  return name_size;
}
