#include <stdio.h>
#include <stdlib.h>

typedef struct node node;
struct node {
    node* n;
    char c;
};
node* newnode() {
    return (node*) malloc(sizeof(node));
}
node* prepend(node* p, node* n) {
    p->n = n;
    return p;
}

void freelist(node* n) {
    if (n) {
        freelist(n->n);
        free(n);
    }
}

void printlist(node* n) {
    if (n) {
        printlist(n->n);
        printf("%c", n->c);
    }
}

int getsize(node* n) {
    int i = 1;
    while(n = n->n) {i++;}
    return i;
}
node* get(node* n, int i) {
    while (n && i--) {n = n->n;}
    return n;
}
node* insertnode(node* p, node* n) {
    n->n = p->n;
    p->n = n;
    return p;
}
node* removenode(node* p, node* n) {
    while (p->n != n) {
        p = p->n;
        if (p->n == 0) {return 0;}
    }
    p->n = n->n;
    return n;
}

int main(int argc, char** argv) {
    printf("testcases:\n");
    node* N[10];
    N[0] = newnode();
    N[1] = prepend(newnode(), N[0]);
    N[2] = prepend(newnode(), N[1]);
    N[3] = prepend(newnode(), N[2]);
    N[0]->c = 'a';
    N[1]->c = 'b';
    N[2]->c = 'c';
    N[3]->c = 'd';
    printlist(N[3]);
    printf("\n%d\n", getsize(N[3]));
    N[4] = newnode();
    N[4]->c = 'e';
    N[4] = prepend(N[0], N[4]);
    printlist(N[3]);
    printf("\n%d\n", getsize(N[3]));
    printf("\n%c\n", get(N[3], 3)->c);
    removenode(N[3], get(N[3], 3));
    printlist(N[3]);
    insertnode(get(N[3], 2), N[0]);
    printlist(N[3]);

    return 0;
} 