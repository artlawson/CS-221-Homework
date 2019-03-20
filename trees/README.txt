README.txt

Initially, I worked on doing all of the functions recursively (except for create, of course). 
This lead to a lot of headache for the last two so I work through getting them done with loops.
The while and for loops seemed to be the simplest way for me to get through path_to and node_at 
respectively. 

For node_at, the consecutive "if" checks seemed to be the cleanest way to 
communicate that one is for left, one is for right, and the other is for neither.

In path_to, I tried to work recursively and return the string with each call of the function,
but I faced constant errors that lead for to reapproach it with an empty string. and adding 
to it as the path is mapped out. 

Destroy_tree was pretty simple to go through recursively,
the thought was to go through the whole tree, then when you get to the bottom, go back through
and delete until you get back to the root (and delete that too!). 