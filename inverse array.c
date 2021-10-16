
#include <stdio.h>

int main()
{
    printf("Please enter an array for inverse\n");
    printf("Please enter the array size:\n");
    int n;
    scanf("%d",&n);
    int arr[99];
    printf("\noriginal array: \n");
    for(int i=0;i<n;i++)    
        scanf("%d",&arr[i]);
        
    printf("\nCHECK your array:\n");
    for(int i=0;i<n;i++)    
        printf("%d",arr[i]);
    
    int i=0,temp,arr2[n];
    for(int i=0;i<n;i++){
        arr2[i]=arr[n-1-i];
    }
    printf("\n\nNow inverse array is: \n");
    for(i=0;i<n;i++){
        printf("%d",arr2[i]);
        
    }
    

    return 0;
}
