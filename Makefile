CXX := g++
CXXFLAGS := -g -Wall --std=c++11
VALGRIND := valgrind --tool=memcheck --leak-check=yes

all: llrec-test stack-test functor-demo heap-test

#-----------------------------------------------------
# ADD target(s) to build your llrec-test executable
#-----------------------------------------------------

llrec-test:llrec-test.cpp llrec.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

stack-test: stack_test.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

functor-demo: functor_demo.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

heap-test: heap_test.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

clean:
	rm -f *.o rh llrec-test stack-test functor-demo heap-test *~

.PHONY: clean 