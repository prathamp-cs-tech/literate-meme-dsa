#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *next;
};

struct node* createsll() {
    struct node *start = NULL, *p;
    int item;
    printf("Enter elements (-999 to stop): ");
    while (scanf("%d", &item) && item != -999) {
        p = malloc(sizeof(struct node));
        p->info = item;
        p->next = start;
        start = p;
    }
    return start;
}

void display(struct node *start) {
    for (; start; start = start->next) printf("%d ", start->info);
    printf("\n");
}

struct node* insert(struct node *start, int item, int posType) {
    struct node *p = malloc(sizeof(struct node)), *temp = start, *prev = NULL;
    int pos, i;

    p->info = item;

    if (!start || posType == 1) {      
        p->next = start;               
        return p;                      
    }

    if (posType == 3) {                
        while (temp->next) temp = temp->next;
        temp->next = p;
        p->next = NULL;
        return start;
    }

    printf("Enter position: ");
    scanf("%d", &pos);

    for (i = 0; i < pos && temp; i++) {     
        prev = temp;
        temp = temp->next;
    }

    prev->next = p;
    p->next = temp;
    return start;
}

int main() {
    struct node *start = NULL;
    int ch, item, opt;

    while (1) {
        printf("\n1.Create  2.Insert  3.Display  4.Exit\nChoice: ");
        scanf("%d", &ch);

        if (ch == 1) start = createsll();
        else if (ch == 2) {
            printf("Item: ");
            scanf("%d", &item);
            printf("1.Beg  2.Pos  3.End : ");
            scanf("%d", &opt);
            start = insert(start, item, opt);
        }
        else if (ch == 3) display(start);
        else if (ch == 4) break;
        else printf("Invalid.\n");
    }
    return 0;
}
