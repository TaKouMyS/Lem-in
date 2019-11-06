import numpy as np
import sys

def get_start(farm, line):
	farm.start = line.split(" ")[0]

def get_end(farm, line):
	farm.end = line.split(" ")[0]

def get_room(farm, line):
	line_split = line.strip().split(" ")
	room_name = line_split[0]
	pos_x = line_split[1]
	pos_y = line_split[2]
	farm.nodes.append(room_name)
	farm.pos[room_name] = (int(pos_x), int(pos_y))
	for node in farm.nodes:
		farm.pos[node] = np.array([int(pos_y), int(pos_x)])
	
def get_link(farm, line):
	line_split = line.strip().split("-")
	farm.links.append(line_split)

def get_move(farm, line):
	final = []
	line_split = line.strip().split(" ")
	for move in line_split:
		tmp = move.split("-")
		ant = tmp[0].lstrip('L')
		room = tmp[1]
		pre_final = []
		pre_final.append(ant)
		pre_final.append(room)
		final.append(pre_final)
	farm.moves.append(final)
