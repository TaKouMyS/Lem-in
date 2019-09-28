# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    read_and_parse.py                                  :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amamy <amamy@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/19 02:22:52 by amamy             #+#    #+#              #
#    Updated: 2019/09/28 20:30:15 by amamy            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import matplotlib.pyplot as plt
import networkx as nx
import sys
import re

# Colors
bg_color = '#994C00'
line_color = '#282828'
node_color = '#282828'
start_color = '#FF33FF'
end_color = '#00CC00'
text_color = '#EEEEEE'

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
            print line
            ant_farm.nodes.append(line[0])
            if flag == 's' :
                ant_farm.start = line[0]
            elif flag == 'e' :
                ant_farm.end = line[0]
            flag = None
    gen = (line for line in input_list if (line and re.search(r"()-()", line[0]) and line[0][0] != 'L'))
    for line in gen:
        ant_farm.links.append(line[0].split('-'))
    return (ant_farm)

def draw_node(name, color, size):
    node_list = []
    node_list.append(name)
    node = nx.draw_networkx_nodes(
    g,
    pos,
    nodelist=node_list,
    node_color=color,
    node_size=size)
    # node.set_edgecolor(line_color) #to set edge color ? 
    return (node)


def draw_nodes(ant_farm, start_color, end_color, node_color, node_size):
    for name in ant_farm.nodes:
        if name == ant_farm.start:
            draw_node(name, start_color, node_size * 2.5)
        elif name == ant_farm.end:
            draw_node(name, end_color, node_size * 2.5)
        else:
            draw_node(name, node_color, node_size)

def render():
    node_size = 500
    nx.draw_networkx_edges(g, pos, edge_color=line_color, width=2.0)
    draw_nodes(ant_farm, start_color, end_color, node_color, node_size)
    # set the background color
    nx.draw_networkx_labels(g,
                            pos,
                            font_size=8,
                            labels=dict([(ant_farm.start,
                                        'START'),
                                        (ant_farm.end,
                                        'END')]),
                            font_family='sans-serif',
                            font_color=text_color)
    fig.set_facecolor(bg_color)

    plt.axis('off')


ant_farm = farm_parser()
print "nodes: "
print ant_farm.nodes
print "Ants: "
print ant_farm.ants
print "links: "
print ant_farm.links
print "moves: "
print ant_farm.moves
g=nx.Graph()
g.add_nodes_from(ant_farm.nodes)
g.add_edges_from(ant_farm.links)
pos = nx.spring_layout(g)
fig = plt.figure()
render()
# nx.draw_networkx_edges(g, edge_color=line_color, width=2.0)
# nx.draw(g, with_labels=True)
plt.show()
    

