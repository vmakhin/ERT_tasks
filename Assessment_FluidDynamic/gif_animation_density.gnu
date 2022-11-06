#We will plot results of modeling flux in this gif animation
reset
#set term gif animate delay 1
#set term gif animate delay 10
set terminal gif size 800, 600 animate delay 10
set output "densityvsx.gif" 
n=200    #n frames corresponds to requested 10 sec end time
dt=0.05
set xrange [0:1000]
set yrange [0:30]
set xlabel "meters"
set ylabel "density"
i=0
load "animate.gnu"
