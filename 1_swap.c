#include <stdio.h>

int main (void)
{
  int a, b;

  printf("Enter the two 3 digit integeers to swap:\n");
  scanf("%d", &a);
  scanf("%d", &b);

  // Swap without using tmeporary variables
  a = a ^ b;
  b = a ^ b;
  a = a ^ b;

  printf("The swapped integers a = %d, b = %d\n", a, b);
}
