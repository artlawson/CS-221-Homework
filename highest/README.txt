README

Initially, the debugger was not working for me because of an 
error in my makefile. After I made my makefile debuggable, things started to work a lot smoother.
I had to contuniually go through and fix the cases after the first two (0 and 1). The issues
came in the recursive calls of highest and the debugger was a pretty clear way to understand
 what was and was not working. The last thing I checked for was a one element array that is
 then one that is not the desired value. There were errors for all of the values after the 
 first two checks through the for loop and that required some slow checks through the recursive
calls and the solutions to my problems were not that hard to obtain.