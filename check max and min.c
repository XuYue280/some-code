
#include <stdio.h>

int main()
{
    int max,min;
    int n,i,check;
    printf("please enter how much number you want to check for max and min\n");
    scanf("%d",&check);
    for(i=0;i<check;i++){
        printf("Please enter %d number: ",i+1);
        scanf("%d",&n);
        if(i==0){
            max=n;
            min=n;
            continue;
        }
        if(n<min){
            min=n;
            continue;
        }
        if(n>max){
            max=n;
            continue;
        }
    }
    printf("Max numbe is %d and min number is %d\n",max,min);
        
    

    return 0;
}
