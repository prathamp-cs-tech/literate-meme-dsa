#include <stdio.h>

#define maxsize 5

int front=-1;
int rear=-1;
int a[maxsize];

void insertcq(int item){
    if(front==(rear+1)%maxsize){
        printf("The cq is full, can't insert\n");
    }
    else if (front==-1){
        front=0;
        rear=0;
        a[rear]=item;
    }
    else{
        rear=(rear+1)%maxsize;
        a[rear]=item;
    }
}

int deletecq(){
    int item;
    if (front==-1){
        printf("The cq is empty, can't delete\n");
    }
    else if(front==rear){
        item=a[front];
        front=-1;
        rear=-1;
        return item;
    }
    else{
        item=a[front];
        front=(front+1)%maxsize;
        return item;
    }
}

void displaycq(){
    if (front==-1){
        printf("The cq is empty, can't display\n");
    }
    else{
        int i=front;
        for(i;i!=rear;i=(i+1)%maxsize){
            printf("%d ",a[i]);
        }
        printf("%d\n",a[i]);
    }
}

int main(){
    int it;
    int j;
    while(j!=-1){
        printf("1.Insert 2.Delete 3.Display (-1 exit): ");
        scanf("%d",&j);
        if(j==1){
            printf("Inserting: ");
            scanf("%d",&it);
            insertcq(it);
        }
        else if(j==2){
            it=deletecq();
            printf("Deleting: %d\n", it);
        }
        else if(j==3){
            displaycq();
        }
        else if (j!=-1){
            printf("Invalid number!\n");
        }
    }
}