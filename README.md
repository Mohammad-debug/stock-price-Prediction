# COT5405 Algorithms Programming Project

## Anatomy of the project

```
.
├── README.md
├── Stocks
├── expermintal           // python code for generating testcases
│   └── random_test_generator.py
├── main.cpp
├── makefile
├── tasks                 // Implementation for each task
│   ├── task1.hpp
│   ├── task2.hpp
│   ├── task3a.hpp
│   ├── task3b.hpp
│   ├── task4.hpp
│   ├── task5.hpp
│   ├── task6a.hpp
│   ├── task6b.hpp
│   ├── task7.hpp
│   └── task8.hpp
│    task9b.hpp
├── tests                 // Testcases
└── utils                 // Helper functions used throughout the tasks
    ├── answer.hpp
    ├── helper.hpp
    └── input.hpp
```

## How to run
Comile the code using the following make recipe.

```
make compile
```

This produces an executable called `Stocks`.

Run the code as follows:
```
./Stocks <task-id>
```

## How to run testcases

Testcases require an installation of python 3.

Run tests as follows:
```
make test test=<test-number> task=<task-id>
```

Failing testcases will print a diff of actual vs expected.


## How to run testcase generator

This also requires an install of python 3

Generate using the python script and run the program
```
python3 './experimental/random_test_generator' m n [k]
./Stocks < input.txt > output.txt
```