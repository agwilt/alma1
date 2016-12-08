CPP=g++
CPPFLAGS=-Werror -Wall -Wextra -g -pedantic -O2
CXXFLAGS=-std=c++11
GOLDBACH=2016-10-19-goldbach
SERIES=2016-11-02-series
DIVISION=2016-11-16-division
ZUSKOMP=2016-11-30-zuskomp

$(ZUSKOMP): $(ZUSKOMP).cpp graph.cpp Makefile
	$(CPP) $(CPPFLAGS) $(CXXFLAGS) graph.cpp $(ZUSKOMP).cpp -o $(ZUSKOMP)

$(DIVISION): $(DIVISION).cpp Makefile
	$(CPP) $(CPPFLAGS) $(CXXFLAGS) $(DIVISION).cpp -o $(DIVISION)

$(SERIES): $(SERIES).cpp largeint.cpp Makefile
	$(CPP) $(CPPFLAGS) $(CXXFLAGS) largeint.cpp $(SERIES).cpp -o $(SERIES)

$(GOLDBACH): $(GOLDBACH).cpp largeint.cpp Makefile
	$(CPP) $(CPPFLAGS) $(CXXFLAGS) $(GOLDBACH).cpp -o $(GOLDBACH)

clean_$(GOLDBACH):
	rm -f $(GOLDBACH)

clean_$(SERIES):
	rm -f $(SERIES)

clean_$(DIVISION):
	rm -f $(DIVISION)

clean_$(ZUSKOMP):
	rm -f $(ZUSKOMP)
