def convert_path_to_links(paths):
	links = []
	all_links = []
	for path in paths:
		for node, next in zip(path, path[1:]):
			link = [node, next]
			links.append(link)
		all_links.append(links)
		links = []
	return (all_links)

def get_ants(farm):
	ants = []
	for move in farm.moves[0]:
		ants.append(move[0])
	return (ants)
	
def get_paths(farm, ant_squad, ants):
	paths = []
	for ant in ants:
		paths.append(ant_squad[int(ant) - 1].node_path)
	return (paths)

def remove_links_in_original_list(farm):
	for path in farm.used_links:
		for link in path:
			if link in farm.links:
				farm.links.remove(link)
			link = list(reversed(link))
			if link in farm.links:
				farm.links.remove(link)

def remove_nodes_in_original_list(farm):
	for path in farm.used_nodes:
		for node in path:
			if node in farm.nodes:
				farm.nodes.remove(node)
			

def get_paths_of_nodes(paths):
	used_nodes = []
	for path in paths:
		used_nodes.append(path[1:-1])
	return (used_nodes)
	
		
def set_paths_colors(farm, ant_squad):
	nb_path = len(farm.moves[0])
	ants = get_ants(farm)
	paths = get_paths(farm, ant_squad, ants)
	farm.used_nodes = get_paths_of_nodes(paths)
	farm.used_links = convert_path_to_links(paths)
	remove_links_in_original_list(farm)
	remove_nodes_in_original_list(farm)
