all: compile

compile : Stocks.cpp
	g++ -o Stocks Stocks.cpp 
	


clean:
	rm -rvf *.o
	