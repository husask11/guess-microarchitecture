#!/bin/bash

gnuplot <<- EOF
set xlabel "memory size"
set ylabel "avg. access time"
set term png size 800, 800
set datafile separator ','

# Create some linestyles for our data
# pt = point type (triangles, circles, squares, etc.)
# ps = point size
set style line 1 lt 1 lc rgb "#A00000" lw 1 pt 7 ps 1
set style line 2 lt 1 lc rgb "#00A000" lw 1 pt 11 ps 1
set style line 3 lt 1 lc rgb "#5060D0" lw 1 pt 9 ps 1
set style line 4 lt 1 lc rgb "#0000A0" lw 1 pt 8 ps 1
set style line 5 lt 1 lc rgb "#D0D000" lw 1 pt 13 ps 1
set style line 6 lt 1 lc rgb "#00D0D0" lw 1 pt 12 ps 1
set style line 7 lt 1 lc rgb "#A00000" lw 1 pt 5 ps 1

set output "my_plot2.png"
plot "data2.csv" u 2:xtic(1) w lp ls 1 t "64B stride", \
"data2.csv" u 3:xtic(1) w lp ls 2 t "128B stride", \
"data2.csv" u 4:xtic(1) w lp ls 3 t "256B stride", \
"data2.csv" u 5:xtic(1) w lp ls 4 t "512B stride", \
"data2.csv" u 6:xtic(1) w lp ls 5 t "1MB stride", \
"data2.csv" u 7:xtic(1) w lp ls 6 t "2MB stride", \
"data2.csv" u 8:xtic(1) w lp ls 7 t "4MB stride"

set output "my_plot3.png"
plot "data2.csv" u 3:xtic(1) w lp ls 2 t "128B stride", \
"data2.csv" u 4:xtic(1) w lp ls 3 t "256B stride", \
"data2.csv" u 5:xtic(1) w lp ls 4 t "512B stride"

EOF


#display "my_plot.png"

#./cache > data.csv
