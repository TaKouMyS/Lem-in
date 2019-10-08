#!/usr/bin/python

import matplotlib.pyplot as plt
import networkx as nx
import sys

from parser import parser 
from animate import animate
from create_settings import create_settings


# Colors
draw_data = {
	"bg" : '#000000',
	"line" : '#282828',
	 "used" : ['#b61515', '#B6B615', '#66B615', '#15B615', '#15B666',
			  '#15B6B6', '#1515B6', '#6615B6', '#B615B6', '#B61566'],
	"node" : '#282828',
	"start" : '#282828',
	"end" : '#282828',
	"text" : '#EEEEEE',
	"ant" : '#00CCCC',
	"steps_between_nodes" : 15,
	"node_size" : 500
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

args = sys.argv
data = create_data()
settings = create_settings(args, data['farm'])
ani = animate(data, settings)
plt.show()
