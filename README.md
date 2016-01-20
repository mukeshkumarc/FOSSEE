 FOSSEE Toolbox project
 To execute stdfilt.cpp
 open terminal and paste 
 
$ g++ -ggdb `pkg-config --cflags opencv` -o `basename stdfilt.cpp .cpp` stdfilt.cpp `pkg-config --libs opencv`
$./stdfilt yourimageloaction with imagename
(if image and cpp both in same folder then $./stdfilt imagename.extension)

To execute multithresh.cpp

$ g++ -ggdb `pkg-config --cflags opencv` -o `basename multithresh.cpp .cpp` multithresh.cpp `pkg-config --libs opencv`
$./stdfilt yourimageloaction with imagename
(if image and cpp both in same folder then $./stdfilt imagename.extension)

