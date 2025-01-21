#include <stdlib.h>
#include <unistd.h>
#include<stdio.h>
void main()
{
char*args[]={"./exec",NULL};
execvp(args[0],args);
printf("End");
}
