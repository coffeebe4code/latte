#pragma once
#define CROSSOVER_BS
#include "stdint.h"
#include <dirent.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef FILE *Fd;
typedef const char *Cstr;
typedef struct {
  Cstr *elems;
  size_t count;
} Cstr_Array;
typedef struct {
  Cstr_Array line;
} Cmd;
typedef struct {
  Cmd *elems;
  size_t count;
} Cmd_Array;

#define CSTRS()                                                                \
  { .elems = NULL, .count = 0 }

#define ENDS_WITH(cstr, postfix) cstr_ends_with(cstr, postfix)
#define NOEXT(path) cstr_no_ext(path)
#define JOIN(sep, ...) cstr_array_join(sep, cstr_array_make(__VA_ARGS__, NULL))
#define CONCAT(...) JOIN("", __VA_ARGS__)
#define PATH(...) JOIN(PATH_SEP, __VA_ARGS__)

#if defined(__GNUC__) || defined(__clang__)
#define NOBUILD_PRINTF_FORMAT(STRING_INDEX, FIRST_TO_CHECK)                    \
  __attribute__((format(printf, STRING_INDEX, FIRST_TO_CHECK)))
#else
#define NOBUILD_PRINTF_FORMAT(STRING_INDEX, FIRST_TO_CHECK)
#endif

#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_BLUE "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN "\x1b[36m"
#define ANSI_COLOR_RESET "\x1b[0m"

void VLOG(FILE *stream, Cstr tag, Cstr fmt, va_list args);
void TABLOG(FILE *stream, Cstr tag, Cstr fmt, va_list args);
void INFO(Cstr fmt, ...) NOBUILD_PRINTF_FORMAT(1, 2);
void WARN(Cstr fmt, ...) NOBUILD_PRINTF_FORMAT(1, 2);
void ERRO(Cstr fmt, ...) NOBUILD_PRINTF_FORMAT(1, 2);
void PANIC(Cstr fmt, ...) NOBUILD_PRINTF_FORMAT(1, 2);
void FAILLOG(Cstr fmt, ...) NOBUILD_PRINTF_FORMAT(1, 2);
void DESCLOG(Cstr fmt, ...) NOBUILD_PRINTF_FORMAT(1, 2);
void RUNLOG(Cstr fmt, ...) NOBUILD_PRINTF_FORMAT(1, 2);
void OKAY(Cstr fmt, ...) NOBUILD_PRINTF_FORMAT(1, 2);
