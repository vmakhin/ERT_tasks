### Assessment IRI EDP:  
     Create a C-based modeling and simulation program that drives IRI model Fortran code. The code should capture and generate vertical  
     EDP (Electron Density Profile) for a given time and location of interest.  
      
##### What the project does? 
      
> Creates a C-based modeling and simulation program that drives IRI model Fortran code. C Modeling interface captures and generates EDP (Electron Density Profile) for a given time and location of interest. 
      
###### Why the project is useful? 
      
> This project creates a new capability to visualize results of **iri2016 Fortran** modeling by  
     using Gnuplot interface with ANSI C (gnuplot_i). This project will simplify graphical representation of the Fortran IRI modeling results. 
      
###### How users can get started with the project? 
      
> We created a set of scripts which allows users  **download necessary files, compile them, link and create excecutables** 
      
###### System Requirements 
      
     1. Linux CENTOS 7 
     2. GCC (gcc and gfortran compilers) 
     2. F2c Utility 
     3. Gnuplot 
     4. gnuplot_i ANSI C interface to Gnuplot (installed by using included bash scripts) 
     5. wget utility 
      
** Get Fortran Files of IRI Project Using the bash script Created in This Project  ** 
      
** Set execute permission to the script ** 
``` 
     [userdir]$chmod +x download_iri.sh 
``` 
##### Run the script 
``` 
     [userdir]$./download_iri.sh 
``` 
      
**After successful run of this script all files  
     for Fortran iri project will be in the current folder ** 
      
<span style="color:red">*ALTERNATIVELY ONE COULD DOWNLOAD FILES FOR IRI PROJECT MANUALLY*</span>. 
    
**THIS STEP Could Be Skipped Until The  Section of This README file  
DOWNLOAD and CREATE OBJECT FILE gnuplot_i.o  FROM gnuplot_i.c and gnuplot_i.h files** 
      
