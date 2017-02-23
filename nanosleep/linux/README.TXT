
[nanosleep test - Linux version]

(c) Jacek Pierzchlewski, 2017  jacek@pierzchlewski.com
    license: BSD-2-Clause.

================================================================================
I. INTRO
Files in the directory test how precise is c/c++ function nanosleep(), which is
suppose to put computer to sleep for a certain amount of nanoseconds.

read more on: www.orange-engineer.com


--------------------------------------------------------------------------------
II. LIST OF FILES

    1. nanox_test_py.cpp:           Python module which tests nanosleep() function

    2. compile_nanox_test_py.py:    Python script which compiles nanox_test_py.cpp

    3. run_nanosleep_test.py:       Run tests on nanosleep() and plot the results.
                                    The results are stored in nanosleep_test.dat

    4. view_nanosleep_test.py:      View test results stored in nanosleep_test.dat


--------------------------------------------------------------------------------
III. MANUAL

    1. To test nanosleep calls for a set of arguments and plot the results:

       a) compile Python module:
        $ make python_module

       b) run the tests on nanosleep:
        $ python3 run_nanosleep_test.py

       c) view the results:
        $ python3 view_nanosleep_test.py
