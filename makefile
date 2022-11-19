compile:
	g++ -o Stocks main.cpp

run3:compile
	./Stocks $(task) < ./tests/test3/input

run4:compile
	./Stocks $(task) < ./tests/test4/input

test1: compile
	@ACTUAL=$$(./Stocks $(task) < ./tests/test1/input) ; \
	EXPECTED=$$(cat ./tests/test1/output) ; \
	python3 ./tests/compare.py "$$ACTUAL" "$$EXPECTED" $(task)

test2: compile
	@ACTUAL=$$(./Stocks $(task) < ./tests/test2/input) ; \
	EXPECTED=$$(cat ./tests/test2/output) ; \
	python3 ./tests/compare.py "$$ACTUAL" "$$EXPECTED" $(task)

test3: compile
	@ACTUAL=$$(./Stocks $(task) < ./tests/test3/input) ; \
	EXPECTED=$$(cat ./tests/test3/output) ; \
	python3 ./tests/compare.py "$$ACTUAL" "$$EXPECTED" $(task)

test4: compile
	@ACTUAL=$$(./Stocks $(task) < ./tests/test4/input) ; \
	EXPECTED=$$(cat ./tests/test4/output) ; \
	python3 ./tests/compare.py "$$ACTUAL" "$$EXPECTED" $(task)