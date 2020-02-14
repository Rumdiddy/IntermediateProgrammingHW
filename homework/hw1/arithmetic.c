//Samuel Jin
//sjin16
//arithmetic.c

#include<stdio.h>

int main() {
  
  //Variables
  int scanres;
  char operator;
  float nnum;
  float result;
  char mal[] = "malformed expression\n";
  char dive[] = "division by zero\n";

  //Prompts user for expression input.
  printf("Please enter an arithmetic expression using * and / only:\n");
  scanres = scanf(" %f", &result);

  //Checks for Ctrl-D if no input is given.
  if (scanres == EOF) {
   printf("%s", mal);
   return 1;
  }

  //Loops through as long as scanf detects a char operator and float
  while ((scanres = scanf(" %c %f", &operator, &nnum)) == 2) {

    //Checks for divide by zero
    if (nnum == 0) {
      printf("\n%s", dive);
      return 2;
    }

    //Switch decides result based on whether * or / is inputted.
    switch(operator) {
      case '*':
	result = result * nnum;
       	break;
      case '/':
	result = result / nnum;
	break;
      default:
	printf("\n%s", mal);
	return 1;
    }
  }

  //Checks for the scanf only detecting one of the wanted inputs. Malformed Expression.
  if (scanres  == 1) {
    printf("\n%s", mal);
    return 1;
  }

  //Checks for reaching end of expression or proper expression terminated by Ctrl-D
  if (scanres == EOF || scanres == 0 || scanres == 2) {
    printf("\n%f\n",result);
    return 0;
  } else {
    printf("\n%s", mal);
    return 1;
  } 
}
