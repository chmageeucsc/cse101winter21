#------------------------------------------------------------------------------
#  Makefile for CSE 101 Programming Assignment 7
#
#  make                     makes Arithmetic
#  make clean               removes all binaries
#  make memcheck            tests for memory leaks
#  make checkTest           test for ListTest
#------------------------------------------------------------------------------

CLIENT         = Arithmetic
ADT1           = BigInteger
ADT2           = List
TEST		   = ListTest
BI			   = BigIntegerTest
SOURCE         = $(CLIENT).c
OBJECT         = $(CLIENT).o
TEST_SOURCE    = $(TEST).c
TEST_OBJECT    = $(TEST).o
BI_SOURCE      = $(BI).c
BI_OBJECT      = $(BI).o
ADT1_SOURCE    = $(ADT1).c
ADT1_OBJECT    = $(ADT1).o
ADT1_HEADER    = $(ADT1).h
ADT2_SOURCE    = $(ADT2).c
ADT2_OBJECT    = $(ADT2).o
ADT2_HEADER    = $(ADT2).h
COMPILE        = gcc -c -std=c11 -Wall
LINK           = gcc -o
REMOVE         = rm -f
MEMCHECK       = valgrind --leak-check=full

$(CLIENT) : $(OBJECT) $(ADT1_OBJECT) $(ADT2_OBJECT)
	$(LINK) $(CLIENT) $(OBJECT) $(ADT1_OBJECT) $(ADT2_OBJECT)

$(OBJECT) : $(SOURCE) $(ADT1_HEADER) $(ADT2_HEADER)
	$(COMPILE) $(SOURCE)

$(ADT1_OBJECT) : $(ADT1_SOURCE) $(ADT1_HEADER)
	$(COMPILE) $(ADT1_SOURCE)

$(ADT2_OBJECT) : $(ADT2_SOURCE) $(ADT2_HEADER)
	$(COMPILE) $(ADT2_SOURCE)

$(TEST) : $(TEST_OBJECT) $(ADT2_OBJECT)
	$(LINK) $(TEST) $(TEST_OBJECT) $(ADT2_OBJECT)
	
$(TEST_OBJECT) : $(TEST_SOURCE) $(ADT2_OBJECT)
	$(COMPILE) $(TEST_SOURCE)
	
$(BI) : $(BI_OBJECT) $(ADT1_OBJECT) $(ADT2_OBJECT)
	$(LINK) $(BI) $(BI_OBJECT) $(ADT1_OBJECT) $(ADT2_OBJECT)
	
$(BI_OBJECT) : $(BI_SOURCE) $(ADT1_OBJECT) $(ADT2_OBJECT)
	$(COMPILE) $(BI_SOURCE)

clean :
	$(REMOVE) $(CLIENT) $(OBJECT) $(ADT1_OBJECT) $(ADT2_OBJECT)

memcheck : $(CLIENT)
	$(MEMCHECK) $(CLIENT) in3 myout3
	
checkTest : $(TEST)
	$(MEMCHECK) $(TEST)
	
checkBI : $(BI)
	$(MEMCHECK) -v $(BI)