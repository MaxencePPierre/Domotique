# first row as column headers
set key autotitle columnhead
set xlabel 'tick'
files = "pp po sp so"
plot for [file in files] for [i=2:4] file.".gp" u 1:i w l 
