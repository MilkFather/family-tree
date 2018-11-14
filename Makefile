INCPTH := ./include/
SRCPTH := ./src/
BLDPTH := ./build/
BINPTH := ./bin/

GPPC := g++ -g -Og -c -std=c++11 -I$(INCPTH)
GPPM := g++ -g -Og -std=c++11 -I$(INCPTH)

build : $(BLDPTH)main.o
	@mkdir -p $(BINPTH)
	$(GPPM) -o $(BINPTH)tree $(BLDPTH)main.o $(BLDPTH)Person.o $(BLDPTH)Relation.o $(BLDPTH)RelationshipParser.o $(BLDPTH)CSV.o $(BLDPTH)Storage.o $(BLDPTH)Service.o

$(BLDPTH)main.o : $(SRCPTH)main.cpp $(BLDPTH)Service.o
	@mkdir -p $(BLDPTH)
	$(GPPC) -o $@ $<

$(BLDPTH)Person.o : $(SRCPTH)Person.cpp $(INCPTH)Person.hpp
	@mkdir -p $(BLDPTH)
	$(GPPC) -o $@ $<

$(BLDPTH)Relation.o : $(SRCPTH)Relation.cpp $(INCPTH)Relation.hpp
	@mkdir -p $(BLDPTH)
	$(GPPC) -o $@ $<

$(BLDPTH)RelationshipParser.o : $(SRCPTH)RelationshipParser.cpp $(INCPTH)RelationshipParser.hpp $(BLDPTH)Relation.o
	@mkdir -p $(BLDPTH)
	$(GPPC) -o $@ $<

$(BLDPTH)CSV.o : $(SRCPTH)CSV.cpp $(INCPTH)CSV.hpp
	@mkdir -p $(BLDPTH)
	$(GPPC) -o $@ $<

$(BLDPTH)Storage.o : $(SRCPTH)Storage.cpp $(INCPTH)Storage.hpp $(BLDPTH)Person.o $(BLDPTH)Relation.o $(BLDPTH)RelationshipParser.o $(BLDPTH)CSV.o
	@mkdir -p $(BLDPTH)
	$(GPPC) -o $@ $<

$(BLDPTH)Service.o : $(SRCPTH)Service.cpp $(INCPTH)Service.hpp $(BLDPTH)Person.o $(BLDPTH)Relation.o $(BLDPTH)Storage.o
	@mkdir -p $(BLDPTH)
	$(GPPC) -o $@ $<

clean :
	rm -rf ./build
	rm -rf ./bin