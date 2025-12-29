#include <stdio.h>
#include <stdlib.h>

struct node{
    int info;
    struct node *next;
};

struct node *push(struct node *top, int x){
    struct node *p = malloc(sizeof(struct node));
    p->info = x;
    p->next = top;
    return p;
}

struct node *pop(struct node *top){
    if(!top){
        printf("Empty\n");
        return top;
    }
    struct node *t = top;
    top = top->next;
    free(t);
    return top;
}

void disp(struct node *p){
    while(p){
        printf("%d ", p->info);
        p = p->next;
    }
    printf("\n");
}

struct node *enqueue(struct node *rear, struct node **front, int x){
    struct node *p = malloc(sizeof(struct node));
    p->info = x;
    p->next = NULL;

    if(!*front){
        *front = rear = p;
    } else {
        rear->next = p;
        rear = p;
    }
    return rear;
}

struct node *dequeue(struct node *front, struct node **rear){
    if(!front){
        printf("Empty\n");
        return front;
    }
    struct node *t = front;
    front = front->next;

    if(!front)
        *rear = NULL;

    free(t);
    return front;
}

int main(){
    struct node *top = NULL, *front = NULL, *rear = NULL;
    int ch, x;

    while(1){
        printf("\n1.Push 2.Pop 3.D.Stack 4.EnQ 5.DeQ 6.D.Queue 7.Exit\nChoice: ");
        scanf("%d", &ch);

        if(ch == 1){
            scanf("%d", &x);
            top = push(top, x);
        }
        else if(ch == 2)
            top = pop(top);
        else if(ch == 3)
            disp(top);
        else if(ch == 4){
            scanf("%d", &x);
            rear = enqueue(rear, &front, x);
        }
        else if(ch == 5)
            front = dequeue(front, &rear);
        else if(ch == 6)
            disp(front);
        else
            break;
    }
    return 0;
}
