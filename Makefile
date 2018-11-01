INCPTH := ./include/
SRCPTH := ./src/
BLDPTH := ./build/
BINPTH := ./bin/

GPPC := g++ -g -Og -c -std=c++11 -I$(INCPTH)
GPPM := g++ -g -Og -std=c++11 -I$(INCPTH)

build : 

$(BLDPTH)RelationshipParser.o : $(SRCPTH)RelationshipParser.cpp $(INCPTH)RelationshipParser.hpp
	@mkdir -p $(BLDPTH)
	$(GPPC) -o $@ $<

$(BLDPTH)Closure.o : $(SRCPTH)Closure.cpp $(INCPTH)Closure.hpp
	@mkdir -p $(BLDPTH)
	$(GPPC) -o $@ $<

$(BLDPTH)CSV.o : $(SRCPTH)CSV.cpp $(INCPTH)CSV.hpp
	@mkdir -p $(BLDPTH)
	$(GPPC) -o $@ $<

$(BLDPTH)Storage.o : $(SRCPTH)Storage.cpp $(INCPTH)Storage.hpp $(BLDPTH)CSV.o
	@mkdir -p $(BLDPTH)
	$(GPPC) -o $@ $<

clean :
	rm -rf ./build
	rm -rf ./bin