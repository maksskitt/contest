#include <stdio.h>
#include <stdlib.h>

int comp(const void* a_ptr, const void* b_ptr) {
 int a = *(int*)a_ptr, b = *(int*)b_ptr;
 if (a < b) return -1;
 else if (a == b) return 0;
 return 1;
}

int count(const int* arr, int len, int n) {
 int l = 0, r = len;
 while (l < r) {
  int m = l + (r - l) / 2;
  if (arr[m] < n) l = m + 1;
  else r = m;
 }
 return l;
}

int main(int argc, char** argv) {
 int n, m;
 scanf("%d %d", &n, &m);

 int* ranges = (int*)malloc(2 * n * sizeof(int));
 int* r_start = ranges;
 int* r_end = ranges + n;

 for (int i = 0, r, l; i < n; i++) {
  scanf("%d %d", &l, &r);
  if (r > l) {
   r_end[i] = r;
   r_start[i] = l;
  }
  else {
   r_end[i] = l;
   r_start[i] = r;
  }
 }
 qsort(r_start, n, sizeof(int), comp);
 qsort(r_end, n, sizeof(int), comp);

 for (int i = 0, d; i < m; i++) {
  scanf("%d", &d);
  printf("%d ", count(r_start, n, d + 1) - count(r_end, n, d));
 }

 free(ranges);
 return 0;
}
