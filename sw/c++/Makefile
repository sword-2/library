.DELETE_ON_ERROR:

CXX=g++ -std=c++17

#preprocessor debug options: -D to #DEFINE and -g to assist valgrind. 
debug=-D DEBUG -g

BGp=BGp.o
VC=VC.o

all: $(BGp) $(VC)

$(BGp): BGp.cpp Makefile
	$(CXX) -D SKIP  $(debug) BGp.cpp -o $@ 2>&1

$(VC): VC.cpp Makefile
	$(CXX) -D SKIP  $(debug) VC.cpp -o $@ 2>&1


.PHONY : clean
clean:
	if [ -f $(BGp) ]; then rm $(BGp); fi;
	if [ -f $(VC) ]; then rm $(VC); fi;
