CXX      =  $(shell   fltk-config --cxx)
DEBUG    =  -g         
CXXFLAGS =  $(shell fltk-config --use-gl --use-images --cxxflags ) -I.
LDFLAGS  =  $(shell  fltk-config --use-gl --use-images --ldflags )
LDSTATIC =  $(shell   fltk-config --use-gl --use-images --ldstaticflags )
LINK     =  $(CXX)    


TARGET = run_program 
OBJS = main.o MyOverlayWindow.o Box.o MyLine.o  
SRCS = main.cpp MyOverlayWindow.cpp Box.cpp MyLine.cpp 

.SUFFIXES: .o .cpp
%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(DEBUG) -c $<

all: $(TARGET)
	$(LINK) -o $(TARGET) $(OBJS) $(LDSTATIC)

$(TARGET): $(OBJS)
main.o: main.cpp Box.h MyOverlayWindow.h MyLine.h 
Box.o: Box.cpp  Box.h MyOverlayWindow.h Size.h
MyOverlayWindow.o: MyOverlayWindow.cpp MyOverlayWindow.h Box.h
MyLine.o: MyLine.cpp MyLine.h Box.h


clean: $(TARGET) $(OBJS)
	rm -f *.o 2> /dev/null
	rm -f $(TARGET) 2> /dev/null



