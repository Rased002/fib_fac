#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#define factorial_size 1754
#define fibonacci_size 23602

void print_fibonacci(int x, long double array[fibonacci_size]);
void print_factorial(int x, long double array[factorial_size]);

int main(void){

    while (1){
        int number_count;
        char operation;

        printf("\nEnter the operation type ( 'a' for factorial, 'i' for fibonacci, 'q' to quit ) : ");
        scanf("%s", &operation);
        printf("\n");

        if (operation == 'q') {
            printf("\t\t****** Succesfully Finished ******\n\n");
            break; //quit
        }
        
        printf("\nEnter number of elements you want : ");
        scanf("%d", &number_count);
        printf("\n");

        clock_t start_time = clock();

        printf("Number of Elements\t\tValues \n");

        if (operation == 'a') {
            long double array[factorial_size];
            print_factorial(number_count, array);
        }
        else{
            long double array_fib[fibonacci_size];
            print_fibonacci(number_count, array_fib);
        }
        printf("\n");

        clock_t end_time = clock();
        printf("\n\tRuntime : %.19LG\n", (long double) ((end_time - start_time) / CLOCKS_PER_SEC));
    }
    return 0;
}

void print_fibonacci(int x, long double array[fibonacci_size]){
    int i;
    int overflow = 0;
    static int max_fib = 0;
    array[0] = 0;array[1] = 1;
    if(max_fib >= x){
        for(i = 0; i < x; i++){
            printf("\n\t%d\t\t\t%.19LG\n", i + 1, array[i]);
        }
    }
    else{
        for(i = 2; i < x; ++i){

            if( array[i-1] == INFINITY ){
                overflow = 1;
                break;
            }

            array[i] = array[i-1] + array[i-2];
            printf("\n\t%d\t\t\t%.19LG\n", i-1, array[i-2]);
        }
        if (max_fib < i) max_fib = i;
        printf("\n\t%d\t\t\t%.19LG\n", i-1, array[i-2]);
        if(overflow != 1) printf("\n\t%d\t\t\t%.19LG\n", i, array[i-1]);
    }
}

void print_factorial(int x, long double array[factorial_size]){
    int i;
    int overflow = 0;
    static int max_fac = 0;
    array[0] = 1;
    if(max_fac >= x){
        for(i = 0; i < x; i++){
            printf("\n\t%d\t\t\t%.19LG\n", i + 1, array[i]);
        }
    }
    else{
        for(i = 1; i < x; ++i){

            if( array[i-1] == INFINITY ){
                overflow = 1;
                break;
            }

            array[i] = array[i-1] * (i + 1);
            printf("\n\t%d\t\t\t%.19LG\n", i, array[i-1]);
        }
        if (max_fac < i) max_fac = i;
        if(overflow != 1) printf("\n\t%d\t\t\t%.19LG\n", i, array[i-1]);  
    }
}