#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double add(double a, double b);
double subtract(double a, double b);
double multiply(double a, double b);
double divide(double a, double b);
double power(double a, double b);

int main() {
	double a;
	double b;
	char operation;
	printf("Hello user, this is the CS102 calculator, please enter your first number: \n");
	scanf("%lf", &a);
	printf("Please enter your second number here: \n");
	scanf("%lf", &b);
	printf("Please enter an operation +, -, x, /, ^ or press q to quit\n");
	scanf(" %c", &operation);
	while (operation != 'q' && operation != 'x' && operation != '+' && operation != '/' && operation != '^' && operation != '-') {
		printf("Please type in an operator\n");
		scanf(" %c", &operation);}
	if (operation == 'q'){
	printf("Yo Almanakadd them numbers in ur head im not helping u twin bye \(-_-)/");
	exit(0);
	}
	else if (operation == 'x'){
printf("%lf * %lf = %.2f", a, b, multiply(a, b));
	}

	else if (operation == '+') {
printf("%lf + %lf = %.2f", a, b, add(a, b));}

	else if (operation == '/'){
printf("%lf / %lf = %.2f", a, b, divide(a, b));}

	else if (operation == '-'){
printf("%lf - %lf = %.2f", a, b, subtract(a, b));}

        else if (operation == '^'){ 
printf("%lf ^ %lf = %.2f", a, b, power(a, b));}
}

double add(double a, double b){
return a + b;
}
double subtract(double a, double b){
return a-b;
}
double multiply(double a, double b){
return a * b;
}
double divide(double a, double b){
return a / b;
}
double power(double a, double b){
return pow(a,b);
}





