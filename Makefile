CPP=g++
CPPFLAGS=-O2 -Werror -Wall -Wextra -g -pedantic -std=c++11
GOLDBACH=2016-10-19-goldbach
SERIES=2016-11-02-series
DIVISION=2016-11-16-division

$(DIVISION): $(DIVISION).cpp
	$(CPP) $(CPPFLAGS) $(DIVISION).cpp -o $(DIVISION)

$(SERIES): $(SERIES).cpp
	$(CPP) $(CPPFLAGS) largeint.cpp $(SERIES).cpp -o $(SERIES)

$(GOLDBACH): $(GOLDBACH).cpp largeint.cpp
	$(CPP) $(CPPFLAGS) $(GOLDBACH).cpp -o $(GOLDBACH)

clean_$(GOLDBACH):
	rm -f $(GOLDBACH)

clean_$(SERIES):
	rm -f $(SERIES)

clean_$(DIVISION):
	rm -f $(DIVISION)
