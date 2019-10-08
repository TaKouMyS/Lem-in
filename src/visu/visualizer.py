#!/usr/bin/python

import matplotlib.pyplot as plt
import networkx as nx
import sys

from parser import parser 
from animate import animate
from create_settings import create_settings, check_args

def check_is_big_map(args):
	if check_args(args, "-f") == False:
		if len(data['farm'].nodes) > 1000:
			print "The map you are trying to run is really big!\n It will take lot of time to launch it, it is not going to be responsive well and, on top of that, you probably will not have a good view\n run -f to force"
			quit()

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
check_is_big_map(args)
ani = animate(data, settings)
plt.show()
