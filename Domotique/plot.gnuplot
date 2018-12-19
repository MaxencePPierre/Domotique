# This key uses the first row as column headers
set key autotitle columnhead
#plot for [i=2:10] "domotique.gp" u 1:i w l 
plot for [i=2:10] "pulsed_onoff.gp" u 1:i w l 
