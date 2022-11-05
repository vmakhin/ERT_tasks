
plot 'densityvstime.txt' using 1:2 index i w l lt rgb 'blue' lw 3 title sprintf("t=%2.2f sec",i*dt)
i=i+1
if (i < n) reread
set output
