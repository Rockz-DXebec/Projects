#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

FILE *fp;

struct Node{
    char *data;
    int isFound;
    int erpid;
    char foundTime[50];
    struct Node *next;
};

void linkedlistTraversal(struct Node *ptr){
    while(ptr!=NULL){
        printf("Item: %s\n",ptr->data);
        if(ptr->isFound){
            printf("Status: FOUND\n");
            printf("Found At: %s",ptr->foundTime);
            printf("ERP: %d\n",ptr->erpid);
        }else{
            printf("Status: NOT FOUND\n");
        }
        printf("----------------------\n");
        ptr=ptr->next;
    }
}

struct Node *insertAtEnd(struct Node *head,char *val,int erp){
    struct Node *ptr=(struct Node*)malloc(sizeof(struct Node));
    ptr->data = strdup(val);
    ptr->erpid=erp;
    ptr->isFound=0;
    ptr->foundTime[0]='\0';
    ptr->next=NULL;
    if(head==NULL){
        return ptr;
    }
    struct Node *p=head;
    while(p->next!=NULL){
        p=p->next;
    }
    p->next=ptr;
    return head;
}

struct Node *markItemFound(struct Node *head,char *val){
    struct Node *ptr=head;
    int erp;
    while(ptr!=NULL){
        if(strcmp(ptr->data,val)==0){
            if(ptr->isFound){
                printf("Item already marked as FOUND!\n");
                return head;
            }
            printf("Enter ERP ID: ");
            scanf("%d",&erp);
            if(ptr->erpid==erp){
                ptr->isFound=1;
                time_t t;
                time(&t);
                strcpy(ptr->foundTime,ctime(&t));
                printf("Item marked as FOUND successfully.\n");
                fp = fopen("lost_found_records.txt", "a");
                if(fp != NULL){
                    char timeStr[50];
                    strcpy(timeStr, ptr->foundTime);
                    timeStr[strcspn(timeStr, "\n")] = '\0';
                    fprintf(fp,"%-20s %-10s %-25s %-10d\n",
                            ptr->data, "FOUND", timeStr, ptr->erpid);
                    fclose(fp);
                }
            }
            else{
                printf("ERP ID is not matching!\n");
            }
            return head;
        }
        ptr=ptr->next;
    }
    printf("Item not Found!\n");
    return head;
}
struct Node *deleteByItemName(struct Node *head,char *val){
    if(head==NULL){
        printf("List is Empty\n");
        return head;
    }
    struct Node *ptr=head;
    struct Node *prev=NULL;
    while(ptr!=NULL && strcmp(ptr->data,val)!=0){
        prev=ptr;
        ptr=ptr->next;
    }
    if(ptr==NULL){
        printf("Item not found!\n");
        return head;
    }
    fp = fopen("lost_found_records.txt", "a");
    if(fp != NULL){
        fprintf(fp,"%-20s %-10s %-25s %-10s\n",
                ptr->data, "DELETED", "-", "-");
        fclose(fp);
    }
    if(prev==NULL){
        head=ptr->next;
    }else{
        prev->next=ptr->next;
    }
    free(ptr->data);
    free(ptr);
    printf("Item deleted permanently.\n");
    return head;
}

void freeList(struct Node *head){
    struct Node *temp;
    while(head!=NULL){
        temp=head;
        head=head->next;
        free(temp->data);
        free(temp);
    }
}

int main(){
    printf("---------------WELCOME TO LOST AND FOUND MANAGEMENT SYSTEM---------------\n");
    int ch;
    char input[100];
    int erp;
    struct Node *head=NULL;
    
    if(fp == NULL){
        fp = fopen("lost_found_records.txt", "w");
        if(fp != NULL){
            fprintf(fp,"%-20s %-10s %-25s %-10s\n",
                    "ITEM","STATUS","TIME","ERP");
            fprintf(fp,"---------------------------------------------------------------\n");
            fclose(fp);
        }
    }else{
        fclose(fp);
    }
    while(1){
        printf("\n1) Add Lost Item\n2) View Lost Items\n3) Mark Item as Found\n4) Exit\n5) Delete Item Permanently\n");
        printf("Enter Choice: ");
        scanf("%d",&ch);
        if(ch==1){
            printf("Enter Lost Item: ");
            scanf(" %[^\n]", input);
            printf("Enter your ERP ID: ");
            scanf("%d",&erp);
            head=insertAtEnd(head,input,erp);
            printf("Item added Successfully.\n");
            fp = fopen("lost_found_records.txt", "a");
            if(fp != NULL){
                time_t t;
                time(&t);
                char *timeStr = ctime(&t);
                timeStr[strcspn(timeStr, "\n")] = '\0';
                fprintf(fp,"%-20s %-10s %-25s %-10s\n",
                        input, "LOST", timeStr, "-");
                fclose(fp);
            }
        }
        else if(ch==2){
            if(head==NULL){
                printf("No lost Items.\n");
            }else{
                printf("Lost Items:\n");
                linkedlistTraversal(head);
            }
        }
        else if(ch==3){
            printf("Enter item to mark as found: ");
            scanf(" %[^\n]", input);
            head=markItemFound(head,input);
        }
        else if(ch==5){
            printf("Enter item to delete permanently: ");
            scanf(" %[^\n]", input);
            head=deleteByItemName(head,input);
        }
        else if(ch==4){
            freeList(head);
            printf("Hope you found your product...\n");
            break;
        }
        else{
            printf("Invalid Choice!\nTry again..\n");
        }
    }
    return 0;
}