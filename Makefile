CXX = g++
CXXFLAGS = -Wall -std=c++11

OBJECTS = main.o
HFILES = singlelist.hpp
TARGET = main.out

%.o : %.cpp $(HFILES) Makefile
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(TARGET) : $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(TARGET)

.PHONY : clean run

run : $(TARGET)
	./$(TARGET)

clean :
	rm -f $(TARGET) *.o core