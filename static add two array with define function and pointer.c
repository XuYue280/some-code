
#include <stdio.h>

int *add_vector(int v1[],int v2[],int size){
    int result[size];
    for(int i=0;i<size;i++){
        result[i]=v1[i]+v2[i];
    }
    int *p=result;//set p value to first element of result(array)
    return p;

}

void main(){
    int a[4]={0,2,3,5};
    int b[4]={2,3,5,1};
    //assign pointer-result to pointer-p(add_vector function)
    int *result=add_vector(a,b,4);
    for(int i=0;i<4;i++){
        printf("the result is %d\n",*(result+i)); //same as result[i]
    }
}
