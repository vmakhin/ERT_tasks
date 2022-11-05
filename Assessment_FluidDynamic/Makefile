all: mainflux.out

mainflux.out: mainflux.o
	 gcc -o mainflux.out mainflux.o flux_corrected_transport.o -I ./flux_corrected_transport.h

mainflux.o: mainflux.c 
	 gcc -c mainflux.c -I. flux_corrected_transport.h
     
flux_corrected_transport.o: flux_corrected_transport.c
	 gcc -c -std=gnu99 flux_corrected_transport.c -I. flux_corrected_transport.h

clean:
	 rm mainflux.o flux_corrected_transport.o mainflux.out
