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
    # node.set_edgecolor(line_color) #to set edge color ? 
    return (node)


def draw_nodes(data, colors, node_size):
    for name in data['farm'].nodes:
        if name == data['farm'].start:
            draw_node(data, name, colors['start'], node_size * 2.5)
        elif name == data['farm'].end:
            draw_node(data, name, colors['end'], node_size * 2.5)
        else:
            draw_node(data, name, colors['node'], node_size)

def draw_ant(position, color):
    ant = plt.plot([position[0]], [position[1]],
                   color=color, marker='.', markersize=20.0)
    return (ant)