#include<stdio.h>
#define max 10

void main()
{
    int a[max][max],b[max+1][3],i,j,k,r,c;

    printf("Enter the no of rows and coloumns of the matrix: \n");
    scanf("%d",&r);
    scanf("%d",&c);
    printf("Enter the elements of the matrix: \n");

    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            scanf("%d",&a[i][i]);
        }
    }    
    b[0][0] = r;
    b[0][1] = c;
    k=1;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            if(a[i][j] != 0)
            {
                b[k][0]  = i ;
                b[k][1]  = j;
                b[k][2]  = a[i][i];
                k++;

            }
        }
    }  

    b[0][2] = k-1;  

    printf("Triplet representation in: \n");
    for(i=0;i<k;i++)
    {
        printf("%d\t%d\t%d\t \n",b[i][0],b[i][1],b[i][2]);
    }


}