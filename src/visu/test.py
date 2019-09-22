import matplotlib.pyplot as plt
import networkx as nx
import sys
import re
import subprocess as proc

class farm:
    """ This class represent the content of the farm."""

    def __init__(self):
        self.links  = []
        self.nodes  = []
        self.start  = None
        self.end    = None
        self.ants   = int(0)

ant_farm = farm()
input_list, moves = [], []
i = 0   
for line in sys.stdin:
    input_list.append((line.strip()).split())
    if line[0][0] == 'L':
        moves.append(line.strip().split())
    i += 1
print input_list
print "------------------"
len_input_list = i
i = 0
ant_farm.ants = input_list[0][0]
print ant_farm.ants
gen = (line for line in input_list if (line[0][0] == 'L'))
# for line in gen:
#     print line
#     print "line"
#     i += 1

print moves