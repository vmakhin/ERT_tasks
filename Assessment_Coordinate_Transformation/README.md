#Assessment Coordinate Transformation: Implement coordinate conversion utilities that can convert radar coordinates (bearing, range) to GIS coordinates (lat, lon) and vice versa in C. The header declaration could be the following or your own design. 

#int GIS2Radar(double *range, 
#	      double *bearing, 
#              double glonInit, 
#              double glatInit, 
#              double glonFinal, 
#              double glatFinal);

#int RtoG (double range, 
#          double bearing, 
#          double  glonInit, 
#          double glatInit, 
#          double *glonFinal, 
#          double *glatFinal);


#You can use the following as the location of interest

#Initial: Wallops Islands, lat: 37N, long: 75W) 
#
#Final: Puerto Rico, lat: long: 18N, 66W) 

#SOLUTION

#To transform GIS to radar coordinates we created two functions

# Using required parameters we can calculate coordinate transformation

#To transform GIS to radar coordinates we created two functions

# Using required parameters we can calculate coordinate transformation

[userdir]$ make coord_trans

# Run executable

[userdir]$./coord_trans.out

#After run we should get similar output 
glonInit= 75.000000
glatInit= 37.000000
glonFinal= 66.000000
glatFinal= 18.000000
2288.663608
205.036783
glonFinal= 66.000000
glatFinal= 18.000000
