## Assessment of modeling fluid dynamic: 
Transport a square wave across a 1-D structured grid.

#### To create gif animated file using provided flux_corrected function

### Solution:

#### I followed next steps to create a gif animated file

1. **Clean files**
```
[userdir]$make clean
```
2. **Create an object file from flux_corrected_transport.c C file**
```
[userdir]$make flux_corrected_transport.o
```
3. **Create mainflux.o object file**
```
[userdir]$make mainflux.o
```
4. **Create the executable mainflux.out**
```
[userdir]$make maneflux.out
```
5. **Run mainflux.out executable file**
```
[userdir]$./mainflux.out
```

After step 5 file with the name densityvstime.txt will be generated.

#### To CREATE a gif animated movie, type on the console:
```
[userdir]$gnuplot < gif_animation_density.gnu
```
> This will produce a densityvsx.gif file for the 6 sec as requestedin this task; this uses an animate.gnu file  

The animation of the Density Spatial Profile vs Time until 6 sec is presented below  

<img src="densityvsx.gif"  alt="drawing"  width="500"  height="500"/>
