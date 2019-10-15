##!/usr/bin/bash
map="$1"
args="${@:2}"
if [ "$map" = "" ];
then
	python3 src/visu/visualizer.py <<<'' ;
else 
	./lem-in < $map 2>/dev/null | python3 src/visu/visualizer.py $args;
fi;