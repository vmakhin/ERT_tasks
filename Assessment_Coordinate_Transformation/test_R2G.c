#include <math.h>
#include <stdio.h>
#define PI 3.14159265

int GIS2Radar(double *range, 
	      double *bearing, 
              double glonInit, 
              double glatInit, 
              double glonFinal, 
              double glatFinal)
{
              double x,y;
              double R;
              double phi1;
              double phi2;
              double delta_phi;
              double delta_lambda;
              double a,c,theta;
              printf("glonInit= %f\n",glonInit);
              printf("glatInit= %f\n",glatInit);
              printf("glonFinal= %f\n",glonFinal);
              printf("glatFinal= %f\n",glatFinal);
              R = 6371.e3; // metres
              phi1 = glatInit *M_PI/180.; // phi, lambda covert to  radians
              phi2 = glatFinal * M_PI/180.;
              delta_phi = (glatFinal-glatInit) * M_PI/180.;
              delta_lambda = (glonFinal-glonInit) * M_PI/180.;
            //#Haversine
              a = sin(delta_phi/2.) * sin(delta_phi/2.) +
              cos(phi1) * cos(phi2) *
              sin(delta_lambda/2.) * sin(delta_lambda/2.);
              c = 2. * atan2(sqrt(a), sqrt(1.-a));
           //#range
              *range = R * c; // in metres
              y = sin(delta_lambda) * cos(phi2);
              x = cos(phi1)*sin(phi2) -
              sin(phi1)*cos(phi2)*cos(delta_lambda);
              theta = atan2(y, x);
           // #bearing
            //*bearing = (theta*180/PI + 360) % 360; // in degrees
            *bearing = fmod((theta*180./PI + 360.) , 360.);

return 0;
}
#include <stdio.h>
#include <math.h>

int RtoG (double range, 
          double bearing, 
          double  glonInit, 
          double glatInit, 
          double *glonFinal, 
          double *glatFinal)
{
//Earth radius
              double R;
              R = 6371e3; // metres
// input longitude and latitude in degrees
// range in m
//where	φ is latitude, λ is longitude,
// θ is the bearing (clockwise from north),
//  δ is the angular distance d/R;
//   d being the distance travelled,
//   R the earth’s radius
          *glatFinal = (asin( sin(glatInit * M_PI/180.)*cos(range/R) +
                      cos(glatInit * M_PI/180.) * sin(range/R) * cos(bearing * M_PI/180.) ))*180./M_PI;
          *glonFinal = glonInit + (atan2(sin(bearing * M_PI/180.) * sin(range/R)*cos(glatInit * M_PI/180.),
                           cos(range/R) - sin(glatInit  * M_PI/180.) * sin(*glatFinal * M_PI/180.)))*180./M_PI;
//The longitude can be normalised to −180…+180 using (lon+540)%360-180
return 0;
}

#include <stdio.h>
#include <math.h>
int main(void){
double range, bearing;
//in degrees
double glatInit  = 37.;
double glonInit  = 75.;
double glatFinal = 18.;
double glonFinal = 66. ;
GIS2Radar(&range,&bearing, glonInit, glatInit, glonFinal, glatFinal);
printf("%f\n", range/1.0e3);
printf("%f\n", bearing);
RtoG (range, bearing,  glonInit,  glatInit, &glonFinal,  &glatFinal);
printf("glonFinal= %f\n",glonFinal);
printf("glatFinal= %f\n",glatFinal);
return 0;
}
