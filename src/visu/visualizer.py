#!/usr/bin/python

import matplotlib.pyplot as plt
import matplotlib.animation as matAni
import networkx as nx
import sys

from parser import parser
from usage import usage
from create_settings import create_settings, check_args
from class_ant import Ant
from draw import draw_node, draw_nodes, draw_ant
from events import *
from set_paths_colors import set_paths_colors

import warnings
warnings.filterwarnings("ignore", category=UserWarning)

def on_key(event):
	global settings
	global anim_running
	if (event.key == "p"):
		anim_running = play_pause(ani, anim_running)
	elif (event.key == "z"):
		up_node_size(settings)
	elif (event.key == "x"):
		down_node_size(settings)
	elif (event.key == "c"):
		up_ant_size(settings)
	elif (event.key == "v"):
		down_ant_size(settings)
	elif (event.key == "d"):
		switch_background_color(settings)
	elif (event.key == "f"):
		switch_node_color(settings)
	elif (event.key == "g"):
		switch_link_color(settings)
	elif (event.key == "h"):
		reset_settings(settings)

def make_squad(data, settings, s_b_n):
	ant_list = []
	for nb in range(1, (int(data['farm'].ants) + 1)):
		ant = Ant(nb)
		ant.set_node_path(data['farm'])
		ant.set_location(data['pos'], data['farm'])
		ant.set_journey(data['pos'], s_b_n, data['farm'])
		ant.color = settings['ant_colors_list'][nb % 11]
		ant_list.append(ant)
	return (ant_list)

def action(frame, data, fig, ant_squad, settings):
	
	fig.clear()

	id_key = fig.canvas.mpl_connect("key_press_event", on_key)

	nx.draw_networkx_edges(data['g'], data['pos'], edgelist = data['farm'].links, edge_color=settings['link_color'], width=2.0)
	for i, path in enumerate(data['farm'].used_links):
		nx.draw_networkx_edges(data['g'], data['pos'], edgelist = path, edge_color=settings['used'][i], width=2.0)
	draw_nodes(data, settings, settings['node_size'])
	
	# draw all the ants:
	for ant in ant_squad:
		if frame < len(ant.journey):
			draw_ant(ant.journey[frame], ant.color, settings)
	
	nx.draw_networkx_labels(
		data['g'],
		data['pos'],
		font_size = 8,
		labels = settings['labels'],
		font_family = 'sans-serif',
		font_color = settings['text_color'])
	
	# set the background color
	fig.set_facecolor(settings['background_color'])

	#   Hide axis
	plt.axis('off')

def check_is_big_map(args):
	if check_args(args, "-f") == False:
		if len(data['farm'].nodes) > 1000:
			print ("The map you are trying to run is really big!\n It will take lot of time to launch it, it is not going to be responsive well and, on top of that, you probably will not have a good view\n run -f to force")
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

try : 
	args = sys.argv
	data = create_data()
	settings = create_settings(args, data['farm'])
	check_is_big_map(args)
	ant_squad = make_squad(data, settings, settings['steps_between_nodes'])
	set_paths_colors(data['farm'], ant_squad)
	fig = plt.figure(figsize=(settings['window_size']))
	anim_running = True
	ani = matAni.FuncAnimation(
		fig,
		action,
		frames = data['farm'].ants * settings['steps_between_nodes'],
		fargs = (data, fig, ant_squad, settings),
		interval = settings['interval'],
		repeat = settings['repeat'],
		blit = 0)
	plt.show()
except : 
		usage()
		quit()