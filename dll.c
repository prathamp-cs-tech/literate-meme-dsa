#include <stdio.h>
#include <stdlib.h>

struct Node {
    struct Node *prev;
    int info;
    struct Node *next;
};

struct Node *start = NULL;

void create(int x) {
    struct Node *new = malloc(sizeof(struct Node)), *t;
    new->info = x;
    new->prev = new->next = NULL;

    if (start == NULL)
        start = new;
    else {
        t = start;
        while (t->next != NULL) t = t->next;
        t->next = new;
        new->prev = t;
    }
}


void insertLeft(int key, int x) {
    struct Node *t = start, *new;
    while (t && t->info != key) t = t->next;
    if (!t) return;

    new = malloc(sizeof(struct Node));
    new->info = x;
    new->next = t;
    new->prev = t->prev;

    if (t->prev) t->prev->next = new;
    else start = new;

    t->prev = new;
}

void deleteNode(int x) {
    struct Node *t = start;
    while (t && t->info != x) t = t->next;
    if (!t) return;

    if (t->prev) t->prev->next = t->next;
    else start = t->next;

    if (t->next) t->next->prev = t->prev;

    free(t);
}


void display() {
    struct Node *t = start;
    while (t) {
        printf("%d ", t->info);
        t = t->next;
    }
    printf("\n");
}


int main() {
    int ch, x, key;

    while (1) {
        printf("\n1.Create 2.InsertLeft 3.Delete 4.Display 5.Exit\n");
        scanf("%d", &ch);

        switch (ch) {
            case 1: printf("Enter value (-1 to stop): ");
                    while (scanf("%d", &x), x != -1) create(x);
                    break;
            case 2: printf("Enter to the left which item and what value: ");
                    scanf("%d%d", &key, &x);
                    insertLeft(key, x);
                    break;
            case 3: printf("Enter value to delete: ");
                    scanf("%d", &x);
                    deleteNode(x);
                    break;
            case 4: display(); break;
            case 5: exit(0);
        }
    }
}
