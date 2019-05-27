
BASE_PATH = ../

INC  = -I./ -I../ 
FLAG = -g -Wno-deprecated -fPIC -std=c++0x

SRC_COMM = $(wildcard ./*.cpp )

OBJECT = $(SRC_COMM:.cpp=.o)

.cpp.o:
	$(CXX) $(FLAG) $(INC) -c -o $@ $<

EXTLIB = $(BASE_PATH)lib/json_lib.a

all:$(EXTLIB)

$(EXTLIB):$(OBJECT)
	$(AR) rcs $@ $^

clean:
	rm $(EXTLIB) $(OBJECT)  







