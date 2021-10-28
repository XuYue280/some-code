#include <stdio.h>

//typedef - create our own data type "Monom" 
//struct - create structure "monomial" with properties "coeff" and "power" with it. Like class in Python
typedef struct monomial{
    float coeff;
    int power;
}Monom;



//function prototyps, put here before using those function call.
Monom product(Monom mono1, Monom mono2);
Monom product_by_ref(Monom *mono1, Monom *mono2);
void change(Monom *mono1, Monom *mono2);


void main()
{
    //initial setting (can be changed into different monoimal equation)
    //def type "Monom"(just like int i=0),{a,b} refer to coeff & power in order.
    Monom mono1={2,3};
    Monom mono2={8.2,-1};
    Monom mono3;
    
    mono3=product(mono1,mono2);
    printf("product result=%fx^%d\n\n",mono3.coeff,mono3.power);
    
    //another way to get the product, by using pointer and arrow operator, pass afress for pointer in function defination below
    mono3=product_by_ref(&mono1,&mono2);
    printf("product_by_ref result=%fx^%d\n\n",mono3.coeff,mono3.power);
    
    //because function writen in pointer, pass adress for pointer in function defination below.
    change(&mono1,&mono2);
    printf("exchange result\nmono1 = %fx^%d,\nmono2 = %fx^%d\n",mono1.coeff,mono1.power,mono2.coeff,mono2.power);
    
}

//regular way 
Monom product(Monom mono1, Monom mono2){
    Monom result;
    result.coeff=mono1.coeff * mono2.coeff;
    result.power=mono1.power + mono2.power;
    return result;
}

//another way by using pointer. *mono-value, by passing &mono1 in function call.
Monom product_by_ref(Monom *mono1, Monom *mono2){
    Monom result;
    //arrow opertor "->" refers to coeff and power
    result.coeff=mono1->coeff * mono2->coeff;
    result.power=mono1->power + mono2->power;
    return result;
}

//swap the order - use pointer to indicate value then switch.
void change(Monom *mono1, Monom *mono2){
    Monom temp;
    temp=*mono1;
    *mono1=*mono2;
    *mono2=temp;
}  

    

