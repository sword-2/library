#!/data/data/com.termux/files/usr/bin/bash

for i in {01..22}; do
  #-v option assigns output to variable
  #arithmetic expansion as some digits interpreted as octal - 08/09 error.
  printf -v Frmt1 "%02d" $((10#$i)) #\n
  #echo $Frmt1
  cp 00-orig "$Frmt1"
  #mv "$Frmt1" "0$Frmt1" #change to triple digits for Psalms
done
