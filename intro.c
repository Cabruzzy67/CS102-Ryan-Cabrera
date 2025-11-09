#include <stdio.h>
int main() {
	char name[68];
	int favoritenumber;
printf("Hi, what's ur name?\n");
scanf("%30s", name);

printf("That's cool, %s \nWhat about a favorite number?\n", name); 
scanf("%50d", &favoritenumber);


printf("Your number is tuff, but doubled is even tuffer, which is %d" , favoritenumber * 2);
return 0;

}
