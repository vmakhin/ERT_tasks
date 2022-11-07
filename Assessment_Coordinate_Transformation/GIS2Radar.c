#include <math.h>
#include <stdio.h>
#define PI 3.14159265

int GIS2Radar(double *range, double *bearing, double glonInit, double glatInit, double glonFinal, double glatFinal)
{
              double x,y;
              double R;
              double phi1;
              double phi2;
              double delta_phi;
              double delta_lambda;
              double a,c,theta;
//              printf("glonInit= %f\n",glonInit);
//              printf("glatInit= %f\n",glatInit);
//              printf("glonFinal= %f\n",glonFinal);
//              printf("glatFinal= %f\n",glatFinal);
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
