#name of exec
EXEC = calculator_exec

#compiler
CXX = g++

#compilr flags
CXXFLAGS = -std=c++11 -Wall

#sourcefiles
SRCS = main.cpp calculator.cpp

#obj files
OBJS = $(SRCS:.cpp=.o)

#to build everything
all: $(EXEC)

#rules to build
$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

#to clean
clean:
	rm -f $(OBJS) $(EXEC)