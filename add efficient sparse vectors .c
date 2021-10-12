

#include <stdio.h>

//add two sparse vector
//for example sparse vector 1 has val1[3]={1,5,6}
//                                pos1[3]={0,1,3}
//                                
//            sparse vector 2 has val2[3]={2,3,4}
//                                pos2[3]={1,2,3}
//add two sparse vector is val3[4]={1,7,3,10}
//                         pos3[4]={0,1,2,3}

int main()
{
    int val1[3]={2,3,4};
    int pos1[3]={0,1,3};
    
    int val2[3]={3,1,4};
    int pos2[3]={0,1,5};
    
    int val3[5]={0}; // 2 6 4 1 4
    int pos3[5]={0}; // 0 1 3 4 5
    
    int i=0,j=0,count=0,k=0;
    int a,b;
    
    
        
    while(count<6){
        if(pos1[i]==count&&pos2[j]==count){
            val3[k]=val1[i]+val2[j];
            pos3[k]=pos2[j];
            i++;
            j++;
            k++;
        } 
        
        else if(pos1[i]==count){
            val3[k]=val1[i];
            pos3[k]=pos1[i];
            i++;
            k++;
        }     
        else if(pos2[j]==count){
            val3[k]=val2[j];
            pos3[k]=pos2[j];
            j++;
            k++;
        } 
        
        count++;
    }



    for(i=0;i<5;i++){
        printf("%d",val3[i]);
    }
    printf("\n");
    for(i=0;i<5;i++){
        printf("%d",pos3[i]);
    }
    return 0;
}
