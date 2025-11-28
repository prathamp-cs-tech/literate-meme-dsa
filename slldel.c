#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *next;
};

struct node* create() {
    struct node *start = NULL, *p;
    int x;
    printf("Enter elements (-999 to stop): ");
    while (scanf("%d",&x) && x != -999) {
        p = malloc(sizeof(struct node));
        p->info = x;
        p->next = start;
        start = p;
    }
    return start;
}

void display(struct node *start) {
    if (!start) { printf("Empty\n"); return; }
    while (start) { printf("%d ", start->info); start = start->next; }
    printf("\n");
}

struct node* delete_first(struct node *start) {
    if (!start) { printf("Empty\n"); return NULL; }
    struct node *temp = start;
    start = start->next;
    free(temp);
    return start;
}

struct node* delete_last(struct node *start) {
    if (!start) return NULL;
    if (!start->next) { free(start); return NULL; }

    struct node *temp = start, *prev = NULL;
    while (temp->next) { prev = temp; temp = temp->next; }
    prev->next = NULL;
    free(temp);
    return start;
}

struct node* delete_specific(struct node *start, int key) {
    if (!start) return NULL;
    if (start->info == key) return delete_first(start);

    struct node *temp = start, *prev = NULL;
    while (temp && temp->info != key) { prev = temp; temp = temp->next; }
    if (!temp) { printf("Not found\n"); return start; }

    prev->next = temp->next;
    free(temp);
    return start;
}

int main() {
    struct node *start = NULL;
    int ch, key;

    while (1) {
        printf("\n1.Create 2.Delete First 3.Delete Specific 4.Delete Last 5.Display 6.Exit\nChoice: ");
        scanf("%d", &ch);

        if (ch == 1) start = create();
        else if (ch == 2) start = delete_first(start);
        else if (ch == 3) { printf("Key: "); scanf("%d",&key); start = delete_specific(start, key); }
        else if (ch == 4) start = delete_last(start);
        else if (ch == 5) display(start);
        else if (ch == 6) break;
        else printf("Invalid\n");
    }
}
