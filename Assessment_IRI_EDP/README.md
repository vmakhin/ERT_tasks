Assessment IRI EDP: Create a C-based modeling and simulation program
 that drive IRI model Fortran code.
 The code should capture and generate vertical EDP (Electron Density Profile)
 for a given time and location of interest. 

What the project does

This project creates a new capability to  
Why the project is useful
How users can get started with the project

DOWNLOAD FILES FOR IRI PROJECT USING bash script

#Set execute permission to script

[userdir]$ chmod +x download_iri.sh

#Run script

[userdir]$./download_iri.sh

After successful run of this script all files 
for iri project will be in current folder 
----------------------------------

ALTERNATIVELY ONE COULD DOWNLOAD FILES FOR IRI PROJECT MANUALLY 


1.On the first step one should download iri2016 model
 from International Reference Ionosphere webpage  irimodel.org.

Using wget utility download 00_iri.tar file with iri2016 model
 typing on Linux computer line:

[userdir]$ wget https://irimodel.org/IRI-2016/00_iri.tar 

One will see output similar to this:

--2022-11-03 20:41:08--  https://irimodel.org/IRI-2016/00_iri.tar
Resolving irimodel.org (irimodel.org)... 216.194.169.102
Connecting to irimodel.org (irimodel.org)|216.194.169.102|:443... connected.
HTTP request sent, awaiting response... 200 OK
Length: 3512320 (3.3M) [application/x-tar]
Saving to: ‘00_iri.tar’

100%[=================...============>] 3,512,320   8.62MB/s   in 0.4s

2022-11-03 20:41:09 (8.62 MB/s) - ‘00_iri.tar’ saved [3512320/3512320]

1.1 Check if file is in the folder
 
[userdir]$ ls

00_iri.tar  README.md

1.2 Untar (extract files) files from  this file using command:

[userdir]$ tar -xvf 00_iri.tar

One will see list of files after extraction of files from tar file

[userdir]$ ls

00_iri2016-License.txt  dgrf1945.dat  dgrf1970.dat  dgrf1995.dat  igrf2020.dat   irifun.for        iritest.for  mcsat15.dat  mcsat20.dat
00_iri.tar              dgrf1950.dat  dgrf1975.dat  dgrf2000.dat  igrf2020s.dat  irirtam.for       mcsat11.dat  mcsat16.dat  mcsat21.dat
00readme.txt            dgrf1955.dat  dgrf1980.dat  dgrf2005.dat  igrf.for       irirtam-test.for  mcsat12.dat  mcsat17.dat  mcsat22.dat
00_update_history.txt   dgrf1960.dat  dgrf1985.dat  dgrf2010.dat  iridreg.for    irisub.for        mcsat13.dat  mcsat18.dat  README.md
cira.for                dgrf1965.dat  dgrf1990.dat  dgrf2015.dat  iriflip.for    iritec.for        mcsat14.dat  mcsat19.dat

1.3 Inside the 00readme.txt one can find full description of the Fortran subroutines and
extracted data files.

It is also required to download additional files:

At http://irimodel.org/indices/:
ig_rz.dat       This file(s) contains the solar and ionospheric indices (IG12, Rz12)
                for the time period from Jan 1958 onward. The file is updated
                quarterly. It is read by subroutine tcon in irifun.for (ASCII).
                [This file will be updated at close to quarterly intervals]
apf107.dat      This file provides the 3-hour ap magnetic index and F10.7 daily
                81-day and 365-day index from 1960 onward (ASCII).
                [This file will be updated at close to quarterly intervals]
Daily updates of these two files are available from the ECHAIM website (David
Themens) as described on irimodel.org.

At http://irimodel.org/COMMON_FILES/:
CCIR%%.dat              Monthly coefficient files for the CCIR foF2 and M(3000)F2 models
                %%=month+10
URSI%%.dat              Monthly coefficient files for the URSI foF2 model
                %%=month+10
 

We will these files download files using wget utility:

[userdir]$ wget http://irimodel.org/indices/ig_rz.dat

[userdir]$ wget http://irimodel.org/indices/apf107.dat

[userdir]$ wget http://irimodel.org/COMMON_FILES/00_ccir-ursi.tar

[userdir]$ tar -xvf 00_ccir-ursi.tar


#DOWNLOAD and CREATE OBJECT FILE gnuplot_i.o  FROM gnuplot_i.c and gnuplot_i.h files

[userdir]$ download_gnuplot_i.sh

#as a result you will get created folder with name gnuplot_i_iri
#with gnuplot_i.o and gnuplot_i.h files which will be used to create gnuplots
# with iri generated data

#----------------------------------------------------------

#Generate IRI2016 code running and plotting gnuplot of DENSITY vs HEIGHT

#1. Copy from subfolder iri_driver two files: iri_driver_main.c and iri_driver_sub.for
#2. Run three make commands:
2.1 CREATE SHARED IRI library

make create_shared_lib77

2.2 CREATE object file for iri_driver_main.c with C request to plot GNUPLOT chart
In this function  we define interaction with GNUPLOT library using gnuplot_i.o
object file

2.3 NEXT step is to run make command to create executable:

make test_gfortranmain

After run this generates executable file test_gfortranmain.out

We will run it using command:

[userdir]$ ./test_gfortranmain.out

This command will call IRI2016 model and produce GNUPLOT chart which will stay open until
press q or close chart using X on the right corner of window with chart.

In current setup code will produce X11 chart on screen.
In order to produce file with image one need to change type of terminal.


# This is limited version of code which will produce Electron NUMBER DENSITY vs HEIGHT

EXAMPLE of OUTPUT is abc.png file in the current folder

#WORK in progress to extend capabilities of this set of functions and subroutines 

We need to create tar file with all files to create IRI2016 model
 and produce chart of  Electron number density vs height from 60 to 600 km.

Whe users can get help with your project sending email to : vmakhin@gmail.com

Who maintains and contributes to the project:

Volodymyr Makhin
Sr. Computational Physicist

