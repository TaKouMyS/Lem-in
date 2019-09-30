import matplotlib.pyplot as plt
import matplotlib.animation as matAni
import networkx as nx
import numpy as np

from read_and_parse import farm_parser 
from farm import farm
from ant import Ant


# Colors
bg_color = '#994C00'
line_color = '#282828'
node_color = '#282828'
start_color = '#FF33FF'
end_color = '#00CC00'
text_color = '#EEEEEE'

def make_squad(ant_farm, s_b_n, pos):
    ant_list = []
    for nb in range(1, (int(ant_farm.ants) + 1)):
        ant = Ant(nb)
        ant.set_node_path(ant_farm)
        ant.set_location(pos, ant_farm)
        ant.set_journey(pos, s_b_n, ant_farm)
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


def draw_nodes(ant_farm, start_color, end_color, node_color, node_size):
    for name in ant_farm.nodes:
        if name == ant_farm.start:
            draw_node(name, start_color, node_size * 2.5)
        elif name == ant_farm.end:
            draw_node(name, end_color, node_size * 2.5)
        else:
            draw_node(name, node_color, node_size)

def draw_ant(position, color):
    ant = plt.plot([position[0]], [position[1]],
                   color=color, marker='.', markersize=20.0)
    return (ant)

def action(frame, ant_farm, g, pos, fig, ant_squad):
    
    fig.clear()
    node_size = 500

    e = draw_nodes(ant_farm, start_color, end_color, node_color, node_size)
    n = nx.draw_networkx_edges(g, pos, edge_color=line_color, style='dashdot', width=2.0)

    # draw all the ants:
    # print "frame : "
    # print frame
    for ant in ant_squad:
        # print "len(ant.journey) : "
        # print len(ant.journey)
        if frame < len(ant.journey):
            print ant.journey[frame]
            draw_ant(ant.journey[frame], ant.color)

    nx.draw_networkx_labels(g,
                            pos,
                            font_size=8,
                            labels=dict([(ant_farm.start,
                                        'START'),
                                        (ant_farm.end,
                                        'END')]),
                            font_family='sans-serif',
                            font_color=text_color)
    
    # set the background color
    fig.set_facecolor(bg_color)

    # Hide axis
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
# for turn in ant_farm.moves:
#     for move in turn:
#         print move[1]
g=nx.Graph()
g.add_nodes_from(ant_farm.nodes)
g.add_edges_from(ant_farm.links)
pos = nx.spring_layout(g)

# pos = ant_farm.pos

steps_between_nodes = 10
ant_squad = make_squad(ant_farm, steps_between_nodes, pos)

fig = plt.figure()

print "animate"
print type(ant_farm.ants)
print ant_farm.ants * steps_between_nodes

ani = matAni.FuncAnimation(
    fig,
    action,
    frames = ant_farm.ants * steps_between_nodes,
    fargs = (
        ant_farm,
        g,
        pos,
        fig,
        ant_squad
    ),
    interval=200,
    blit=0)

# nx.draw_networkx_edges(g, edge_color=line_color, width=2.0)
# nx.draw(g, with_labels=True)
plt.show()