#include <stdio.h>
#include <stdlib.h>

//def own type-employee contain two characteristics-name and salary
typedef struct{
    char name[20];
    int salary;
}employee;

int main()
{
    //p is a double pointer -point to each employee(pointer to name & salary)
    //acllocate memory for double pointer
    employee** p=malloc(5*sizeof(employee*));
    for(int i=0;i<5;i++){
        //for each "row" double pointer point to acllocate memory, sizeof(employee)=20 char + 4 int = 24
        employee* emprow=malloc(sizeof(employee));
        p[i]=emprow;
    }
    //memory size check
    printf("%ld,%ld\n",sizeof(employee),sizeof(p));
    
    printf("please input the name of name & salary\n");
    for(int i=0;i<5;i++){
        printf("Please input %d employee information\n",i+1);
        scanf("%s",p[i]->name);
        scanf(" %d",&p[i]->salary);
    }
    //double pointer check - to see all employees information
    for(int i=0;i<5;i++){
        printf("\n%d employee information is: Name:%s Salary:%d\n",i+1,p[i]->name,p[i]->salary);
    }
    free(p);
    return 0;
}
