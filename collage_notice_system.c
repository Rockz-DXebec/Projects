#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct queue{
    int size;
    int f;
    int r;
    char arr[100][500]; 
};
int isFull(struct queue *q){
    if(q->r == q->size-1){
        return 1;
    }
    return 0;
}
int isEmpty(struct queue *q){
    if(q->f == q->r){
        return 1;
    }
    return 0;
}
void enqueueR(struct queue *q, char not[]){
    if(isFull(q)){
        printf("Queue is full!\n");
        return;
    }
    q->r++;
    strcpy(q->arr[q->r], not);
}
void dequeueF(struct queue *q){
    if(isEmpty(q)){
        printf("Queue is empty!\n");
        return;
    }
    q->f++;
}
void dequeueR(struct queue *q){
    if(isEmpty(q)){
        printf("Queue is empty!\n");
        return;
    }
    q->r--;
}
int main(){
    printf("---------------WELCOME TO COLLEGE NOTICE SYSTEM---------------\n");
    struct queue *q=(struct queue*)malloc(sizeof(struct queue));
    printf("Enter Size of Queue: ");
    scanf("%d",&q->size);
    q->r = q->f = -1;
    int choice;
    while(1){
        printf("\n1)Enter Notice\n2)Show Latest Notice\n3)Show Oldest Notice\n4)Show all Notices\n5)Delete Latest Notice\n6)Delete Oldest Notice\n7)Exit\n");
        scanf("%d",&choice);
        if(choice==1){
            char not[500];
            printf("Enter Notice: ");
            scanf(" %[^\n]", not);
            enqueueR(q, not);
        }
        else if(choice==2){
            if(!isEmpty(q))
                printf("Latest Notice: %s\n", q->arr[q->r]);
            else{
                printf("There is no Notice\n");
            }
        }
        else if(choice==3){
            if(!isEmpty(q))
                printf("Oldest Notice: %s\n", q->arr[q->f+1]);
            else{
                printf("There is no Notice\n");
            }   
        }
        else if(choice==4){
            if(!isEmpty(q)){
                printf("All Notices:\n");
                int j=1;
                for(int i=q->f+1; i<=q->r; i++){
                    printf("%d)%s\n",j++, q->arr[i]);
                }
            }
            else{
                printf("There is no Notice\n");
            }
        }
        else if(choice==5){
            dequeueR(q); 
        }
        else if(choice==6){
            dequeueF(q); 
        }
        else if(choice==7){
            printf("Exitting...");
            break;
        }
    }
    free(q);
    return 0;
}