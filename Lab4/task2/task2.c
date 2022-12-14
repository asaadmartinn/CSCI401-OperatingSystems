//worked with amira and mary
#include <stdio.h>
#include <stdlib.h>

/* IMPLEMENT ME: Declare your functions here */
typedef int (*Operation) (int a, int b);
int add (int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
int divide(int a, int b);


int main (void)
{
  // Array of functions of type
  Operation operations[4];
  char operation[10];
  int o;
  
  operations[0] = &add;
  operations[1] = &subtract;
  operations[2] = &multiply;
  operations[3] = &divide;
  
  // different operations that willl be done
  // in this case, add, subtract, multiply, divide
  int a = 6;
  int b = 3;
  int r;
  //while loop to loop through operand and operation char
  while(1){
    printf("Operand 'a' : %d | Operand 'b' : %d \n Specify the operation to perform \n(0 : add | 1 : subtract | 2 : Multiply | 3: divide | 4 : exit):", 
           a, b);
    scanf("%s", operation);
    o = atoi(operation);
    while (o > 4) {
      printf("Specify the operation to perform\n(0 : add | 1 : subtract | 2 : Multiply | 3: divide | 4 : exit):");
      scanf("%s", operation); 
      o = atoi(operation);
    }
    
    if (o == 4){ break; }
    
    r = (*operations[o])(a, b);
    printf("x = %d\n", r);
  }

  return 0;
}

/* IMPLEMENT ME: Define your functions here */
int add (int a, int b) { printf ("Adding 'a' and 'b'\n"); return a + b;}
int subtract (int a, int b) { printf ("Subtracting 'a' and 'b'\n"); return a - b;}
int multiply (int a, int b) { printf ("Multiplying 'a' and 'b'\n"); return a * b;}
int divide (int a, int b) { printf ("Dividing 'a' and 'b'\n"); return a / b;}

//printing operation that were put before