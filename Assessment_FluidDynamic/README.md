# To create gif animated file using provided flux_limiter function
#Follow next steps


1. Clean files

[userdir]$ make clean

2. Create object file from flux_corrected_transport.c C file

[userdir]$ make flux_corrected_transport.o

3. Create mainflux.o object file

[userdir]$ make mainflux.o

4. Create executable mainflux.out

[userdir]$ make maneflux.out

5. run mainflux.out

[userdir]$ ./mainflux.out


After step 5 file with name densityvstime.txt will be generated.

#CREATE gif animated movie type:

6. gnuplot < gif_animation_density.gnu

#to produce densityvsx.gif file for the 6 sec as requested in this task
#this uses animate.gnu file also 
