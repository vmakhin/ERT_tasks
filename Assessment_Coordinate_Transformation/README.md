#### Assessment Coordinate Transformation: Implement coordinate conversion utilities that can convert radar coordinates (bearing, range) to GIS coordinates (lat, lon) and vice versa in C. The header declaration could be the following or your own design. 
```
int GIS2Radar(double *range, 
	      double *bearing, 
              double glonInit, 
              double glatInit, 
              double glonFinal, 
              double glatFinal);
```
```
int RtoG (double range, 
          double bearing, 
          double  glonInit, 
          double glatInit, 
          double *glonFinal, 
          double *glatFinal);
```

You can use the following as the location of interest

Initial: Wallops Islands, lat: 37N, long: 75W) 

Final: Puerto Rico, lat: long: 18N, 66W) 

#### MY SOLUTION

I checke publications and found existing solution implemented in Javascript on [1][2].

I used existing JavaScript implementation of coordinate transformations to create C functions.

Implemented solution is based of spherical shape of the Earth which gives according to Ref.1 0.3% of error.

To transform GIS to the radar coordinates we created two functions in C.

Using the required parameters (Initial: Wallops Islands, lat: 37N, long: 75W) 

Final: Puerto Rico, lat: long: 18N, 66W)) we can calculate coordinates transformation from GIS to radar and radar to GIS

```
[userdir]$ make coord_trans
```
### Run executable
```
[userdir]$./coord_trans.out
```
After the run we got the following output 
```
glonInit= 75.000000
glatInit= 37.000000
glonFinal= 66.000000
glatFinal= 18.000000
2288.663608
205.036783
glonFinal= 66.000000
glatFinal= 18.000000
```

**I tried to compare my results with Ref1 using provided for this task coordinates

<img src="fromRef1.png"  alt="drawing"  width="500"  height="500"/>

I got some discrepancy in comparison of my and published on internet results and trying to resolve them.

### References
1. https://en.wikipedia.org/wiki/Haversine_formula#cite_note-Brummelen_2013-1
2. http://www.movable-type.co.uk/scripts/latlong.html
3. http://www.jaimerios.com/?p=39

**The users can get help with their projects sending email to:** 
      
     vmakhin@gmail.com 
      
**Who maintains and contributes to the project:** 
      
     Volodymyr Makhin,  
     Sr. Computational Physicist 
