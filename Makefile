CPP=g++
CPPFLAGS=-O2 -Wall -pedantic -std=c++11
GOLDBACH=2016-10-19-goldbach

$(GOLDBACH): $(GOLDBACH).cpp
	$(CPP) $(CPPFLAGS) $(GOLDBACH).cpp -o $(GOLDBACH)

clean:
	rm -f $(GOLDBACH)
