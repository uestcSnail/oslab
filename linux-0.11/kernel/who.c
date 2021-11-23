#include <errno.h>
#include <string.h>
#include <asm/segment.h>

static char identity[25] = "none";
static char name_size = 4;

int sys_iam(const char* name) {
  int i = 0, count = 0;
  char tmp[25];
  for (count = 0; count < 24 &&(tmp[count] = get_fs_byte(name + count)); ++count);
  if (count >= 24) {
    errno = EINVAL;
    return -1;
  }
  name_size = count;
  for (i = 0;identity[i] = tmp[i]; ++i);
  return name_size;
}

int sys_whoami(char* name, unsigned int size){
  int i = 0;
  if (size < name_size)
  {
      errno = EINVAL;
      return -1;
  }
  for (i = 0; i < name_size; ++i)
  {
      // name[i] = identity[i];
      put_fs_byte(identity[i], name + i);
  }
  return name_size;
}
