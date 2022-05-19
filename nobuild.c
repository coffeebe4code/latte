#define NOBUILD_IMPLEMENTATION
#define CC "clang"
#define CFLAGS "-Wall", "-Werror", "-Wextra", "-std=c11"
#include "./nobuild.h"

int main(int argc, char **argv) {
  EXE("latte", "-lpthread");
  BOOTSTRAP(argc, argv);
  return 0;
}
