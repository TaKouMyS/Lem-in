# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    read_and_parse.py                                  :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amamy <amamy@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/19 02:22:52 by amamy             #+#    #+#              #
#    Updated: 2019/09/23 01:01:14 by amamy            ###   ########.fr        #
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
        self.start  = None
        self.end    = None
        self.ants   = int(0)

    
def farm_parser():
    i = 0   
    input_list, moves = [], []
    ant_farm = farm()
    for line in sys.stdin:
        input_list.append((line.strip()).split())
        if line[0][0] == 'L':
            moves.append(line.strip().split())
        i += 1
    len_input_list = i
    i = 1
    ant_farm.ants = input_list[0][0]
    print ant_farm.ants
    while i < len_input_list and re.search(r"()-()", input_list[i][0]) is None:
        if len(input_list[i]) == 3:
            ant_farm.nodes.append(input_list[i][0])
            if i > 1 and re.search(r"^#{2}(start|end)", input_list[i - 1][0]):
                if re.search(r"^#{2}(start)", input_list[i - 1][0]):
                    ant_farm.start = input_list[i][0] 
                else:
                    ant_farm.end = input_list[i][0]
        i += 1
    while i < len_input_list and re.search(r"()-()", input_list[i][0]):
        ant_farm.links.append(input_list[i][0].split('-'))
        i += 1
    print input_list
    print moves
    return ant_farm

ant_farm = farm_parser()
g=nx.Graph()
g.add_nodes_from(ant_farm.nodes)
g.add_edges_from(ant_farm.links)
nx.draw(g, with_labels=True)
plt.show()
    
