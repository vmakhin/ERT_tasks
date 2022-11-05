/*Use a structured grid that has 1000 grid cells, with a cell width of 1.0 meters.
  All variable values are stored in the cell centers
Width of a square wave should cover at least ten grid cells
Recommend testing with a square wave that covers 100 grid cells (see example gif below)
Use a CFL condition where C_max<0.5 
Use positive velocity of 10.0 m/s
Use a density value of 25.0
Only transport density values > 1.0e-6  */

#include <stdio.h>
#include <flux_corrected_transport.h>
int main(void){
    int arrlen = 1000;
    double dt = 1.00;
    double dx = 1.0;  /* dx = 1.0 m*/
  /*  double RHO = 25.0;*/   /* kg/m^3 */
    double RHOvoid = 1.0e-4; /* */
   /* double VEL = 10.0;*/ /* m/s*/
    double C_max = 0.5; /* Courant number*/
//    dt = C_max*dx/10.0;
//    printf("%lf\n", dt);
    double X[arrlen];
    double RHO[arrlen];
    double RHOOUT[arrlen];
    double VEL[arrlen];
    double time = 0.0;
    FILE *outfile;
 /*
    * @param U[in] Quantity to transport
   * @param V[in] Velocity values
   * @param arrlen[in] Size of U, V, and U_trnsp arrays
   * @param dt[in] Delta time step
   * @param dx[in] grid cell length
   * @param U_trnsp[out] Transported quantity
   */
        int i;
        dt = C_max*dx/10.0;
        printf("%lf\n", dt);
        for (i=0;i<arrlen;i++){
            X[i]=i*dx;           
            RHO[i] = RHOvoid;
            VEL[i] = 10.0;
                     
}
	
        for (i=50;i<=149;i++){
            RHO[i] = 25.0;
        }             
        int number;
        outfile = fopen("densityvstime.txt","w");
	for(number=0;number<=200;number++)	//for loop to print 1-10 numbers
	{
                time = time + dt;
                flux_corr_method(RHO, VEL, arrlen,  dt,  dx,  RHOOUT);
                for (i=0;i<arrlen; i++){
                  RHO[i] = RHOOUT[i];
                 fprintf(outfile,"%f %f\n",X[i],RHOOUT[i]);
                 }
                  fprintf(outfile,"\n");
                  fprintf(outfile,"\n");
                  fprintf(outfile,"\n");
                printf("%f\n",time);
                time = time + dt;
    }
                fclose(outfile);
 /*    flux_corr_method(double *U, double *V, int arrlen, double dt, double dx, double *U_trnsp);*/
return 0;
}
