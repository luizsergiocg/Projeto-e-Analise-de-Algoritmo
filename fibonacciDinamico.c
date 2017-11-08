#include <stdio.h>
#include <stdlib.h>

float fibonacci(int n);
float fibonacciRec(int n);
int main()
{
    printf("%f\n", fibonacci(80));

    return 0;
}

float fibonacci(int n){
    float fibonacci[n];
    int i;

    fibo[0] = 0.0;
    fibo[1] = 1.0;

    for( i= 2; i < n; i++){
        fibonacci[i] = fibonacci[i-1] + fibonacci[i-2];
    }

    return fibonacci[i-1];
}

float fibonacciRec(int n){ e
    if(n == 0){
        return 0.0;
    }
    else if(n == 1){
        return 1.0;
    }
    else
        return fibonacciRec(n-1) + fibonacciRec(n-2);
}
