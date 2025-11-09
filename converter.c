#include <stdio.h>
	int main(){
 
	double kilometerstoMeters;
	double kilometerstoCentimeter;
	double kilometerstoMiles;
	double milestoFeet;
	double milestoInches;
	double kilometerinput;
	
	printf("Welcome to the converter user, please enter a distance in kilometers\n");
	scanf("%lf", &kilometerinput);
	while (kilometerinput < 0) {
	printf("You cannot have a negative value!!!!!! Please try again.\n");
	scanf("%lf", &kilometerinput);}

	double meters = kilometerstoMeters;
	double centimeters = kilometerstoCentimeter;
	double Miles = kilometerstoMiles;
	double feet = milestoFeet;
	double inches = milestoInches;

	meters = kilometerinput * 1000;
	centimeters = kilometerinput * 100000;
	Miles = kilometerinput * .623137;
	feet = kilometerinput * 5280;
	inches = kilometerinput * 63360;

	printf("Conversions for %f kilometers:\n", kilometerinput);
	printf("______________________________\n");
	printf("Meters:		%f\n", meters);
	printf("Centimeters:	%f\n",centimeters);
	printf("Miles:		%f\n", Miles);
	printf("Feet:		%f\n", feet);
	printf("Inches:		%f\n", inches);

return 0;
	}
