
[usleep test - Mac version]

(c) Jacek Pierzchlewski, 2017  jacek@pierzchlewski.com
    license: BSD-2-Clause.

================================================================================
I. INTRO
Files in the directory test how precise is c/c++ function usleep(), which is
suppose to put computer to sleep for a certain amount of microseconds.

read more on: www.orange-engineer.com

--------------------------------------------------------------------------------
II. LIST OF FILES

    1. us_test.cpp:     Measure the time of 1 million usleep(1) calls.

    2. us_test.c:       Measure the time of 1 million usleep(1) calls
                        (c version).

    3. us10_test.cpp:   Measure the time of 1 million usleep(10) calls.

    4. usx_test.cpp:    Measure the time of usleep() calls with a set of
                        arguments in range  1us - 1s.

    5. usx_test_py.cpp:          Python interface to usx_test.cpp

    6. compile_usx_test_py.py:   Python script which compiles usx_test_py.cpp

    7. run_usleep_test.py:       Run tests on usleep() and plot the results.
                                 The results are stored in usleep_test.dat

    8. view_usleep_test.py:      View test results stored in uslee_test.dat



--------------------------------------------------------------------------------
III. MANUAL

    1. To measure the time of 1 million usleep(1) calls

       a) compile us_test.cpp:
        $ make us_test

       b) run us_test:
        $ ./us_test


    2. To measure the time of 1 million usleep(10) calls

       a) compile us10_test.cpp:
        $ make us10_test

       b) run us10_test:
        $ ./us10_test


    3. To measure the time of usleep calls with a set of arguments
       in range  1us - 1s:

       a) compile usx_test.cpp:
        $ make usx_test

       b) run usx_test:
        $ ./usx_test


    4. To test usleep calls for a set of arguments and plot the results:

       a) compile Python module:
        $ make python_module

       b) run the tests on usleep:
        $ python3 run_usleep_test.py

       c) view the results:
        $ python3 view_usleep_test.py

