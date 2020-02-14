//Samuel Jin
//sjin16

#include<stdio.h>

int main() {
  int scanres;
  char operator;
  float nnum;
  float result;
  char mal[] = "malformed expression\n";
  char dive[] = "division by zero\n";
  
  printf("Please enter an arithmetic expression using * and / only:\n");
  scanres = scanf(" %f", &result);
  
  while (scanres = scanf(" %c %f", &operator &nnum) == 2) {
    if (nnum == 0) {
      printf("%s", dive);
      return 2;
    } else {   
      switch(operator) {
      case '*':
	result = result * nnum;
	break;
      case '/':
	result = result / nnum;
	break;
      default:
	printf("%s", mal);
	return 1;
      }
    }
  }

  if (scanres == EOF) {
    printf("%f", result);
    return 0;
  } else {
    printf("%s", mal);
    return 1;
  }
}
    
    
    printf("Please enter an arithmetic expression using * and / only:\n");
    



}
