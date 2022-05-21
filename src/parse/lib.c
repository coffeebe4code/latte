#include "../../include/parse.h"
#include "ctype.h"
#include "stdio.h"
#include "string.h"

#define KEYWORD_LENGTH 3

// clang-format off
static char *keyword_list[KEYWORD_LENGTH] = {
  "DEPS", 
  "EXE",
  "FEATURE",
};
static int keyword_len[KEYWORD_LENGTH] __attribute__((unused)) = {
  4,
  3,
  7,
};
// clang-format on

size_t skip_whitespace(char *data) {
  size_t len = 1;
  while (*++data != '\0') {
    if (*data == ' ') {
      len++;
    } else {
      break;
    }
  }
  return len;
}

token_e tokenize_string(char *data, int *len) {
  int cont = 1;
  token_e tok = ERROR;
  while (*++data != '\0' && cont) {
    switch (*data) {
    case '\\':
      (*len)++;
      if (*++data != '\0') {
        switch (*data) {
        case '"':
          tok = STRING;
          cont = 0;
          break;
        default:
          (*len)++;
          break;
        }
      } else {
        cont = 0;
      }
      break;
    case '"':
      tok = STRING;
      cont = 0;
      break;
    default:
      (*len)++;
      break;
    }
  }
  return tok;
}

size_t word_len_check(char *data) {
  int next = 1;
  size_t len = 1;
  while (*++data != '\0' && next) {
    if (isalnum(*data)) {
      len++;
    } else {
      switch (*data) {
      case '_':
      case '-':
        len++;
        break;
      default:
        next = 0;
        break;
      }
    }
  }
  return len;
}

token_e tokenize_word(char *data, int *len) {
  token_e token;
  *len = word_len_check(data);
  token = KEYWORD;
  for (size_t i = 0; i < KEYWORD_LENGTH; i++) {
    if (keyword_len[i] == *len) {
      if (strncmp(keyword_list[i], data, *len) == 0) {
        token = (token_e)i;
      }
    }
  }
  return token;
}

token_e token_next(char *data, int *len) {
  *len = 0;
  token_e token;
  if (isalpha(*data)) {
    token = tokenize_word(data, len);
  } else {
    switch (*data) {
    case ' ':
      token = WHITESPACE;
      *len = (int)skip_whitespace(data);
      break;
    case '"':
      token = tokenize_string(data, len);
      break;
    case '(':
      *len = 1;
      token = OPAREN;
      break;
    case ')':
      *len = 1;
      token = CPAREN;
      break;
    case ',':
      *len = 1;
      token = WHITESPACE;
      break;
    case ';':
      *len = 1;
      token = WHITESPACE;
      break;
    case '\n':
      token = WHITESPACE;
      *len = 1;
      break;
    case EOF || '\0':
      *len = 0;
      token = EMPTY;
      break;
    default:
      if (strcmp(data, "") == 0) {
        *len = 0;
        token = EMPTY;
      } else {
        *len = 1;
        token = EMPTY;
      }
      break;
    }
  }
  return token;
}

void parse(char *buffer, Cstr_Array *features, Cstr_Array *deps,
           Cstr_Array *exes) {
  int len = 0;
  int cont = 1;
  token_e curr = EMPTY;
  while (cont) {
    curr = token_next(buffer, &len);
    if (curr == EMPTY || curr == ERROR) {
      cont = 0;
      break;
    }
    if (curr != KEYWORD) {
      PANIC("Need one of DEPS, FEATURE, EXE");
    }
    buffer += len;
    curr = token_next(buffer, &len);
    if(curr !=
  }
  if (curr == ERROR) {
    PANIC("Invalid token in config file");
  }
}
