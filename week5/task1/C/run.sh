#!/bin/bash

# Запускаем программу с переданным аргументом
./bin/main.p $1

rm -f result_file.txt
rm -f huge_file.txt

