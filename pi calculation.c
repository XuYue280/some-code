

#include <stdio.h>

int main()
{
    int n;
    int d=1;
    double pi=0;
    scanf("%d",&n);
    if (n>=1){
       for (int i=0;i<n;i++){
           if(i%2==0){
               pi=pi+(4.0/d);
               d=d+2;
           }
           else{
               pi=pi-(4.0/d);
               d=d+2;
           }
           
       }
    printf("%f",pi);  
    return pi;
    }
    else{
        printf("Faile");
    }
    return 0;
}
