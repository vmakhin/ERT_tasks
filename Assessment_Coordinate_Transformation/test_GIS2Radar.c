#include <math.h>
#include <stdio.h>
#include "GIS2Radar.h"
#define PI 3.14159265

int main(void){

// Definition of type of variable used in program

// These are Input GIS coordinates variables 
double glatInit;
double glonInit;
double glatFinal;
double glonFinal;

// These are Output Radar coordinates
double range, bearing;

// Set values of prescribed latitude and longitude 
//ALtutude and longitude should be defined in DEGREES
//
//double glatInit  = 37.;
//double glonInit  = 75.;
//double glatFinal = 18.;
//pdouble glonFinal = 66.;

printf("Initial Point GIS coordinates (latitude and longitude):\n");

printf("Input value of latitude at Initial Location(in degrees):\n");
scanf("%lf",&glatInit);
printf("glatInit= %f , in degrees\n",glatInit);

printf("Input value of longitude at Initial Location(in degrees):\n");
scanf("%lf",&glonInit);
printf("glonInit= %f , in degrees\n",glonInit);


printf("Final Point GIS coordinates (latitude and longitude):\n");

printf("Input value of latitude at Final Location(in degrees):\n");
scanf("%lf",&glatFinal);
printf("glatFinal= %f , in degrees\n",glatFinal);
printf("Input value of longitude at Final Location(in degrees):\n");
scanf("%lf",&glonFinal);
printf("glonFinal= %f , in degrees\n",glonFinal);


// Call function to calculate Radar coordinates (range and bearing)
//  using given GIS coordinates   
GIS2Radar(&range,&bearing, glonInit, glatInit, glonFinal, glatFinal);

// Print calculated range and bearing 

printf("range= %f , in km\n", range/1.0e3);
printf("bearing= %f , in degrees\n", bearing);

return 0;
}
