#!/usr/bin/python

import matplotlib.pyplot as plt
import networkx as nx

from parser import parser 
from animate import animate


# Colors
colors = {
	"bg" : '#000000',
	"line" : '#282828',
	 "used" : ['#b61515', '#B6B615', '#66B615', '#15B615', '#15B666',
			  '#15B6B6', '#1515B6', '#6615B6', '#B615B6', '#B61566'],
	"node" : '#282828',
	"start" : '#282828',
	"end" : '#282828',
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
# print "len(moves[0][1][3]) : "
# print data['farm'].moves[0][0][1]
# print "moves :"
# for turn in data['farm'].moves:
#     print turn
# print "ants :\n\n"
# print data['farm'].ants
# print "links :"
# print data['farm'].links

ani = animate(data, colors)
plt.show()

