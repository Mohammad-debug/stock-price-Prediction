compile:
	g++ -o Stocks main.cpp

run: compile
	@TEST_PATH="./tests/test$(test)/input" ; \
	./Stocks $(task) < $$TEST_PATH

test: compile
	@TEST_INPUT_PATH="./tests/test$(test)/input" ; \
	TEST_OUTPUT_PATH="./tests/test$(test)/output" ; \
	ACTUAL=$$(./Stocks $(task) < $$TEST_INPUT_PATH) ; \
	EXPECTED=$$(cat $$TEST_OUTPUT_PATH) ; \
	python3 ./tests/compare.py "$$ACTUAL" "$$EXPECTED" $(task)

testAll: compile
	@echo Running tests.
	$(MAKE) test test=3 task=6a
	$(MAKE) test test=4 task=6a
	$(MAKE) test test=5 task=6a

	$(MAKE) test test=3 task=6b
	$(MAKE) test test=4 task=6b
	$(MAKE) test test=5 task=6b
