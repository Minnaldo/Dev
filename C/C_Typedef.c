#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int Integer;
typedef char* String;

int main()
{
	Integer size = 0;
	Integer num = 10;
    String string;

	printf("Please input string\n");
	scanf("%s", string);

    int strlength = strlen(string);

    printf("the size of string is : %d\n", strlength);
    printf("the string which inputted is : %s\n", string);


	// String str = (String)malloc(sizeof(char)*size);

}
