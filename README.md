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

Using the [makefile](http://ioccc.org/1995/Makefile) provided by
IOCCC organizers, the program can be built on a typical Linux
system using GCC by issuing the following command:

    $ make makarios


Running tests
-------------

No automated tests exist for the program at the moment, but during
refactoring, I used the following commands to see if I didn't mess
up anything badly:

    $ gcc -Wall -ansi -O -o ./makarios makarios.c \
      && ./makarios >/tmp/actual.txt \
      && diff -u first_150_numbers.txt /tmp/actual.txt \
      && echo OK


License
-------

The refactored code is distributed under the terms of the
WTFPL license document. Read the file named LICENSE.md for the
details.
