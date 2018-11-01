INCPTH := ./include/
SRCPTH := ./src/
BLDPTH := ./build/
BINPTH := ./bin/

CC := g++ -g -Og -std=c++11 -I$(INCPTH)

build : 


clean :
	rm -rf ./build
	rm -rf ./bin