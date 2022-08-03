# pybind11 / py312 bug

This is a producing case of a bug which compiles with pybind11 on both py310
and py312 (and py311).

It will import correctly on py310, py311a7, and the 3.11 dev branch, but not
with py312 (CPython main branch).  The import failure is:

```

In [1]: import pybindbug._bug
---------------------------------------------------------------------------
AttributeError                            Traceback (most recent call last)
AttributeError: 'pybind11_static_property' object attribute '__doc__' is read-only

The above exception was the direct cause of the following exception:

ImportError                               Traceback (most recent call last)
Cell In [1], line 1
----> 1 import pybindbug._bug

File ~/source/p/tacaswell/pybind11bug/lib/pybindbug/__init__.py:1
----> 1 from . import _bug

ImportError: initialization failed

```

originally found this with contourpy.
