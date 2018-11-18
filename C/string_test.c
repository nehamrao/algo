#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void) {
	// your code goes here
        char *s = malloc (100);
        char *s1 = malloc (100);
	strcpy (s, "NEHA RAO ROCKS");
	strcpy (s1, "FOO BAR BAZ");
	
	char *res1 = strtok(s, " ");
	printf ("String res1: %s\n", res1);

        char *res2 = strtok(s1, " ");
	printf ("String res2: %s\n", res2);

        char *res3 = strtok(NULL, " ");
        printf ("String res3: %s\n", res3);
	
	return 0;
}
