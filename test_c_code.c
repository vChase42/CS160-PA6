#include <stdio.h>


int foo(int a, int b);

int main(){
    
    int this = 4;

    int potato = foo(this,9);

    

    printf("%d\n",this);

    return 0;
}



int foo(int a, int b){
    return a + b;
}