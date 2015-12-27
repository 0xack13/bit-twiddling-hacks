# BitOperations
[![Travis build status][badge-travis]][travis]
[![Coveralls coverage][badge-coveralls]][coveralls]

Several bit operations and manipulations, also known as 'bit hacks'.  

*Please note that the coverage results do not include the function macros, although those are tested in the unit tests.*

## Documentation
Documentation can be found in the [documentation page](http:http://vidavidorra.github.io/BitOperations/html/index.html), and for the function macros and functions on the [BitOperations.h documentation page](http:http://vidavidorra.github.io/BitOperations/html/BitOperations_8h.html).  
For the functions that are based on Sean Eron Andersons [Bit Twiddling Hacks](https://graphics.stanford.edu/~seander/bithacks.html) the arithmetics are explained on his Bit Twiddling Hacks page or also, in markdown format, at gibjose's [markdown version](https://github.com/gibsjose/BitHacks/blob/master/BitHacks.md) of that page.

## Unit test
The unit tests use [greatest](https://github.com/silentbicycle/greatest/) by Scott Vokes. Greatest is licensed under a [custom license](https://github.com/silentbicycle/greatest/blob/master/LICENSE).  

All the functions and function macros are tested by the unit tests, of which the log can be found in every [travis build](https://travis-ci.org/vidavidorra/BitOperations#L169-L243).


[badge-travis]:             https://travis-ci.org/vidavidorra/BitOperations.svg
[travis]:                   https://travis-ci.org/vidavidorra/BitOperations
[badge-coveralls]:          https://coveralls.io/repos/vidavidorra/BitOperations/badge.svg?branch=master&service=github
[coveralls]:                https://coveralls.io/github/vidavidorra/BitOperations?branch=master