#### One should download iri2016 Fortran model 
     from International Reference Ionosphere webpage  irimodel.org [iri2016 model](http://irimodel.org/IRI-2016/). 
      
**The detailed description of what the script download_iri.sh does is presented below** 
      
One can use ***wget*** utility to download ***00_iri.tar*** file with iri2016 model 
      by typing on Linux computer line: 
``` 
     [userdir]$ wget https://irimodel.org/IRI-2016/00_iri.tar  
``` 
      
     One will see output similar to this: 
``` 
   
     --2022-11-03 20:41:08--  https://irimodel.org/IRI-2016/00_iri.tar 
     Resolving irimodel.org (irimodel.org)... 216.194.169.102 
     Connecting to irimodel.org (irimodel.org)|216.194.169.102|:443... connected. 
     HTTP request sent, awaiting response... 200 OK 
     Length: 3512320 (3.3M) [application/x-tar] 
     Saving to: ‘00_iri.tar’ 
      
     100%[=================...============>] 3,512,320   8.62MB/s   in 0.4s 
      
     2022-11-03 20:41:09 (8.62 MB/s) - ‘00_iri.tar’ saved [3512320/3512320] 
``` 
##### Check if file _00_iri.tar appeared in the folder 
```  
     [userdir]$ ls 
      
     00_iri.tar  README.md 
``` 
##### Untar (extract) files from  00_iri.tar file using the following command: 
``` 
     [userdir]$ tar -xvf 00_iri.tar 
``` 
***One will see a list of files after the extraction from tar file*** 
``` 
     [userdir]$ ls 
``` 
``` 
     00_iri2016-License.txt  dgrf1945.dat  dgrf1970.dat  dgrf1995.dat  igrf2020.dat   irifun.for        iritest.for  mcsat15.dat  mcsat20.dat 
     00_iri.tar              dgrf1950.dat  dgrf1975.dat  dgrf2000.dat  igrf2020s.dat  irirtam.for       mcsat11.dat  mcsat16.dat  mcsat21.dat 
     00readme.txt            dgrf1955.dat  dgrf1980.dat  dgrf2005.dat  igrf.for       irirtam-test.for  mcsat12.dat  mcsat17.dat  mcsat22.dat 
     00_update_history.txt   dgrf1960.dat  dgrf1985.dat  dgrf2010.dat  iridreg.for    irisub.for        mcsat13.dat  mcsat18.dat  README.md 
     cira.for                dgrf1965.dat  dgrf1990.dat  dgrf2015.dat  iriflip.for    iritec.for        mcsat14.dat  mcsat19.dat 
``` 
      
##### Inside the **00readme.txt** one can find the full description of the Fortran subroutines and the extracted data files 
      
_It is also required to download some additional files:_ 
      
_at http://irimodel.org/indices/:_ 
      
>ig_rz.dat       This file(s) contains the solar and ionospheric indices (IG12, Rz12) 
>                for the time period from Jan 1958 onward. The file is updated 
>                quarterly. It is read by subroutine tcon in irifun.for (ASCII). 
>                [This file will be updated at close to quarterly intervals] 
>apf107.dat      This file provides the 3-hour ap magnetic index and F10.7 daily 
>                81-day and 365-day index from 1960 onward (ASCII). 
>                [This file will be updated at close to quarterly intervals] 
                      
>Daily updates of these two files are available from the ECHAIM website (David 
Themens) as described on irimodel.org. 
      
>At http://irimodel.org/COMMON_FILES/: 
>CCIR%%.dat              Monthly coefficient files for the CCIR foF2 and M(3000)F2 models 
                     %%=month+10 
>URSI%%.dat              Monthly coefficient files for the URSI foF2 model 
                     %%=month+10 
       
      
### We will download files using wget utility: 
``` 
     [userdir]$wget http://irimodel.org/indices/ig_rz.dat 
      
     [userdir]$wget http://irimodel.org/indices/apf107.dat 
      
     [userdir]$wget http://irimodel.org/COMMON_FILES/00_ccir-ursi.tar 
      
     [userdir]$tar -xvf 00_ccir-ursi.tar 
``` 
<span style="color:red">*END of SECTION of DOWNLOAD FILES FOR IRI FORTRAN PROJECT MANUALLY*</span>. 
      
#### Download and Create the Object File **gnuplot_i.o**  using gnuplot_i.c function  and gnuplot_i.h header files from gnuplot_i distribution, 
``` 
     [userdir]$ download_gnuplot_i.sh 
``` 
#### This script downloads from  [gnuplot_i] web page gnuplot_i ANSI C **source code**, 
**compiles** it and creates **gnuplot_i.o** object file 
      
     It will create folder with name ***gnuplot_i_iri*** 
     with gnuplot_i.o and gnuplot_i.h files which will be used to create ***gnuplot*** charts 
     with iri generated data 
      
#### Generate IRI2016 code running and plotting gnuplot of Density vs Altitude 
      
>Copy from subfolder iri_driver two files to main folder: 
***iri_driver_main.c and iri_driver_sub.for*** 
``` 
     [userdir]$cp iri_driver/iri_driver_main.c  
     [userdir]$cp iri_driver/iri_driver_sub.for  
``` 
     After that run the three make commands: 
      
##### Create SHARED IRI library from Fortran subroutines 
``` 
     [userdir]$make create_shared_lib77 
``` 
#### Create the object file for function iri_driver_main.c with ANSI C request to plot GNUPLOT chart 
      
     This interface was built using gnuplot_i ANSI C interface [gnuplot_i](http://ndevilla.free.fr/gnuplot/). 
      
     In this step  we define the interaction with GNUPLOT library using gnuplot_i.o 
     object file 
      
``` 
     [userdir]$make iri_driver_mainc 
``` 
#### NEXT step is to use make command to create the executable program: 
``` 
     [userdir]$make test_gfortranmain 
``` 
      
##### After that step generate the executable file test_gfortranmain.out 
      
#### We will run it using the command: 
``` 
     [userdir]$./test_gfortranmain.out 
``` 
     This command will call ***IRI2016 model*** and produce ***GNUPLOT chart*** 
      
     If we use ***set terminal X11*** the plot will stay open until 
     one presses q on keyboard or closes this chart using X on the right corner of the chart window. 
      
     In current setup *** code will produce PNG file*** in the current folder. 
      
     An example of the PNG image format file generated by using gnuplot with **set terminal PNG** is presented below
      
<img src="NevsH.png"  alt="drawing"  width="400"  height="400"/> 
      
     In order to produce the file with an image on the screen one needs to change the type of the terminal to X11. 
      
<!-- ['Electron Density vs Altitude'](NevsH.png) --> 
      
**This is a limited version of the code to produce EDP (Electron Density Profile)** 
**for a given time and the location of interest** 
      
#### An EXAMPLE of OUTPUT is NevsH.png file is in the current folder 
      
**The WORK is IN PROGRESS to extend the capabilities of this set of functions and subroutines** 
      
**As a Result of This project** 
     We created tar file with all script files to build IRI2016 model 
      
     and produce a chart of  Electron Number Density vs Altitude from 60 to 600 km. 
      
**The users can get help with their projects sending email to:** 
      
     vmakhin@gmail.com 
      
**Who maintains and contributes to the project:** 
      
     Volodymyr Makhin,  
     Sr. Computational Physicist 
 








