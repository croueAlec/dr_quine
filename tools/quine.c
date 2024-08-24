#include <stdio.h>
#include <fcntl.h>

char *s = "#include <stdio.h>%c#include <fcntl.h>%c%cchar *s = %c%s%c;%c%cint main(void) {%c%cFILE *file = fopen(%cquine_test.c%c, %cw%c);%c%cfprintf(file,s,10,10,10,34,s,34,10,10,10,9,34,34,34,34,10,9,10,9,10,10);%c%cfclose(file);%c}%c";

int main(void) {
	FILE *file = fopen("quine_test.c", "w");
	fprintf(file,s,10,10,10,34,s,34,10,10,10,9,34,34,34,34,10,9,10,9,10,10);
	fclose(file);
}
