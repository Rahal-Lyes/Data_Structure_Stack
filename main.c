#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node *next;
} node;

// Fonction pour empiler (push)
node *push(node *top, int data) {
    node *newNode = malloc(sizeof(node));
    if (newNode == NULL) {
        newNode->val=data;
        newNode->next=NULL;
        return newNode;
    }
    newNode->val = data;
    newNode->next = top;
    return newNode;
}

// Fonction pour vérifier si la pile est vide
int isEmpty(node *top) {
    return (top == NULL) ? -1 : 1;
}

// Fonction pour dépiler (pop)
node *pop(node *top) {
    if (isEmpty(top)) {
        printf("Stack is empty\n");
        return NULL;
    }
    node *ptr = top;
    top = top->next;
    free(ptr);
    return top;
}

// Fonction pour afficher les éléments de la pile
void print(node *top) {
    if (isEmpty(top)<0) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements are:\n");
    node *ptr = top;
    while (ptr != NULL) {
        printf("%d\n", ptr->val);
        ptr = ptr->next;
    }
    printf("\n");
}

// Fonction pour inverser une pile
node *reverseStack(node *pile1, node *pile2) {
    while (pile1 != NULL) {
        int val = pile1->val;
        pile1 = pop(pile1);
        pile2 = push(pile2, val);
    }
    return pile2;
}

// Fonction pour compter le nombre d'éléments dans la pile
int count(node *top) {
    int count = 0;
    node *ptr = top;
    while (ptr != NULL) {
        count++;
        ptr = ptr->next;
    }
    return count;
}

// Fonction pour cloner une pile
node *cloneStack(node *top) {
    int nmbrElement = count(top); // Nombre d'éléments dans la pile
    int *tab = malloc(nmbrElement * sizeof(int)); // Allocation dynamique du tableau

    // Stocker les valeurs de la pile dans le tableau
    node *temp = top;
    for (int i = 0; i < nmbrElement; i++) {
        tab[i] = temp->val;
        temp = temp->next;
    }

    // Créer la pile clonée
    node *clonedStack = NULL;
    for (int i = nmbrElement - 1; i >= 0; i--) {
        clonedStack = push(clonedStack, tab[i]);
    }

    free(tab); // Libérer la mémoire du tableau
    return clonedStack;
}

int main() {
    node *pile1 = NULL;
    node *pile2 = NULL;

    //Empiler des éléments dans pile1
    pile1 = push(pile1, 5);
    pile1 = push(pile1, 4);
    pile1 = push(pile1, 3);
    pile1 = push(pile1, 2);
    // pile1 = push(pile1, -1);
    pile1 = push(pile1, 0);

    printf("Pile 1:\n");
    print(pile1);

    // Cloner pile1 dans pile3 avant d'inverser
    node *pile3 = cloneStack(pile1);
    printf("Pile 3 (clone de pile 1):\n");
    print(pile3);

    // Inverser pile1 dans pile2
    pile2 = reverseStack(pile1, pile2);
    printf("Pile 2 (inversée):\n");
    print(pile2);

    return 0;
}
