#include <stdio.h>

struct BST {
 int key;
 struct BST *left;
 struct BST *right;
};

struct BST bst_pool[1000000];
int i = 0;

void bst_insert(struct BST *bst, int n) {
 struct BST bst_new;
 bst_pool[i].key   = n;
 bst_pool[i].right = NULL;
 bst_pool[i].left  = NULL;

 if (n > bst->key) {
  if (bst->right == NULL) bst->right = &bst_pool[i++];
  else bst_insert(bst->right, n);
 }
 if (n < bst->key) {
  if (bst->left == NULL) bst->left = &bst_pool[i++];
  else bst_insert(bst->left, n);
 }
}

int bst_height(const struct BST *bst) {
 if (bst->left == NULL && bst->right == NULL) return 1;
 if (bst->left != NULL && bst->right == NULL) return bst_height(bst->left) + 1;
 if (bst->left == NULL && bst->right != NULL) return bst_height(bst->right) + 1;

 int hl = bst->left != NULL  ? bst_height(bst->left)  : 0;
 int hr = bst->right != NULL ? bst_height(bst->right) : 0;
 return (hl > hr ? hl : hr) + 1;
}

int main(int argc, char** argv) {
 int n;
 struct BST bst;
 bst.left  = NULL;
 bst.right = NULL;

 scanf("%d", &n);
 if (!n) {
  printf("0\n");
  return 0;
 }
 bst.key = n;

 while (1) {
  scanf("%d", &n);
  if (!n) break;
  bst_insert(&bst, n);
 }

 printf("%d\n", bst_height(&bst));
 return 0;
}
