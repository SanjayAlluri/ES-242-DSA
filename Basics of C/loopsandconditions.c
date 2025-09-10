#include<stdio.h>
#include<stdlib.h>

int main(){
    int a;
    scanf("%d", &a);
    if(a==1){
        printf("Yes the answer was %d\n", a);
    }
    else if(a==2){
        printf("Yes the answer was %d\n", a);         // syntax same as C++
    }
    else{
        printf("The answer is not correct");
    }



    int count=0;
    while(a>=0){
        count++;                    // while loop syntax is also same as C++
        a=a-1;
    }

    printf("%d\n", count);


}
