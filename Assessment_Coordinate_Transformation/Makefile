#coord_trans:
#
#	gcc -o coord_trans.out coord_trans.c -lm


all: test_GIS2Radar.out, test_RtoG.out

# GIS2Radar section of makefile
#
test_GIS2Radar.out: test_GIS2Radar.o
	 gcc -o test_GIS2Radar.out test_GIS2Radar.o GIS2Radar.o -I ./GIS2Radar.h -lm

test_GIS2Radar.o: test_GIS2Radar.c
	 gcc -c test_GIS2Radar.c  -I./GIS2Radar.h

GIS2Radar.o: GIS2Radar.c 
	 gcc -c GIS2Radar.c -I. GIS2Radar.h


#RtoG section of makefile
#     
test_RtoG.out: RtoG.o
	 gcc -o test_RtoG.out test_RtoG.o RtoG.o -I ./RtoG.h -lm

test_RtoG.o: test_RtoG.c
	 gcc -c test_RtoG.c  -I ./RtoG.h

RtoG.o: RtoG.c 
	 gcc -c RtoG.c -I. RtoG.h

clean:
	 rm GIS2Radar.o RtoG.o  mainflux.out
