INCPTH := ./include/
SRCPTH := ./src/
BLDPTH := ./build/
BINPTH := ./bin/

CC := g++ -g -Og -std=c++11 -I$(INCPTH)

build : 

$(BLDPTH)RelationshipParser.o : $(SRCPTH)RelationshipParser.cpp $(INCPTH)RelationshipParser.hpp
	@mkdir -p $(BLDPTH)
	$(CC) -o $@ $<

$(BLDPTH)Closure.o : $(SRCPTH)Closure.cpp $(INCPTH)Closure.hpp
	@mkdir -p $(BLDPTH)
	$(CC) -o $@ $<

$(BLDPTH)CSV.o : $(SRCPTH)CSV.cpp $(INCPTH)CSV.hpp
	@mkdir -p $(BLDPTH)
	$(CC) -o $@ $<

$(BLDPTH)Storage.o : $(SRCPTH)Storage.cpp $(INCPTH)Storage.hpp $(BLDPTH)CSV.o
	@mkdir -p $(BLDPTH)
	$(CC) -o $@ $<

clean :
	rm -rf ./build
	rm -rf ./bin