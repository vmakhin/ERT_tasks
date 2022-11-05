fortran_files = cira.for igrf.for iridreg.for irifun.for irisub.for iritec.for iriflip.for

f77flags = -std=legacy -w -g -O2 -fbacktrace -ff2c -fno-automatic -fPIC

irifolder = /home/vmakhin/ERTassessment/Assessment_IRI_EDP

create_shared_lib77:

	gfortran $(f77flags) -shared  -o libiriv77.so -fPIC cira.for igrf.for iridreg.for irifun.for irisub.for iritec.for iriflip.for 

iri_driver_mainc:

	gcc -g -pedantic -std=c99 -c iri_driver_main.c 

test_gfortranmain:
	
	gfortran $(f77flags)  -o test_gfortranmain.out iri_driver_sub.for  gnuplot_i.o iri_driver_main.o $(fortran_files) $(irifolder)/libiriv77.so /usr/local/lib/libf2c.a  -lm

#test_gfortranmain:
#	
#	gfortran $(f77flags)  -o test_gfortranmain.out iri_driver_sub.for  gnuplot_i.o iri_driver_main.o $(fortran_files) /home/vmakhin/ERTtask1/Task1/iri_debug/libiriv77.so /usr/local/lib/libf2c.a  -lm
