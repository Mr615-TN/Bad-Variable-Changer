#ifndef UTILS_H
#define UTILS_H

#include <string.h>
#include <errno.h>

#define ERR(msg, stream, ...)                           \
  do {                                                  \
    fprintf(stream, "ERR: " msg "\n", __VA_ARGS__);     \
    exit(EXIT_FAILURE);                                 \
  } while (0)

#endif // UTILS_H
