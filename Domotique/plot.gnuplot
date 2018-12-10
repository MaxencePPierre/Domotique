# This key uses the first row as column headers
set key autotitle columnhead
plot for [i=2:10] "Debug/data.gp" u 1:i w l 
