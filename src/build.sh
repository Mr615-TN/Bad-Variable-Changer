#!/bin/bash

set -xe

gcc -Wextra -Wall -g -o main main.c lexer.c token.c
