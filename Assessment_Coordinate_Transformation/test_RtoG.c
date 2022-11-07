#include <math.h>
#include <stdio.h>
#include "RtoG.h"
#define PI 3.14159265

int main(void){

// Definition of type of variable used in program

// These are Input GIS coordinates variables
// of the Initial Location 
double glatInit;
double glonInit;

// These are Input Radar coordinates
double range, bearing;

// Output values of GIS Coordinates of the Final Location
double glatFinal;
double glonFinal;
// Set values of prescribed latitude and longitude of the Initial Location
//ALtutude and longitude should be defined in DEGREES
//
printf("Initial Point GIS coordinates (latitude and longitude):\n");

printf("Input value of latitude at Initial Location(in degrees):\n");
scanf("%lf",&glatInit);
printf("glatInit= %f , in degrees\n",glatInit);

printf("Input value of longitude at Initial Location(in degrees):\n");
scanf("%lf",&glonInit);
printf("glonInit= %f , in degrees\n",glonInit);


printf("Input value of Initial Point Radar Coordinates:\n");

printf("Input value of range at Initial Location(in m):\n");
scanf("%lf",&range);
printf("range= %f , in m\n",range);
printf("Input value of bearing at Initial Location(in degrees):\n");
scanf("%lf",&bearing);
printf("bearing= %f , in degrees\n",bearing);


// Call function to calculate GIS  coordinates (range and bearing)
//  using given Radar coordinates (range and bearing )  and  

RtoG (range, bearing,  glonInit,  glatInit, &glonFinal,  &glatFinal);

// Print calculated GIS Coordinates of Final Location 

printf("Final Point GIS coordinates (latitude and longitude):\n");

printf("glatFinal= %f , in degrees\n",glatFinal);
printf("glonFinal= %f , in degrees\n",glonFinal);

return 0;
}
