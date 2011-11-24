Palindromic Primes
==================

Introduction
------------

I've found this piece of code at the website of the [International
Obfuscated C Code Contest](http://ioccc.org). It's a C file named
[makarios.c](http://ioccc.org/1995/makarios.c), and it's only 105
bytes:

    main(n,i,a,m){while(i=++n)
    for(a=0;a<i?a=a*8+i%8,i/=8,m=a==i|a/8==i,1:(n-++m||printf("%o\n",n))&&n%m;);}

"Good code documents itself", many say, but can an IOCCC winner be
refactored to fulfill that statement?


Buld tips
---------

The program can be built on a typical Linux system using GCC by
issuing the following command:

    $ make makarios


Running tests
-------------

Use the following command to run tests:

    $ make check >/dev/null && echo "OK"


License
-------

The refactored code is distributed under the terms of the
WTFPL license document. Read the file named LICENSE.md for the
details.
