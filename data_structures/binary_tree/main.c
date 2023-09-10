#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* do_create_new_node(int value);
struct Node* do_remove_current(struct Node* node);
struct Node* do_append_node(struct Node* node, int value);
int do_find_node(struct Node* node, int data);
int do_remove_node(struct Node* node, int data);

void do_print_in_order(struct Node* node);
void do_print_pre_order(struct Node* node);
void do_print_pos_order(struct Node* node);

int main() {
    struct Node* my_node = NULL;

    my_node = do_append_node(my_node, 10);
    my_node = do_append_node(my_node, 5);
    my_node = do_append_node(my_node, 7);
    my_node = do_append_node(my_node, 35);
    my_node = do_append_node(my_node, 62);
    my_node = do_append_node(my_node, 23);
    my_node = do_append_node(my_node, 12);
    my_node = do_append_node(my_node, 62);
    my_node = do_append_node(my_node, 53);
    my_node = do_append_node(my_node, 77);
    my_node = do_append_node(my_node, 4);

    printf("(Before removal) Binary Tree in order: ");
    do_print_in_order(my_node);
    printf("\n");
    do_remove_node(my_node, 4);
    printf("Binary Tree in order: ");
    do_print_in_order(my_node);
    return 0;
    printf("\n");
    printf("Binary Tree pre order: ");
    do_print_pre_order(my_node);
    printf("\n");
    printf("Binary Tree pos order: ");
    do_print_pos_order(my_node);
    return 0;
}

// Function to create new node.
struct Node* do_create_new_node(int value) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = value;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// Function to insert a node in Binary Tree.
struct Node* do_append_node(struct Node* node, int value) {
    if (node == NULL) {
        return do_create_new_node(value);
    }
    if (value < node->data) {
        node->left = do_append_node(node->left, value);
    } else if (value > node->data) {
        node->right = do_append_node(node->right, value);
    }
    return node;
}

int do_find_node(struct Node* node, int data){
    if (node->data != data && node->left == NULL && node->right == NULL)
        return 0;
    else if (node->data == data)
        return 1;
    else if (data > node->data)
        return do_find_node(node->right, data);
    else if (data < node->data)
        return do_find_node(node->left, data);
}

struct Node* do_remove_current(struct Node* node){
    struct Node *node_1, *node_2;
    if (node->left == NULL)
    //No child on the right.
    //Point to the child on the left.
    //Treats leaf node and node with a child.
    {
        node_2 = node->right;
        free(node);
        return node_2;
    }
    //Search for the rightmost child of the left subtree
    node_1 = node;
    node_2 = node->left;
    while (node_1 != node)
    {
        node_1 = node_2;
        node_2 = node_2->right;
    }
    //Copies the rightmost child of the left subtree to the location of the node to be removed
    if (node_1 != node)
    {
        node_1->right = node_2->left;
        node_2->left = node->left;
    }
    node_2->right = node->right;
    free(node);
    return node_2;
}

int do_remove_node(struct Node* node, int data){
   if(node == NULL) return 0;
   struct Node* prev = NULL;
   struct Node* current = node;
   while (current != NULL){
        if (data == current->data){
            //Found the knot to be removed. Treat the removal
            if (current == node)
                node = do_remove_current(current);
            else{
                if (prev->right == current)
                    prev->right = do_remove_current(current);
                else
                    prev->left = do_remove_current(current);
            }
            return 1;
        }
        //Continue walking through the tree looking for the node to be removed
        prev = current;
        if (data > current->data)
            current = current->right;
        else
            current = current->left;
    }
}

void do_print_in_order(struct Node* node) {
    if (node != NULL) {
        do_print_in_order(node->left);
        printf("%d ", node->data);
        do_print_in_order(node->right);
    }
}

void do_print_pre_order(struct Node* node) {
    if (node != NULL) {
        printf("%d ", node->data);
        do_print_pre_order(node->left);
        do_print_pre_order(node->right);
    }
}

void do_print_pos_order(struct Node* node) {
    if (node != NULL) {
        do_print_pos_order(node->left);
        do_print_pos_order(node->right);
        printf("%d ", node->data);
    }
}
