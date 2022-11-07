### Assessment Interpolation

Using any language and plotting packages you like, interpolate
the given point location values to a structured grid of longitude
 and latitude locations. This task will ask the candidate to implement
 a procedure that interpolates known grid points and values
 to a structured grid

### My Solution based on Python and third party tools:

For the solution of this problem, I used  language Python and third-party tools [1].
I applied several methods to solve this problem.

Point locations are shown on Fig1.

<img src="plot_locations.png"  alt="drawing"  width="400"  height="400"/>

On the first approach I applied Delaunay triangulation from Scipy library.
Point Locations are shown is on Fig. 2

<img src="Delaunay_Triangulation.png"  alt="drawing"  width="400"  height="400"/> 

Using the area coordinates inside of each triangle and values at the corners of
 triangles with application of linear interpolation function Ref.[3] I got the first result
 which is shown on Fig3.

<img src="Delaunay_Linear_Interpolation.png"  alt="drawing"  width="400"  height="400"/> 

### This approach gives a very rough linear interplolation using area coordinates representation of the values on the structured grid. 

This approach doesn’t consider values outside Delaunay triangles.

Another limitation of this approach is very limited extrapolation capabilities
 outside the area covered by triangles.
 
### The second approach I used was based on applying nearest analysis with original kriging method [3] with spherical variogram model.

I used publicly available Python tool **PyKrige**.

This method involves coordinates of the points with known values and the whole set of values
 in these points to create an interpolation object over the whole rectangular area.
 
 On Fig.4 and Fig.55 we can see the final result of our application of the nearest approximation
 using kriging function
 
<img src="assessment_interpolation.png"  alt="drawing"  width="400"  height="400"/> 

and Fig.5 3D visualization of interpolation

<img src="snaps__top_nearest.png"  alt="drawing"  width="500"  height="500"/>


### References
1. https://github.com/GeoStat-Framework/PyKrige
2. https://www.e-education.psu.edu/geog586/node/685
3. L. J. Segerlind, Applied Finite Element Analysis, Wiley & Sons, 1976.

**The users can get help with their projects sending email to:** 
      
     vmakhin@gmail.com 
      
**Who maintains and contributes to the project:** 
      
     Volodymyr Makhin,  
     Sr. Computational Physicist 
