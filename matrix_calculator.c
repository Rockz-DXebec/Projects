#include<stdio.h>
int main(){
    while(1){
        int ch,r1,c1,r2,c2;
        int mat1[r1][c1],mat2[r2][c2],result[r1][c2];
        printf("\n=======================\n");
        printf(" MATRIX OPERATIONS MENU \n");
        printf("========================\n");
        printf("1)Matrix Addition\n2)Matrix Subtraction\n3)Matrix Multiplication\n4)Transpose\n5)Exit");
        printf("\nChoose: ");
        scanf("%d",&ch);
        if(ch==1){ 
            printf("Enter rows and columns of 1st matrix: ");
            scanf("%d %d",&r1,&c1);
            printf("Enter rows and columns of 2nd matrix: ");
            scanf("%d %d",&r2,&c2);
            if(r1!=r2 || c1!=c2){
                printf("Matrix addition is not possible!\n");
                printf("Condition: Both matrix should have same dimensions.");
                continue;
            }
            printf("Enter elements of 1st matrix:\n");
            for(int i=0;i<r1;i++){
                for(int j=0;j<c1;j++){
                    scanf("%d",&mat1[i][j]);
                }
            }
            printf("Enter elements of 2nd matrix:\n");
            for(int i=0;i<r2;i++){
                for(int j=0;j<c2;j++){
                    scanf("%d",&mat2[i][j]);
                }
            }
            for(int i=0;i<r1;i++){
                for(int j=0;j<c1;j++){
                    result[i][j]=mat1[i][j]+mat2[i][j];
                }
            }
            printf("The Addition of matrix will be:\n");
            for(int i=0;i<r1;i++){
                for(int j=0;j<c1;j++){
                    printf("%d ",result[i][j]);
                }
                printf("\n");
            }
            printf("\n\n");
        }
        else if(ch==2){
            printf("Enter rows and columns of 1st matrix: ");
            scanf("%d %d",&r1,&c1);
            printf("Enter rows and columns of 2nd matrix: ");
            scanf("%d %d",&r2,&c2);
            if(r1!=r2 || c1!=c2){
                printf("Matrix Subtraction is not possible!\n");
                printf("Condition: Both matrix should have same dimensions.");
                continue;
            }
            printf("Enter elements of 1st matrix:\n");
            for(int i=0;i<r1;i++){
                for(int j=0;j<c1;j++){
                    scanf("%d",&mat1[i][j]);
                }
            }
            printf("Enter elements of 2nd matrix:\n");
            for(int i=0;i<r2;i++){
                for(int j=0;j<c2;j++){
                    scanf("%d",&mat2[i][j]);
                }
            }
            for(int i=0;i<r1;i++){
                for(int j=0;j<c1;j++){
                    result[i][j]=mat1[i][j]-mat2[i][j];
                }
            }
            printf("The Subtraction of matrix will be:\n");
            for(int i=0;i<r1;i++){
                for(int j=0;j<c1;j++){
                    printf("%d ",result[i][j]);
                }
                printf("\n");
            }
            printf("\n\n");

        }
        else if(ch==3){
            printf("Enter rows and columns of 1st matrix: ");
            scanf("%d %d",&r1,&c1);
            printf("Enter rows and columns of 2nd matrix: ");
            scanf("%d %d",&r2,&c2);
            if(c1!=r2){
                printf("Matrix multiplication is not possible!\n");
                printf("Condition: The number of columns in the first matrix must equal the number of rows in the second matrix.");
                continue;
            }
            printf("Enter elements of 1st matrix:\n");
            for(int i=0;i<r1;i++){
                for(int j=0;j<c1;j++){
                    scanf("%d",&mat1[i][j]);
                }
            }
            printf("Enter elements of 2nd matrix:\n");
            for(int i=0;i<r2;i++){
                for(int j=0;j<c2;j++){
                    scanf("%d",&mat2[i][j]);
                }
            }
            for(int i=0;i<r1;i++){
                for(int j=0;j<c2;j++){
                    result[i][j]=0;
                }
            }
            for(int i=0;i<r1;i++){
                for(int j=0;j<c2;j++){
                    for(int k=0;k<c1;k++){
                        result[i][j]+=mat1[i][k]*mat2[k][j];
                    }
                }
            }
            printf("The Multiplication will be:\n");
            for(int i=0;i<r1;i++){
                for(int j=0;j<c2;j++){
                    printf("%d ",result[i][j]);
                }
                printf("\n");
            }
            printf("\n\n");
        }
        else if(ch==4){
            printf("Enter rows and columns of matrix: ");
            scanf("%d %d",&r1,&c1);
            printf("Enter elements of matrix:\n");
            for(int i=0;i<r1;i++){
                for(int j=0;j<c1;j++){
                    scanf("%d",&mat1[i][j]);
                }
            }
            for(int i=0;i<r1;i++){
                for(int j=0;j<c1;j++){
                    result[j][i]=mat1[i][j];
                }
            }
            printf("The Transpose of matrix is:\n");
            for(int i=0;i<c1;i++){
                for(int j=0;j<r1;j++){
                    printf("%d ",result[i][j]);
                }
                printf("\n");
            }
            printf("\n\n");
        }
        else if(ch==5){
            break;
        }
        else{
            printf("Invalid input!\nTry again.\n\n");
        }
    }
    return 0;
}
