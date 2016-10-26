CPP=g++
CPPFLAGS=-O2 -Wall -pedantic
GOLDBACH=2016-10-19-goldbach

$(GOLDBACH):
	$(CPP) $(CPPFLAGS) $(GOLDBACH).cpp -o $(GOLDBACH)

clean:
	rm -f $(GOLDBACH)
