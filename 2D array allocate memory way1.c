/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h> 
//allocate memory for 2D array
int main()
{
    int r,c,i;
    int size=0;
    int **pp;
    scanf("%d%d",&r,&c);
    //pp is a double pointer, allocate memory for pp = &pp[0] to &pp[r]
    //int* for unknow size of colum
    pp=malloc(r*sizeof(int*));
    //allocate memory for size of colum in each rows
    for(i=0;i<c;i++){
        pp[i]=malloc(c*sizeof(int));
    }
    
    //check memory size
    for(i=0;i<r;i++){
        for(int j=0;j<c;j++){
            size=size+sizeof(int);
        }
    }
    printf("row=%d,colum=%d,total size in bites=%d",r,c,size);

    return 0;
}
