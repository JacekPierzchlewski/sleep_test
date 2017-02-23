# Compile Python module which tests nanosleep()
python_module: compile_nanox_test_py.py nanox_test_py.cpp
	python3 compile_nanox_test_py.py build_ext --inplace

# Clean up (without .dat file with results of the test)
clean:
	@rm -f *.so
	@rm -fR build

# Clean up (without .dat file with results of the test)
mrproper:
	@make clean
	@rm -f *.dat
