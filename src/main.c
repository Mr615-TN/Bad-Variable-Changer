#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./include/utils.h"

void usage(const char *prog_name)
{
  printf("Usage:\n");
  printf("  %s <filepath>\n", prog_name);
  exit(EXIT_SUCCESS);
}

char *get_chars_from_src(FILE *fp)
{
  // Find the size of the file
  fseek(fp, 0, SEEK_END);
  long file_size = ftell(fp);
  rewind(fp);

  char *file_data = (char *)malloc(file_size + 1);

  if (!file_data) {
    return NULL;
  }

  // Read the contents of the file into the allocated memory
  size_t bytes_read = fread(file_data, 1, file_size, fp);

  // Error reading the file
  if (bytes_read != (size_t)file_size) {
    free(file_data);
    return NULL;
  }

  file_data[file_size] = '\0';

  return file_data;
}

int main(int argc, char **argv)
{
  const char *prog_name = argv[0];
  if (argc < 2) {
    usage(prog_name);
  }

  const char *filepath = argv[1];
  FILE *fp = fopen(filepath, "r");
  if (!fp) {
    ERR("could not open filepath: %s", stderr, filepath);
    fclose(fp);
  }

  char *file_data = get_chars_from_src(fp);
  if (!file_data) {
    ERR("Could not read file data. Reason: %s",
        stderr, strerror(errno));
  }

  fclose(fp);
  return 0;
}
