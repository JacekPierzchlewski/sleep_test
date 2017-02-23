#
# compile_nanox_test_py.py [version 1.0]
#
# This script compiles Python module which tests nanosleep function.
#
# read more on: www.orange-engineer.com
#
# (c) Jacek Pierzchlewski, 2017  jacek@pierzchlewski.com
# license: BSD-2-Clause.
#
from distutils.core import setup, Extension

nanox_test = Extension('nanoxTest', sources=['nanox_test_py.cpp'])
setup(name='nanox_test', version='1.0',
      description='Python interface to nanosleep() test',
      ext_modules=[nanox_test])
