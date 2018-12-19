# first row as column headers
set key autotitle columnhead
set terminal png medium\
	size 2160,1440 \
#	transparent

#set output '| display png:-'
set xlabel 'tick'
names = "pp po sp so"
#plot for [file in files] for [i=2:4] file.".gp" u 1:i w l 
#set multiplot layout 2,2
do for [name in names] {
	outfile = sprintf('%s.png', name)
   set output outfile
   filename = name.".gp"
   set title sprintf("Scenario %s",name)
   plot for [i=2:4] filename u 1:i w l
}
#unset multiplot
