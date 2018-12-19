set encoding utf8
# first row as column headers
set key autotitle columnhead
set terminal pdf colour enhanced font "arial,10" size 25.7cm,20cm

set xlabel 'tick'
name = "paysage"
subnames = "Chambre Aquarium"
units = "ºC pH"
sn = 0
set output name.".pdf"
set multiplot layout 2,1
do for [j in "1 4"] {
	sn = sn + 1
	outfile = sprintf('%s.png', name)
	filename = name.".gp"
	set title sprintf("Scenario %s",word(subnames,sn))
	set ylabel sprintf("[%s]", word(units,sn))
	plot for [i=j+1:j+3] filename u 1:i w l
}
unset multiplot
