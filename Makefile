CPP=g++
CPPFLAGS=-Wall -Wextra -g -pedantic -std=c++11
GOLDBACH=2016-10-19-goldbach
SERIES=2016-11-02-series

$(SERIES): $(SERIES).cpp
	$(CPP) $(CPPFLAGS) largeint.cpp $(SERIES).cpp -o $(SERIES)

$(GOLDBACH): $(GOLDBACH).cpp
	$(CPP) $(CPPFLAGS) $(GOLDBACH).cpp -o $(GOLDBACH)

clean:
	rm -f $(GOLDBACH)
