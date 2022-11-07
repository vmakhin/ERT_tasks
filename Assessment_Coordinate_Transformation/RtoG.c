#include <math.h>
#include <stdio.h>
#define PI 3.14159265

int RtoG (double range, double bearing, double  glonInit, double glatInit, double *glonFinal, double *glatFinal)
{
//Earth's radius
              double R;
              R = 6371.0e3; // metres
// input longitude and latitude in degrees
// range in m
// where glatInit and glatFinal  are latitudes, glatFinal are longitudes,
// bearing is the bearing (clockwise from north),
// theta is the angular distance d/R;
// d being the distance travelled,
// R the Earth’s radius
//
// Calculate latitude at Final Location
          *glatFinal = (asin( sin(glatInit * M_PI/180.)*cos(range/R) +
                      cos(glatInit * M_PI/180.) * sin(range/R) * cos(bearing * M_PI/180.) ))*180./M_PI;
// Calculate longitude at Final Location          
          *glonFinal = glonInit + (atan2(sin(bearing * M_PI/180.) * sin(range/R)*cos(glatInit * M_PI/180.),
                           cos(range/R) - sin(glatInit  * M_PI/180.) * sin(*glatFinal * M_PI/180.)))*180./M_PI;

//The longitude can be normalised to −180…+180 using (lon+540)%360-180
return 0;
}

