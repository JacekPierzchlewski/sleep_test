#
# This is makefile for ' sleep_test/usleep '.
#
# Read more on www.orange-engineer.com
#
# (c) Jacek Pierzchlewski, 2017  jacek@pierzchlewski.com
# license: BSD-2-Clause.

# Compile usleep(1) tests (c++ version)
us_test: us_test.cpp
	g++ us_test.cpp -o us_test

# Compile usleep(1) tests (c version)
us_testc: us_test.c
	gcc us_test.c -o us_testc

# Compile usleep(10) tests (c++ version)
us10_test: us10_test.cpp
	g++ us10_test.cpp -o us10_test

# Compile test of usleep calls with various arguments
usx_test: usx_test.cpp
	g++ usx_test.cpp -o usx_test

# Compile Python interface to usx_test.cpp
python_module: compile_usx_test_py.py usx_test_py.cpp
	python3 compile_usx_test_py.py build_ext --inplace

# Clean up (without .dat file with results of the test)
clean:
	@rm -f us_test
	@rm -f us10_test
	@rm -f usx_test
	@rm -f us_testc
	@rm -f *.so
	@rm -fR build

# Clean up (without .dat file with results of the test)
mrproper:
	@make clean
	@rm -f *.dat

