#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* do_create_new_node(int value);
struct Node* do_append_node(struct Node* node, int value);
int do_find_node(struct Node* node, int data);
int do_remove_node(struct Node* node, int data);
void do_call_node_remover(struct Node* node, int data);
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

    do_print_in_order(my_node);
    printf("\n");
    int x  = do_find_node(my_node, 7);
    printf("\nResult -> %d\n", x);
    do_call_node_remover(my_node, 7);


    printf("Binary Tree in order: ");
    do_print_in_order(my_node);
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
        return -1;
    if (node->data == data)
        return 1;
    else if (data > node->data)
        do_find_node(node->right, data);
    else if (data < node->data)
        do_find_node(node->left, data);
}

int do_remove_node(struct Node* node, int data){
    if (node->data == data && node->left == NULL && node->left == NULL) {
        printf("\nRemovi node -> %d\n", node);
        return 1;
    }
    else if (data > node->data) {
        if (do_remove_node(node->right, data) > 0){
            node->right = NULL;
            return -1;
        }
    } else if (data < node->data) {
        if (do_remove_node(node->left, data) > 0)
            node->left = NULL;
    }
    else{
        return -1;
    }
}

void do_call_node_remover(struct Node* node, int data){
    if (do_find_node(node, data) > 0)
        do_remove_node(node, data);
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
