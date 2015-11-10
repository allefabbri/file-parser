# file_parser
A very simple _Boost_ based library which provides a function to parse a commented parameter file and returns a ``std::vector`` of ``std::vector`` of the form ``{ key, value1, value2, ... }``

#### Installation
There is a ``makefile`` which builds the source ``example.cpp`` and the related dependencies. To use it in your program just add the header ``file_parser.h`` and the lib source ``file_parser.cpp`` to your project folder and adapt your toolchain.

#### Sample input
```
# These
! are
/ comments!

###

 field1 = 12.345        # These

	FiElD3 = text            ! are

    FIELD2 = 43     / comments

		fIeLd4 , more text      # too!!!
```

#### Sample output
The function return nested vectors of the form
```
field1 12.345
field3   text
field2     43
field4   more   text
```
