import os
import re

from pybind11.setup_helpers import ParallelCompile, Pybind11Extension, build_ext, naive_recompile
from setuptools import setup

ParallelCompile(default=0, needs_recompile=naive_recompile).install()

_bug = Pybind11Extension(
    "pybindbug._bug",
    sources=[
        "src/wrap.cpp",
    ],
    undef_macros=[],
)


setup(
    version='0.0.1',
    ext_modules=[_bug],
    cmdclass={},
)
