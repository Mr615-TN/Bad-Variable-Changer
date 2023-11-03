#include <stdio.h>
#include <stdlib.h>

#define ERR(msg, stream, ...)                           \
  do {                                                  \
    fprintf(stream, "ERR: " msg "\n", __VA_ARGS__);     \
    exit(EXIT_FAILURE);                                 \
  } while (0)

void usage(const char *prog_name)
{
  printf("Usage:\n");
  printf("  ./%s <filepath>\n", prog_name);
  exit(EXIT_SUCCESS);
}

int main(int argc, char **argv)
{
  const char *prog_name = argv[0];
  if (argc != 2) {
    usage(prog_name);
  }

  const char *filepath = argv[1];
  FILE *fp = fopen(filepath, "r");
  if (!fp) {
    ERR("could not open filepath: %s", stderr, filepath);
    fclose(fp);
  }

  fclose(fp);
  return 0;
}
