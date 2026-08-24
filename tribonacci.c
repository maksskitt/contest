#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
 int n;
 scanf("%d", &n);

 int* seq_nums = malloc(n * sizeof(*seq_nums));

 seq_nums[0] = 2;
 seq_nums[1] = 4;
 seq_nums[2] = 7;
 for (int i = 3; i < n; i++)
  seq_nums[i] = seq_nums[i - 3] + seq_nums[i - 2] + seq_nums[i - 1];

 printf("%d", seq_nums[n - 1]);

 return 0;
}
