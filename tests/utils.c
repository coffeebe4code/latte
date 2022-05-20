#define NOBUILD_IMPLEMENTATION
#include "../include/utils.h"
#include "../nobuild.h"

int main() {
  DESCRIBE("utils");
  SHOULDB("Assert 1 == 1", { ASSERT(1 == 1); });
  RETURN();
}
