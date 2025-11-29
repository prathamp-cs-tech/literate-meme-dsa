#include <stdio.h>
#include <stdlib.h>

struct node{
    int info;
    struct node * next;
};

struct node * createsll() {
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

struct node *sortlist(struct node *start){
    struct node *p1, *p2, *temp;
    if (start==NULL || start->next==NULL)    
        return start;
    p1=start;
    while(p1!=NULL){
        p2=p1->next;
        while(p2!=NULL){
            if(p1->info>p2->info){
                int temp;
                temp = p1->info;
                p1->info = p2->info;
                p2->info = temp;
            }
            p2=p2->next;
        }
        p1=p1->next;            
    }
    return start;
}

struct node * reverseList(struct node * start){
    struct node *prev=NULL, *curr=start, *nextNode;
    while(curr!=NULL){
        nextNode=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nextNode;
    }
    return prev;
}

struct node * concatList(struct node * start1, struct node * start2){
    struct node * temp;
    if(start1==NULL){
        return start2;
    }
    else if(start2==NULL){
        return start1;
    }
    temp=start1;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=start2;
    return start1;
}

int main() {
    struct node *start1 = NULL, *start2 = NULL;
    int ch, opt;

    while (1) {
        printf("\n1.Create 2.Display 3.Sort 4.Reverse 5.Concat 6.Exit\nChoice: ");
        scanf("%d", &ch);

        if (ch == 1){
            printf("1.sll-1 2.sll-2: ");
            scanf("%d",&opt);
            if (opt==1) start1 = createsll();
            else if(opt==2) start2 = createsll();
        }
        else if (ch == 2){
            printf("1.sll-1 2.sll-2: ");
            scanf("%d",&opt);
            if (opt==1) display(start1);
            else if(opt==2) display(start2);
        }
        else if (ch==3){
            printf("1.sll-1 2.sll-2: ");
            scanf("%d",&opt);
            if (opt==1) start1 = sortlist(start1);
            else if(opt==2) start2 = sortlist(start2);
        }
        else if (ch==4){
            printf("1.sll-1 2.sll-2: ");
            scanf("%d",&opt);
            if (opt==1) start1 = reverseList(start1);
            else if(opt==2) start2 = reverseList(start2);
        }
        else if (ch==5){
            start1 = concatList(start1, start2);
        }
        else if (ch == 6) break;
        else printf("Invalid.\n");
    }
    return 0;
}
