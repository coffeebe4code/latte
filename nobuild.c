#define NOBUILD_IMPLEMENTATION
#define CC "clang"
#define CFLAGS "-Wall", "-Wextra", "-std=c11", "-pthread"
#include "./nobuild.h"

int main(int argc, char **argv) {
  FEATURE("utils");
  FEATURE("parse");
  DEPS("parse", "utils");
  EXE("barista", "parse", "utils");
  BOOTSTRAP(argc, argv);
  return 0;
}
