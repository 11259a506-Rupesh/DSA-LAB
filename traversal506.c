#include <stdio.h>
#include <stdlib.h>
struct Node {
int data;
struct Node *left, *right;
};
struct Node *createNode(int value) {
struct Node *newNode = (struct Node *) malloc(sizeof(struct Node));
newNode->data = value;
newNode->left = newNode->right = NULL;
return newNode;
}
struct Node *insert(struct Node *root, int value) {
if (root == NULL)
return createNode(value);
if (value < root->data)
root->left = insert(root->left, value);
else if (value > root->data)
root->right = insert(root->right, value);
return root;
}
void inorder(struct Node *root) {
if (root == NULL) return;
inorder(root->left);
printf("%d ", root->data);
inorder(root->right);
}
void preorder(struct Node *root) {
if (root == NULL) return;
printf("%d ", root->data);
preorder(root->left);
preorder(root->right);
}
void postorder(struct Node *root) {
if (root == NULL) return;
postorder(root->left);
postorder(root->right);
printf("%d ", root->data);
}
int main() {
struct Node *root = NULL;
int n, value;
printf("Enter number of nodes: ");
scanf("%d", &n);
printf("Enter %d values: ", n);
for (int i = 0; i < n; i++) {
scanf("%d", &value);
root = insert(root, value);
}
printf("\nIn-order traversal: ");
inorder(root);
printf("\nPre-order traversal: ");
preorder(root);
printf("\nPost-order traversal: ");
postorder(root);
printf("\n");
return 0;
}
Sample Input / Output
Input:
Enter number of nodes: 7
Enter 7 values: 50 30 70 20 40 60 80

