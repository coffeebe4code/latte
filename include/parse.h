#pragma once
#include "../include/utils.h"

typedef enum {
  STRING,
  OPAREN,
  CPAREN,
  KEYWORD,
  COMMA,
} token_e;

void parse(char *buffer, Cstr_Array *features, Cstr_Array *deps,
           Cstr_Array *exes);
