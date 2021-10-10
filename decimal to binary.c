
#include <stdio.h>



void main(){
    
    int input,i;
    //C language dont have dynamic array, array size cant change. 999999 is for large number
    int binary[999999]={0};
    
    printf("Please enter base 10 interge to transfer into binary interge\n");
    scanf("%d",&input);
    printf("\n");
    
    // append input module then devide input by 2 until it reach 0
    for(i=0;input>0;i++){
        binary[i]=input%2;
        input=input/2;
    }
    
    //check i value and binary array
    /*printf("%d\n",i);
    for(i=0;i<20;i++){*/
    //printf("%d\n",i);
        
    
    printf("number in binary is ");
    
    /*IMPORTANT; eg input = 12, need 4 devision to get input=0, i=4, 4 number in binary array, 
    but printing index is form 0 to 3 (i=i-1)*/
    for(i=i-1;i>=0;i--){
        printf("%d",binary[i]);
    }
    
    
}  



    
    
