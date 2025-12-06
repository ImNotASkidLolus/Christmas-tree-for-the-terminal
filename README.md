# Christmass Tree in the Terminal
Christmass tree in C that outputs in your terminal
<br>
<img src="./assets/images/tree.png" alt="Tree image" width="240" height="240"/>

## How to make it work?
```
gcc /path/to/this/file.c -o tree
./tree
```
## If you want to change the colors
change these lines in the code by comenting the first one and uncommenting the other:
```C
const char* colors[] ={"\e[1;33m", "\e[0;34m", "\e[0;35m", "\e[0;36m","\e[0;31m", "\e[0;37m", "\e[0;32m"};
//const char* colors[] ={"\e[1;32m", "\e[0;31m", "\e[0;37m"};
```
