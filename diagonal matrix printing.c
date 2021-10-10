/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

int main()
{
    int arr[3][3]={{1,2,3},
                   {4,5,6},
                   {7,8,9}};
    int object[9];
    
    int k,i,j,count=0;
    for(k=0;k<3;k++){
        i=k;
        j=0;
        while(i>=0){
            object[count]=arr[i][j];
            i--;
            j++;
            count++;
        }
    }
    for(k=1;k<3;k++){
        i=2;
        j=k;
        while(j<3){
            object[count]=arr[i][j];
            i--;
            j++;
            count++;
        }
        
    }
    
    for(int u=0;u<9;u++){
        printf("%d",object[u]);
    }
    
    
    return 0;
}
