//Add two vector with dynamic input (memory allocation)

#include <stdio.h>
#include <stdlib.h>

//function defination is a int* (pointer), 
//object-use pointer to locate each element in the sum of v1&v2
int *add_vector(int v1[],int v2[],int size){
    int sum[size];//sum is int not a pointer
    for (int i=0;i<size;i++){
        sum[i]=v1[i]+v2[i];
    }
    int *p=sum;//set pointer-p to array-sum
    //return int* (pointer)
    return p;//p will be the location for array-sum, point to first element of the sum
}

int main()
{
    int size;
    printf("input the size of vector\n");
    scanf("%d",&size);
    //allocate memory space for v1 (and v2 in same size)
    int *v1=malloc(sizeof(int)*size);
    int *v2=malloc(sizeof(int)*size);
    //if allocate memory space successfully (have enough space)
    if(v1!=0){
        //input element into v1 and v2
        printf("input the element in first vector v1\n");
        for(int i=0;i<size;i++){
            scanf("%d",&v1[i]);
        }
        printf("input the element in second vector v2\n");
        for(int i=0;i<size;i++){
            scanf("%d",&v2[i]);
        }
        //function call-run the function to get int* (pointer)
        //set it to a new local pointer
        int *result=add_vector(v1,v2,size);
        for(int i=0;i<size;i++){
            //use pointer to go through each element in array-result
            //recall-*p refer to the value in array
            printf("the result in result[%d] is %d\n",i,*(result+i));
        }
    }
    //if v1 and v2 are too big for memory then do nothing
    else{
        printf("vector is too big for memory\n");
    }
    
    
    
    
    return 0;
}
