#define NOBUILD_IMPLEMENTATION
#include "../include/parse.h"
#include "../nobuild.h"

int main() {
  DESCRIBE("parse");
  SHOULDB("Assert 1 == 1", { ASSERT(1 == 1); });
  RETURN();
}
