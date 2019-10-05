#!/usr/bin/python

import matplotlib.pyplot as plt
import networkx as nx

from parser import parser 
from animate import animate


# Colors
colors = {
    "bg" : '#994C00',
    "line" : '#282828',
    "node" : '#282828',
    "start" : '#FF33FF',
    "end" : '#00CC00',
    "text" : '#EEEEEE',
    "ant" : '#00CCCC'
}

def create_data():
    data = {}
    data['farm'] = parser()
    data['g'] = make_graph(data['farm'])
    data['pos'] = nx.spring_layout(data['g'])
    return (data)

def make_graph(farm):
    g=nx.Graph()
    g.add_nodes_from(farm.nodes)
    g.add_edges_from(farm.links)
    return (g)

data = create_data()
ani = animate(data, colors)
plt.show()

