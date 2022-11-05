#!/bin/bash
# Download and untar gnuplot_i, Gnuplot interfaces in ANSI C
# from http://ndevilla.free.fr/gnuplot/ web page:

mkdir gnuplot_i_iri

cd gnuplot_i_iri

wget from http://ndevilla.free.fr/gnuplot/gnuplot_i-2.11.tar.gz

tar -xvf gnuplot_i-2.11.tar.gz

cd gnuplot_i

make gnuplot_i.o

cp gnuplot_i.o ../..

cp src/gnuplot_i.h ../..

cd ..

ls

