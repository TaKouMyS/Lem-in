# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    read_and_parse.py                                  :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amamy <amamy@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/19 02:22:52 by amamy             #+#    #+#              #
#    Updated: 2019/09/19 22:59:11 by amamy            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import matplotlib.pyplot as plt
import networkx as nx
import sys
import re


class farm:
    """ This class represent the content of the farm."""

    def __init__(self):
        self.links = []
        self.nodes = []
        self.start = None
        self.end  = None
        

    
def parser():
    input_list=[]
    i = 0   
    ant_farm = farm()
    for line in sys.stdin:
        input_list.append((line.strip()).split())
        i += 1
    len_input_list = i
    i = 0
    while i < len_input_list and len(input_list[i]) == 3:
        ant_farm.nodes.append(input_list[i][0])
        i += 1
    while i < len_input_list and re.search(r"()-()", input_list[i][0]):
        ant_farm.links.append(input_list[i][0].split('-'))
        print i
        i += 1
    return ant_farm

ant_farm = parser()
g=nx.Graph()
g.add_nodes_from(ant_farm.nodes)
g.add_edges_from(ant_farm.links)
nx.draw(g, with_labels=True)
plt.show()
    

