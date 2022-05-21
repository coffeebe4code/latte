#define NOBUILD_IMPLEMENTATION
#define WITH_MOCKING
#define CROSSOVER_BS
#include "../include/parse.h"
#include "../nobuild.h"

int main() {
  DESCRIBE("parse");
  SHOULDB("Assert 1 == 1", { ASSERT(1 == 1); });
  RETURN();
}
