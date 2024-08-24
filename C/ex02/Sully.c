#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CURRFILE strrchr("/" __FILE__, '/') + 1
#define GCC "gcc -Wall -Werror -Wextra Sully_%1$d.c -o Sully_%1$d"
#define EXECUTE "./Sully_%1$d"
#define code "#include <fcntl.h>%1$c#include <stdio.h>%1$c#include <stdlib.h>%1$c#include <string.h>%1$c%1$c#define CURRFILE strrchr(%2$c/%2$c __FILE__, '/') + 1%1$c#define GCC %2$cgcc -Wall -Werror -Wextra Sully_%%1$d.c -o Sully_%%1$d%2$c%1$c#define EXECUTE %2$c./Sully_%%1$d%2$c%1$c#define code %2$c%3$s%2$c%1$c%1$cint i = %4$d;%1$c%1$cint main(void) { int diff = strcmp(CURRFILE, %2$cSully.c%2$c) != 0; char filename[20] = {0}; if (i-diff < 0 || sprintf(filename, %2$cSully_%%d.c%2$c, i-diff) < 9) exit(1); FILE* file = fopen(filename, %2$cw%2$c); if (!file) exit(1); fprintf(file,code,10,34,code,i-diff); fclose(file); char compilation[65] = {0}; char exec[20] = {0}; if (sprintf(compilation,GCC,i-diff)<45 || sprintf(exec,EXECUTE,i-diff)<9) exit(1); system(compilation); system(exec); return 0; }%1$c"

int i = 5;

int main(void) { int diff = strcmp(CURRFILE, "Sully.c") != 0; char filename[20] = {0}; if (i-diff < 0 || sprintf(filename, "Sully_%d.c", i-diff) < 9) exit(1); FILE* file = fopen(filename, "w"); if (!file) exit(1); fprintf(file,code,10,34,code,i-diff); fclose(file); char compilation[65] = {0}; char exec[20] = {0}; if (sprintf(compilation,GCC,i-diff)<45 || sprintf(exec,EXECUTE,i-diff)<9) exit(1); system(compilation); system(exec); return 0; }
