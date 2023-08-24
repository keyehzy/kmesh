#include <stdio.h>
#include <stdlib.h>

int kmesh(int n, int m, double *f)
{
  printf("%d %d\n", n, m);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      printf("%.17g%s",
	     ((double)(i-n+1)) * f[j] / ((double)(n-1)) + 0.5 * f[j],
	     j < m-1 ? "\t" : "\n");
    }
  }
  return 0;
}

int usage(void) {
  printf("usage: ");
  printf("kmesh <entries> [<columns>] [width1 width2 ..]\n\n");
  printf("If optional array is not provided, it is assumed to be a\n");
  printf("column with default width of 1.0.\n\n");
  return 1;
}

int main(int argc, char **argv)
{
  if (argc < 2)
    return usage();

  int entries = atoi(argv[1]);

  if (entries < 1)
    return usage();

  int columns = 1;

  if (argc > 2) {
    columns = atoi(argv[2]);

    if (columns < 1)
      return usage();
  }

  double width[columns];

  if (argc > 3) {
    if (argc < 3 + columns)
      return usage();

    for (int j = 0; j < columns; j++)
      width[j] = atoi(argv[3 + j]);
  } else {
    for (int j = 0; j < columns; j++)
      width[j] = 1;
  }

  return kmesh(entries, columns, width);  
}
