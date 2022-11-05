## Assessment of modeling fluid dynamic: 
Transport a square wave across a 1-D structured grid.

#### To create gif animated file using provided flux_corrected function

#### I followed next steps to create a gif animated file

1. **Clean files**
```
[userdir]$make clean
```
2. **Create object file from flux_corrected_transport.c C file**
```
[userdir]$make flux_corrected_transport.o
```
3. **Create mainflux.o object file**
```
[userdir]$make mainflux.o
```
4. **Create executable mainflux.out**
```
[userdir]$make maneflux.out
```
5. **Run mainflux.out executable file**
```
[userdir]$./mainflux.out
```

After step 5 file with name densityvstime.txt will be generated.

#### CREATE gif animated movie type:
```
[userdir]$gnuplot < gif_animation_density.gnu
```
> To produce densityvsx.gif file for the 6 sec as requested in this task this uses animate.gnu file also 

Animation of Density Spatial Profile vs Time until 6 sec  

<img src="densityvsx.gif"  alt="drawing"  width="500"  height="500"/>
