import matplotlib.pyplot as plt
import matplotlib.animation as matAni
import networkx as nx

from class_ant import Ant
from set_links_colors import set_links_colors
from draw import draw_node, draw_nodes, draw_ant

def make_squad(data, colors, s_b_n):
	ant_list = []
	for nb in range(1, (int(data['farm'].ants) + 1)):
		ant = Ant(nb)
		ant.set_node_path(data['farm'])
		ant.set_location(data['pos'], data['farm'])
		ant.set_journey(data['pos'], s_b_n, data['farm'])
		ant.color = colors['ant']
		ant_list.append(ant)
	return (ant_list)

def action(frame, data, fig, ant_squad, colors):
	
	fig.clear()
	node_size = 500

	nx.draw_networkx_edges(data['g'], data['pos'], edge_color=colors['line'], width=2.0)
	for i, path in enumerate(data['farm'].used_links):
		nx.draw_networkx_edges(data['g'], data['pos'], edgelist = path, edge_color=colors['used'][i], width=2.0)
	draw_nodes(data, colors, node_size)

	# draw all the ants:
	for ant in ant_squad:
		if frame < len(ant.journey):
			draw_ant(ant.journey[frame], ant.color)

	nx.draw_networkx_labels(
		data['g'],
		data['pos'],
		font_size=8,
		# labels=dict([(data['farm'].start, 'START'), (data['farm'].end, 'END')]),
		font_family='sans-serif',
		font_color=colors['text'])
	
	# set the background color
	fig.set_facecolor(colors['bg'])

	#   Hide axis
	plt.axis('off')
	
def animate(data, colors):
	# pos = farm.pos
	steps_between_nodes = 15
	ant_squad = make_squad(data, colors, steps_between_nodes)
	set_links_colors(data['farm'], ant_squad)
	fig = plt.figure(figsize=(12, 8))
	ani = matAni.FuncAnimation(
		fig,
		action,
		frames = data['farm'].ants * steps_between_nodes,
		fargs = (data, fig, ant_squad, colors),
		interval=1,
		repeat=0,
		blit=0)
	return (ani)
	