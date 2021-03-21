#!/bin/bash

AllFiles="effFiles.txt"

if [[ "$#" -lt 1 ]]; 
then
    echo " "
    echo "====>>  no argument is passed. Pass either histfiles.txt"
    echo " "
    exit
fi

if [[ "$#" -lt 2 ]];
then
HistFiles=$1
fi

if [[ "$#" -eq 2 ]];
then
    AllFiles=$1
    HistFiles=$2
fi

root -l -b -q "plot_efficiency.C(\"$AllFiles\",\"$HistFiles\")"  
