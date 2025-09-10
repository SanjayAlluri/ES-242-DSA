#include<stdio.h>
#include<stdlib.h>

int main(){

    //static array

    int a[10]={1,2,3,4,5,6,7,8,9,10};   //creating an array similar to c++
    int n=sizeof(a)/sizeof(a[0]); //sixe of ststic array
    for(int i=0;i<n;i++){
        printf("%d\n", a[i]);
    }
    // other operations are similar to that of C++







    // dynamic array :- somewhat works like vector in c++ but not exactly vector

    int capacity =5 // for dynamic arrays capacity should be initially declared
    int *arr=malloc(capacity*sizeof(int));  //key step
    arr[0]=1; //inserting is same as arrays

    int capacity2=10;

    arr=realloc(capacity2*size(int));  //if want to change the size of array

    // print whatever required

    free(a);  //veryvery important to free the memory

}
