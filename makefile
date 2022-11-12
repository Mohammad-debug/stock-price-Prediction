all: compile

compile : Stocks.cpp
	gcc -o Stocks Stocks.cpp 
	


clean:
	rm -rvf *.o
	