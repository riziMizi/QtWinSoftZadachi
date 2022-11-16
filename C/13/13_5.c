#include <stdio.h>
#include <stdlib.h>

struct node {
    int key;
    struct node *left, *right;
};

struct node* newNode(int item);
struct node* insert(struct node* node, int key);
struct node* minValueNode(struct node* node);
struct node* deleteNode(struct node* root, int key);

int main()
{
    int n;
    int i;
    int value;
    int deleteValue;
    struct node *root = NULL;

    printf("Vnesete broj na elementi na drvoto: ");
    scanf("%d", &n);

    for(i = 0; i < n; ++i)
    {
        printf("Vnesete element vo drvoto: ");
        scanf("%d", &value);
        root = insert(root, value);
    }

    printf("Drvoto vo inorder izgleda vaka: \n");
    inorder(root);

    printf("\nVnesete koj element da bide izbrishan: ");
    scanf("%d", &deleteValue);
    root = deleteNode(root, deleteValue);
    inorder(root);
    return 0;
}

struct node* newNode(int item)
{
    struct node* temp
        = (struct node*)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

void inorder(struct node* root)
{
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

struct node* insert(struct node* node, int key)
{
    if (node == NULL)
        return newNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else
        node->right = insert(node->right, key);

    return node;
}

/* Ovaa funkcija se koristi vo slucaj elementot sto sakame
da go izbrisheme ima dve deca. Ovaa funkcija go vraka najmaliot element
vo levoto poddrvo, odnosno najleviot element vo levoto poddrvo.
*/
struct node* minValueNode(struct node* node)
{
    struct node* current = node;

    //dvizi se dodeka ne stigneme do najleviot element
    while (current && current->left != NULL)
        current = current->left;

    return current;
}

// Funkcija za brishenje na elementi vo drvoto
struct node* deleteNode(struct node* root, int key)
{
    // Dokolku drvoto e prazno nema shto da se brishe
    if (root == NULL)
        return root;

  // Ako vrednosta sto sakame da ja izbrisheme e pomala
  // od vrednosta na root dvizi se levo po drvoto
    if (key < root->key)
        root->left = deleteNode(root->left, key);

  // Ako vrednosta sto sakame da ja izbrisheme e pogolema
  // od vrednosta na root dvizi se desno po drvoto
    else if (key > root->key)
        root->right = deleteNode(root->right, key);

    // Koga ke ja najdeme vrednosta sto ja barame
    else {
        // Jazol sto nema deca ili ima samo edno dete
        // Dokolku nema levo dete smesti go desnoto dete
        // vo temp i izbrishi go elementot na root.
        if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        // Dokolku nema desno dete smesti go levoto dete
        // vo temp i izbrishi go elementot na root.
        else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }

        //Dokolku stigneme do ovde znachi deka jazolot ima dve deca

        //Smesti go vo temp jazolot so najmala vrednost
        struct node* temp = minValueNode(root->right);

        //smesti ja vrednosta na najmaliot jazol vo root.
        root->key = temp->key;

        //Izbrishi go najmaliot jazol.
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}
