#########################################################################
# File Name: make.sh
# Author: qyh
# mail: xxx@126.com
# Created Time: Thu 21 Jun 2018 02:43:42 AM UTC
#########################################################################
#!/bin/bash
gcc -fPIC -shared -o cutil.so cutil.c -I /usr/local/include -l lua
