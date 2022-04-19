/**
 * @Author Thomas "Thomassino" Vitulovič && Květoslav Cimbálovič
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX 1000
//přidání, za/před konkrétní prvek, smazání prvku před/za, modifikace dat, vyvážení stromu


typedef struct t_Node {
    char key;
    int value;
    struct t_Node *left;
    struct t_Node *right;
} t_Node_t;

void insert_key(t_Node_t **node, int given_value, char key);
void inord_trav(t_Node_t *root);
void preord_trav(t_Node_t *root);
void postord_trav(t_Node_t *root);
void delete(t_Node_t **root, char mark);
t_Node_t *newNode(int item);
t_Node_t *find_MinValue(t_Node_t *node);
void del_node(t_Node_t *root, int marker);
t_Node_t *search_tree(t_Node_t **root, char mark);
void replace(t_Node_t *target, t_Node_t **tree);


t_Node_t *newNode(int item)         //creating new node
{
    t_Node_t *tmp = (t_Node_t *)malloc(sizeof(t_Node_t));
    if(tmp != NULL) {
        tmp->value = item;
        tmp->left = tmp->right = NULL;
        tmp->key = "a";
    }
    return tmp;
}

void inord_trav(t_Node_t *root)     //inorder traversal w/recursion
{
    if(root != NULL) {
        inord_trav(root->left);
        printf("%d\n", root->value);
        inord_trav(root->right);
    }
}

void preord_trav(t_Node_t *root)
{
    if(root != NULL) {
        printf("%d\n", root->value);
        preord_trav(root->left);
        preord_trav(root->right);
    }
}

void postord_trav(t_Node_t *root)
{
    if(root != NULL) {
        postord_trav(root->left);
        postord_trav(root->right);
        printf("%d\n", root->value);
    }
}

t_Node_t *search_tree(t_Node_t **root, char mark)
{
    if(*root == NULL) {
        return *root;
    }

    t_Node_t *tmp = *root;

    if(mark < tmp->key) {
        return search_tree(&tmp->left, mark);
    }

    if(mark > tmp->key) {
        return search_tree(&tmp->right, mark);
    }

    if(mark == tmp->key) {
        return tmp;
    }
}

void replace(t_Node_t *target, t_Node_t **tree) {
    if((target->right == NULL && target->left != NULL) || (target->right != NULL && target->left == NULL)){
        target->key = (*tree)->key;
        target->value = (*tree)->value;
        t_Node_t *tmp = *tree;
        if((*tree)->left == NULL)
            *tree = (*tree)->right;
        else
            *tree = (*tree)->left;
        free(tmp);
        return;
    }
    if((*tree)->right == NULL){
        target->key = (*tree)->key;
        target->value = (*tree)->value;
        t_Node_t *tmp = *tree;
        (*tree) = (*tree)->right;
        free(tmp);
        return;
    }
    replace(target, &(*tree)->right);
}

void delete(t_Node_t **root, char mark)
{
    if(*root == NULL) {
        return;
    }

    if((*root)->left == NULL && (*root)->right == NULL && (*root)->key != mark) {
        return;
    }

    t_Node_t **tmp = root;

    if((*tmp)->key == mark) {
       if((*tmp)->left == NULL) {
           if((*tmp)->right == NULL) {
               free(*tmp);
               *tmp = NULL;
           }
           else {
               replace(*tmp, &(*tmp)->right);
           }
       }

       else {
           replace(*tmp, &(*tmp)->left);
       }
       return;
    }

    if((*tmp)->key > mark) {
        delete(&(*tmp)->left, mark);
    }

    else {
        delete(&(*tmp)->right, mark);
    }
}

void insert_key(t_Node_t **node, int given_value, char key)      //inserting node with given data value
{
    if(*node == NULL) {
        *node = newNode(given_value);
        return;
    }

    t_Node_t *tmp = *node;

    if(key < tmp->key) {
        insert_key(&tmp->left, given_value,key);
    }
    else if(key > tmp->key) {
        insert_key(&tmp->right, given_value,key);
    }
}

int counter(t_Node_t **root)
{
    if(*root == NULL) {
        return 0;
    }

    return 1 + counter(&(*root)->left) + counter(&(*root)->right);
}

void startBT(t_Node_t **root)
{
    char *array = (char *)malloc(sizeof(char) * counter(root));
}

void balance_tree(t_Node_t **root)
{

    int n = counter(root);

}

int main()
{
    t_Node_t *root = NULL;

    //creating root
    insert_key(&root, 50,'h');

    //creating childs
    insert_key(&root, 30,'b' );
    insert_key(&root, 20, 'a');
    insert_key(&root, 40, 'c');
    insert_key(&root, 70,'j');
    insert_key(&root, 60,'i');
    insert_key(&root, 80,'k');

    //print in inorder traversal
    printf("Inorder traversal of the given tree\n\n");
    inord_trav(root);

    /*//deleting 20
    printf("\nDelete 20\n");
    del_node(root, 20);
    printf("\nPrinting modified tree\n\n");
    inord_trav(root);

    //deleting 30
    printf("\nDelete 30\n");
    del_node(root, 30);
    printf("\nPrinting modified tree\n\n");
    inord_trav(root);

*/    //printf("%p\n", search_tree(root, 40));
    return 0;
}

