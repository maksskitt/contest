#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int is_opening(char c) {
 return c == '(' || c == '[' || c == '{';
}

int is_closing(char c) {
 return c == ')' || c == ']' || c == '}';
}

int are_brackets_pair(char c1, char c2) {
 return (c1 == '(' && c2 == ')') ||
        (c1 == '[' && c2 == ']') ||
        (c1 == '{' && c2 == '}');
}

int are_brackets_valid(const char* s, int len) {
 char* stack = malloc(len * sizeof(*stack));
 int top = -1;
 char c, oc;
 for (int i = 0; i < len; i++) {
  c = s[i];
  if (is_opening(c)) stack[++top] = c;
  else if (is_closing(c)) {
   if (top == -1) {
    free(stack);
    return 0;
   }

   oc = stack[top--];
   if (!are_brackets_pair(oc, c)) {
    free(stack);
    return 0;
   }
  }
 }

 free(stack);
 return top == -1;
}

int main(int argc, char** argv) {
 char in[100001];
 scanf("%s", in);

 if (are_brackets_valid(in, strlen(in))) puts("yes");
 else puts("no");

 return 0;
}
