# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    read_and_parse.py                                  :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amamy <amamy@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/19 02:22:52 by amamy             #+#    #+#              #
#    Updated: 2019/09/23 04:09:22 by amamy            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import matplotlib.pyplot as plt
import networkx as nx
import sys
import re


class farm:
    """ This class represent the content of the farm."""

    def __init__(self):
        self.links  = []
        self.nodes  = []
        self.moves  = []
        self.start  = None
        self.end    = None
        self.ants   = int(0)

    
def farm_parser():
    i = 0   
    input_list = []
    ant_farm = farm()
    for line in sys.stdin:
        input_list.append((line.strip()).split())
        if line[0][0] == 'L':
            ant_farm.moves.append(line.strip().split())
        i += 1
    len_input_list = i
    i = 1
    ant_farm.ants = input_list[0][0]
    flag = None
    gen = (line for line in input_list if (line and re.search(r"()-()", line[0][0]) is None))
    for line in gen:
        if re.search(r"^#{2}(start|end)", line[0]):
            if line and re.search(r"^#{2}(start)", line[0]):
                flag = "s"
            elif line and re.search(r"^#{2}(end)", line[0]):
                 flag = "e"
        elif len(line) == 3 and line[0][0] != 'L':
            ant_farm.nodes.append(line[0])
            if flag == 's' :
                ant_farm.start = line[0]
            elif flag == 'e' :
                ant_farm.end = line[0]
            flag = None
    gen = (line for line in input_list if (line and re.search(r"()-()", line[0]) and line[0][0] != 'L'))
    for line in gen:
        ant_farm.links.append(line[0].split('-'))
    return ant_farm

ant_farm = farm_parser()
print "Ants: "
print ant_farm.ants
print "links: "
print ant_farm.links
print "moves: "
print ant_farm.moves
g=nx.Graph()
g.add_nodes_from(ant_farm.nodes)
g.add_edges_from(ant_farm.links)
nx.draw(g, with_labels=True)
plt.show()
    

