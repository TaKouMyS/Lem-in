import matplotlib.pyplot as plt
import networkx as nx

def draw_node(data, name, color, size):
    node_list = []
    node_list.append(name)
    node = nx.draw_networkx_nodes(
    data['g'],
    data['pos'],
    nodelist=node_list,
    node_color=color,
    node_size=size)
    node.set_edgecolor('#000000')
    return (node)


def draw_nodes(data, settings, node_size):
    for name in data['farm'].nodes:
        if name == data['farm'].start:
            draw_node(data, name, settings["node_color"], settings['node_size'] * 2.5)
        elif name == data['farm'].end:
            draw_node(data, name, settings["node_color"], settings['node_size'] * 2.5)
        else:
            draw_node(data, name, settings["node_color"], settings['node_size'])

def draw_ant(position, color, settings):
    ant = plt.plot([position[0]], [position[1]],
                   color=color, marker='.', markersize=settings["markersize"])
    return (ant)