/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

int main()
{
    int a[3]={1,2,7};
    int b[3]={2,4,6};
    int total=6; //sum of two array length
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(a[i]==b[j]){
                total--;
            }
        }
    }
    printf("%d",total);

    return 0;
}
