#
# compile_usx_test_py.py [version 1.0]
#
# This is script which compiles Python interface to
# test of usleep calls (usx_test_py.cpp).
#
# read more on: www.orange-engineer.com
#
# (c) Jacek Pierzchlewski, 2017  jacek@pierzchlewski.com
# license: BSD-2-Clause.
#
from distutils.core import setup, Extension

usx_test = Extension('usxTest', sources=['usx_test_py.cpp'])
setup(name='usx_test', version='1.0',
      description='Python interface to usleep() test',
      ext_modules=[usx_test])
