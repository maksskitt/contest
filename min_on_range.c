#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
 int n, k;
 scanf("%d %d", &n, &k);

 int* nums = (int*)malloc(2 * n * sizeof(int));
 int* mins = nums + n;
 for (int i = 0; i < n; i++) scanf("%d", &nums[i]);

 for (int i = 0, start = 0, end = 0; i < n; i++) {
  if (start < end && i - mins[start] > k - 1) start++;
  while (end > start && nums[i] <= nums[mins[end - 1]]) end--;
  mins[end++] = i;
  if (i >= k - 1) printf("%d\n", nums[mins[start]]);
 }

 free(nums);
 return 0;
}
