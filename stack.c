#include <stdio.h>
int arr[5];
int maxsize=4;
int top=-1;
void push(int i){
    if (top==maxsize){
          printf("The stack will overflow\n");
    }else{
        top++;
        arr[top]=i;
    }
}
int pop(){
    if (top==-1){
        printf("The stack will underflow\n");
        return -1;
    }
    else{
        int item=arr[top];
        top--;
        return item;
    }
}
void display(){
    if (top==-1){
        printf("The stack will underflow\n");
    }
    else{
        for(int i=top;i>=0;i--){
                printf("%d\n",arr[i]);
        }
    }
}

int main(){
    int j=-1;
    while(j!=4){
        printf("Choose 1.push 2.pop 3.display 4.stop\n");
        scanf("%d",&j);
        if(j==1){
            int k;
            scanf("%d",&k);
            push(k);
        }
        else if(j==2){
            printf("%d\n",pop());
        }
        else if(j==3){
            display();
        }
        else if(j==4){
            break;
        }
        else{
            printf("Enter a valid number\n");
        }
    }
}
