/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

int main()
{
    int decision;
    float add,amount=100;
    int step,i=0;
    int name;
    printf("***************************Welcome to XY bank***************************\n");
    while(i==0)
    {
        printf("***** Please tell me how can I help you by pressing the number:\n");
        printf("\n");
        printf("************************************LIST****************************************\n");
        printf("***** '1' -- withdraw money\n");
        printf("***** '2' -- deposit money\n");
        printf("***** '3' -- e transfer\n");
        printf("***** '4' -- balance check\n");
        printf("************************************************************************\n");
        printf("\n");
        printf("***** Please tell me your decision\n");
        scanf("%d",&decision);
    
        
        switch (decision)
        {
            case 1:
            printf("************************************************************************\n");
            printf("***** Please enter the amount that you want to withdraw\n");
            scanf("%f",&add);
            if(add>0){
                amount=amount+add;
                printf("\n");
                printf("***** Withdraw successfully! Your new balance is: %f\n",amount);
                printf("\n");
                printf("Do you want to continue? 1-keep,0-quit\n");
                scanf("%d",&step);
                if (step==0)
                {
                    i=1;
                    printf("***************************Thanks for using XY bank***************************\n");
                    break;
                }
                else{
                    break;
                }
            }
            else{
                printf("Invalid amount! Please try again.\n");
                break;
            }
            
            //deposit money
            case 2:
                printf("************************************************************************\n");
                printf("***** Please enter the amount that you want to deposit\n");
                scanf("%f",&add);
                //check input is positive
                if(add>0)
                {
                    if(add<=amount)
                    {
                        amount=amount-add;
                        printf("\n");
                        printf("***** Deposit successfully! Your new balance is: %f\n",amount);
                        printf("\n");
                        printf("Do you want to continue? 1-keep,0-quit\n");
                        printf("\n");
                        scanf("%d",&step);
                        if (step==0)
                        {
                            i=1;
                            printf("***************************Thanks for using XY bank***************************\n");
                            break;
                        }
                        else
                        {
                            break;
                        }
                    }
                    //money is not enough
                    else
                    {
                        printf("Your account do not have enough money, please check your input.\n");
                        printf("\n");
                        break;
                    }
                          
                    
                    
                }
                
            
                else{
                    printf("Invalid input, please try again.\n");
                    break;
                }
            case 3:
                
                printf("************************************************************************\n");
                printf("***** Please enter the amount that you want to etransfer\n");
                printf("\n");
                scanf("%f",&add);
                printf("***** Please enter the Contact Code of accpter that who you want to etransfer to\n");
                printf("\n");
                scanf("%d",&name);
                
                if(add>0)
                {
                    if(add<=amount)
                    {
                        
                        amount=amount-add;
                        printf("\n");
                        printf("%f have been successfully transfer to Contact Code NO.%d.Current balance is: %f\n",add,name,amount);
                        printf("\n");
                        printf("Do you want to continue? 1-keep,0-quit\n");
                        printf("\n");
                        scanf("%d",&step);
                        
                        if (step==0)
                        {
                            i=1;
                            printf("***************************Thanks for using XY bank***************************\n");
                            break;
                        }
                        
                        else
                        {
                            break;
                        }
                    }
                    
                    else{
                        printf("Not enough money, plaese try again\n");
                        break;
                    }
                    
                    
                }
                
                else
                {
                    printf("Invalid input, please try again\n");
                }
            case 4:
                    printf("Your current balance is: %f\n",amount);
                    printf("\n");
                    break;
            
            default:
                printf("Invalid number, please check the list.\n");
            
        }
    }

        
    return 0;
    
}