#!/bin/bash

say -v Milena "Да начнутся голодные игры"

purple=$(printf "👮")
blue=$(printf "👺")

sed "s|X|$purple|g" |
sed "s|O|$blue|g" |
sed "/^0.. /s|x|$purple|g" |
sed "/^0.. /s|o|$blue|g"

say -v Milena "Голодные игры окончены"
