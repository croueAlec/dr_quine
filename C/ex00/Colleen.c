#include <stdio.h>

char *s = "#include <stdio.h>%1$c%1$cchar *s = %2$c%3$s%2$c;%1$c%1$cvoid colleen(void) {%1$c%4$cprintf(s,10,34,s,9);%1$c}%1$c%1$cint main(void) {%1$c%4$c/* %1$c%4$c%4$cThis program prints it's own source code using printf and a very long string.%1$c%4$c */%1$c%4$ccolleen();%1$c%4$creturn 0;%1$c}%1$c%1$c/* %1$c%4$cI should currently be going to sleep instead of doing this...%1$c */%1$c";

void colleen(void) {
	printf(s,10,34,s,9);
}

int main(void) {
	/* 
		This program prints it's own source code using printf and a very long string.
	 */
	colleen();
	return 0;
}

/* 
	I should currently be going to sleep instead of doing this...
 */
