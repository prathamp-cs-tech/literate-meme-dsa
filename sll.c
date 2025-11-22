#include <stdio.h>

struct node{
    int info;
    struct node *next;
};

struct node * createsll(){
    struct node *start=NULL, *p;
    int item;
    printf("Enter element to insert(-999 to stop): ");
    scanf("%d",&item);
    while(item!=-999){
        p=(struct node *)malloc(sizeof(struct node));
        p->info=item;
        if (start==NULL){
            p->next=NULL;
            start=p;
        }
        else{
            p->next=start;
            start=p;
        }
        scanf("%d",&item);
    }
    return start;
}

struct node * insertatanypos(struct node *start, int item, int opt){
    struct node *p, *temp, *follow;
    int pos;
    p=(struct node *)malloc(sizeof(struct node));
    p->info=item;
    if(start==NULL){
        p->next=NULL;
        start=p;
        printf("Sll was empty inserted at start");
    }
    else{   
        if (opt==1){
            p->next=start;
            start=p;
        }
        else if(opt==2){
            printf("Enter pos");
            scanf("%d",&pos);
            temp=start;
            for (int i=0;i<pos;i++){
                if(temp->next==NULL){
                    printf("The sll ends at %d while, you wanted to insert at %d, inserting at the end of the sll instead",i,pos);
                    break;
                }
                follow=temp;
                temp=temp->next;
            }
            follow->next=p;
            p->next=temp;
        }
        else if(opt==3){
            temp=start;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=p;
            p->next=NULL;
        }
    }
    return start;
}

void display(struct node *start){
    if (start==NULL){
        printf("Empty");
    }
    else{
        temp=start;
        while(temp!=NULL){
            printf("%d")
        }
    }
}