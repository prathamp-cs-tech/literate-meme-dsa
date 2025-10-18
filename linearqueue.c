#include <stdio.h>
#define maxsize 5
int q[maxsize];
int front=-1,rear=-1;

void insertq(int item){
    if (rear==maxsize-1){
        printf("The queue is full\n");
    }
    else{
        if(front==-1){
            front=0;
            rear=0;
            q[rear]=item;
        }
        else{
            rear++;
            q[rear]=item;
        }
    }
}

int deleteq(){
    int item;
    if (front==-1){
        printf("The queue is empty\n");
        return -1;
    }
    else{
        if(front==rear){
            item=q[front];
            front=-1;
            rear=-1;
        }
        else{
            item=q[front];
            front++;
        }
        return item;
    }
}

void dis(){
    if (front==-1){
        printf("The queue is empty\n");
    }
    else{
        for(int i=front;i<=rear;i++){
            printf("%d\n",q[i]);
        }
    }
}

int main(){
    int n=-1;
    while(n!=4){
        printf("Choose 1.insert 2.delete 3.display 4.exit: ");
        scanf("%d",&n);
        if(n==1){
            int item;
            printf("Enter item to be inserted: ");
            scanf("%d",&item);
            insertq(item);
        }
        else if(n==2){
            int item;
            item=deleteq();
            if(item!=-1){
                printf("Deleted item: %d\n",item);
            }
        }
        else if(n==3){
            dis();
        }
        else if(n!=4){
            printf("Invalid");
        }
    }
    printf("Exited");
}
