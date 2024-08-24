#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

#define destination "Grace_kid.c"
#define code "#include <stdio.h>%1$c#include <stdlib.h>%1$c#include <fcntl.h>%1$c%1$c#define destination %2$c%3$s%2$c%1$c#define code %2$c%4$s%2$c%1$c#define ft int main(void) {FILE *file = fopen(destination, %2$cw%2$c); if (!file) exit(1); fprintf(file, code, 10, 34, destination, code); fclose(file); }%1$c%1$cft;%1$c/* %1$c	This runs the quine.%1$c */%1$c"
#define ft int main(void) {FILE *file = fopen(destination, "w"); if (!file) exit(1); fprintf(file, code, 10, 34, destination, code); fclose(file); }

ft;
/* 
	This runs the quine.
 */
