# Domotique
Project domotique EPFL.
par Tiarnach Ó Riada [pcoo34] et Maxence Marie Thibaud Petitpierre [pcoo30]ctor.cpp

## Structure des fichiers soumis
```
|-- .doxyfile
      fichier du configuration Doxygen
|-- conf_files
|   |-- exemplaires/
          des exemples fichiers de configuration utilisée pendant le testing
|   `-- paysage.xml
          le fichier final
|-- Debug
      makefiles 
|-- Domotique.launch
|-- html/
      documentation HTML genere par doxygen
|-- out
      directoire contient des fichiers journals et des données gnuplot, ainsi que le pdf des traces gnuplot
|   |-- exemplaires/
          des fichiers journals et données gnuplot correspondant aux scénarios décrits dans les fichiers /conf_files/exemplaires/*.xml
|   |-- paysage.gp
|   |-- paysage.log
|   |-- paysage.pdf
|   `-- plot.gnuplot
          des fichiers journals correspondants aux paysage requise
`-- src
     des fichiers source
```
