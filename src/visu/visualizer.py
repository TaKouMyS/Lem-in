#!/usr/bin/python

import matplotlib.pyplot as plt
import matplotlib.animation as matAni
import networkx as nx
import numpy as np

from parser import parser 
from class_farm import ant_farm
from class_ant import Ant


# Colors
bg_color = '#994C00'
line_color = '#282828'
node_color = '#282828'
start_color = '#FF33FF'
end_color = '#00CC00'
text_color = '#EEEEEE'

def make_squad(farm, s_b_n, pos):
    ant_list = []
    for nb in range(1, (int(farm.ants) + 1)):
        ant = Ant(nb)
        ant.set_node_path(farm)
        ant.set_location(pos, farm)
        ant.set_journey(pos, s_b_n, farm)
        ant.color = '#00CCCC'
        ant_list.append(ant)
    return (ant_list)


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


def draw_nodes(farm, start_color, end_color, node_color, node_size):
    for name in farm.nodes:
        if name == farm.start:
            draw_node(name, start_color, node_size * 2.5)
        elif name == farm.end:
            draw_node(name, end_color, node_size * 2.5)
        else:
            draw_node(name, node_color, node_size)

def draw_ant(position, color):
    ant = plt.plot([position[0]], [position[1]],
                   color=color, marker='.', markersize=20.0)
    return (ant)

def action(frame, farm, g, pos, fig, ant_squad):
    
    fig.clear()
    node_size = 500

    e = draw_nodes(farm, start_color, end_color, node_color, node_size)
    n = nx.draw_networkx_edges(g, pos, edge_color=line_color, style='dashdot', width=2.0)

    # draw all the ants:
    for ant in ant_squad:
        if frame < len(ant.journey):
            draw_ant(ant.journey[frame], ant.color)

    nx.draw_networkx_labels(
        g,
        pos,
        font_size=8,
        labels=dict([(farm.start, 'START'), (farm.end, 'END')]),
        font_family='sans-serif',
        font_color=text_color)
    
    # set the background color
    fig.set_facecolor(bg_color)

    # Hide axis
    plt.axis('off')
    

farm = parser()
print "nodes: "
print farm.nodes
print "Ants: "
print farm.ants
print "links: "
print farm.links
print "moves: "
print farm.moves
# for turn in farm.moves:
#     for move in turn:
#         print move[1]
g=nx.Graph()
g.add_nodes_from(farm.nodes)
g.add_edges_from(farm.links)
pos = nx.spring_layout(g)

# pos = farm.pos

steps_between_nodes = 15
ant_squad = make_squad(farm, steps_between_nodes, pos)

fig = plt.figure()

print "animate"
print type(farm.ants)
print farm.ants * steps_between_nodes

ani = matAni.FuncAnimation(
    fig,
    action,
    frames = farm.ants * steps_between_nodes,
    fargs = (
        farm,
        g,
        pos,
        fig,
        ant_squad
    ),
    interval=50,
    repeat=0,
    blit=0)


# nx.draw_networkx_edges(g, edge_color=line_color, width=2.0)
# nx.draw(g, with_labels=True)
plt.show()