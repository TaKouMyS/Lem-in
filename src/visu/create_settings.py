#!/usr/bin/python
import sys
from usage import usage

def check_args(args, option):
	for arg in args:
		if arg == option:
			return True
	return False
	
def check_graph_size(farm, settings):
	if (len(farm.nodes)) < 100:
		settings["markersize"] = 20.0
		settings["node_size"] = 500
		settings["window_size"] = (12, 8)
	elif (len(farm.nodes)) < 1000:
		settings["markersize"] = 10.0
		settings["node_size"] = 300
		settings["window_size"] = (16, 12)
	elif (len(farm.nodes)) > 1000:
		settings["markersize"] = 5.0
		settings["node_size"] = 100
		settings["window_size"] = (18, 16)
	return settings

def basic_settings(settings, args, farm):
	if check_args(args, "-dark_theme") == True or check_args(args, "-dark_theme") == False:
		settings = check_graph_size(farm, settings)
		settings["steps_between_nodes"] = 15
		settings["repeat"] = False
		settings["link_color"] = "#101010"
		settings["used"] = ['#F7C59F', '#5A5a86', '#7CEA9C', '#55D6BE', '#2E5EAA', '#00C9FF', '#2A324B', '#F6C0D0', '#B8E1FF', '#808D8E', '#202030']
		settings["text_color"] = "#EEEEEE"
		settings["background_color"] = "#15202b"
		settings["node_color"] = "#282828"
		settings["ant_colors_list"] = ['#15B6B6', '#15B6B6', '#1515B6', '#B615B6', '#6615B6', '#15B6B6', '#15B6B6', '#1515B6', '#B615B6', '#6615B6', '#6615B6']
		settings["labels"] = None

	if check_args(args, "-blue_theme") == True:
		settings = check_graph_size(farm, settings)		
		settings["steps_between_nodes"] = 15
		settings["window_size"] = None
		settings["repeat"] = False
		settings["link_color"] = "#549EDD"
		settings["used"] = ['#F7C59F', '#5A5a86', '#7CEA9C', '#55D6BE', '#2E5EAA', '#00C9FF', '#2A324B', '#F6C0D0', '#B8E1FF', '#808D8E', '#202030']
		settings["text_color"] = "#094DB9"
		settings["background_color"] = "#013FC1"
		settings["node_color"] = "#AAD1ED"
		settings["ant_colors_list"] = ['#1515B6', '#1515B6', '#1515B6', '#1515B6', '#1515B6', '#1515B6', '#1515B6', '#1515B6', '#1515B6', '#1515B6', '#1515B6']
		settings["labels"] = None
	return settings

def color_background(settings, args):
	if check_args(args, "-red_background") == True:
		settings["background_color"] = "#B61515"
	elif check_args(args, "-orange_background") == True:
		settings["background_color"] = "#B66615"
	elif check_args(args, "-yellow_background") == True:
		settings["background_color"] = "#B6B615"
	elif check_args(args, "-green_background") == True:
		settings["background_color"] = "#15B615"
	elif check_args(args, "-blue_background") == True:
		settings["background_color"] = "#15B6B6"
	elif check_args(args, "-darkblue_background") == True:
		settings["background_color"] = "#1515B6"
	elif check_args(args, "-purple_background") == True:
		settings["background_color"] = "#B615B6"
	elif check_args(args, "-darkpurple_background") == True:
		settings["background_color"] = "#6615B6"
	elif check_args(args, "-pink_background") == True:
		settings["background_color"] = "#B61566"
	return settings

def color_nodes(settings, args):
	if check_args(args, "-red_nodes") == True:
		settings["node_color"] = "#B61515"
	elif check_args(args, "-orange_nodes") == True:
		settings["node_color"] = "#B66615"
	elif check_args(args, "-yellow_nodes") == True:
		settings["node_color"] = "#B6B615"
	elif check_args(args, "-green_nodes") == True:
		settings["node_color"] = "#15B615"
	elif check_args(args, "-blue_nodes") == True:
		settings["node_color"] = "#15B6B6"
	elif check_args(args, "-darkblue_nodes") == True:
		settings["node_color"] = "#1515B6"
	elif check_args(args, "-purple_nodes") == True:
		settings["node_color"] = "#B615B6"
	elif check_args(args, "-darkpurple_nodes") == True:
		settings["node_color"] = "#6615B6"
	elif check_args(args, "-pink_nodes") == True:
		settings["node_color"] = "#B61566"
	return settings

def color_links(settings, args):
	if check_args(args, "-red_links") == True:
		settings["link_c   olor"] = "#B61515"
	elif check_args(args, "-orange_links") == True:
		settings["link_color"] = "#B66615"
	elif check_args(args, "-yellow_links") == True:
		settings["link_color"] = "#B6B615"
	elif check_args(args, "-green_links") == True:
		settings["link_color"] = "#15B615"
	elif check_args(args, "-blue_links") == True:
		settings["link_color"] = "#15B6B6"
	elif check_args(args, "-darkblue_links") == True:
		settings["link_color"] = "#1515B6"
	elif check_args(args, "-purple_links") == True:
		settings["link_color"] = "#B615B6"
	elif check_args(args, "-darkpurple_links") == True:
		settings["link_color"] = "#6615B6"
	elif check_args(args, "-pink_links") == True:
		settings["link_color"] = "#B61566"
	return settings

def color_ant(settings, args):
	if check_args(args, "-red_ant") == True:
		settings["ant_colors_list"] = ['#B61515', '#B61515', '#B61515', '#B61515', '#B61515', '#B61515', '#B61515', '#B61515', '#B61515', '#B61515', '#B61515']
	elif check_args(args, "-orange_ant") == True:
		settings["ant_colors_list"] = ['#B66615', '#B66615', '#B66615', '#B66615', '#B66615', '#B66615', '#B66615', '#B66615', '#B66615', '#B66615', '#B66615']
	elif check_args(args, "-yellow_ant") == True:
		settings["ant_colors_list"] = ['#B6B615', '#B6B615', '#B6B615', '#B6B615', '#B6B615', '#B6B615', '#B6B615', '#B6B615', '#B6B615', '#B6B615', '#B6B615']
	elif check_args(args, "-green_ant") == True:
		settings["ant_colors_list"] = ['#15B615', '#15B615', '#15B615', '#15B615', '#15B615', '#15B615', '#15B615', '#15B615', '#15B615', '#15B615', '#15B615']
	elif check_args(args, "-blue_ant") == True:
		settings["ant_colors_list"] = ['#15B6B6', '#15B6B6', '#15B6B6', '#15B6B6', '#15B6B6', '#15B6B6', '#15B6B6', '#15B6B6', '#15B6B6', '#15B6B6', '#15B6B6']
	elif check_args(args, "-darkblue_ant") == True:
		settings["ant_colors_list"] = ['#1515B6', '#1515B6', '#1515B6', '#1515B6', '#1515B6', '#1515B6', '#1515B6', '#1515B6', '#1515B6', '#1515B6', '#1515B6']
	elif check_args(args, "-purple_ant") == True:
		settings["ant_colors_list"] = ['#B615B6', '#B615B6', '#B615B6', '#B615B6', '#B615B6', '#B615B6', '#B615B6', '#B615B6', '#B615B6', '#B615B6', '#B615B6']
	elif check_args(args, "-darkpurple_ant") == True:
		settings["ant_colors_list"] = ['#6615B6', '#6615B6', '#6615B6', '#6615B6', '#6615B6', '#6615B6', '#6615B6', '#6615B6', '#6615B6', '#6615B6', '#6615B6']
	elif check_args(args, "-pink_ant") == True:
		settings["ant_colors_list"] = ['#B61566', '#B61566', '#B61566', '#B61566', '#B61566', '#B61566', '#B61566', '#B61566', '#B61566', '#B61566', '#B61566']
	return settings

def set_speed(settings, args):
	if check_args(args, "-fast") == True:
		settings["steps_between_nodes"] = 5
	if check_args(args, "-slow") == True:
		settings["steps_between_nodes"] = 30
	return settings

def set_repeat(settings, args):
	if check_args(args, "-repeat") == True:
		settings["repeat"] = True
	return settings

def set_size(settings, args):
	if check_args(args, "-small") == True:
		settings["node_size"] = 50
		settings["markersize"] = 5.0
	elif check_args(args, "-big") == True:
		settings["node_size"] = 5000
		settings["markersize"] = 50.0
	return settings

def set_window_size(settings, args):
	flag = False
	if check_args(args, "-window_size") == True:
		for arg in args:
			if (arg == "-window_size"):
				flag = True
		if flag == True:
			line = arg.split(" ")
		try:
			x = (int)(line[0])
			y = (int)(line[1])
		except Exception:
			print ("default size taken, please choose a size between 0 and 20")
			return settings
		if (x >= 0 and x <= 20 and y >= 0 and y <= 20):
			settings["window_size"] = (x, y)
		print (settings["window_size"])
	return settings

#To be check
# def set_nodes_names(settings, args, farm):
# 	if check_args(args, "-nodes_name") == True:
# 		settings["labels"] = dict([(farm.start, 'START'), (farm.end, 'END')])
# 	else:
# 		settings["labels"] = None

def print_usage(args):
	if check_args(args, "-help") == True:
		usage()

def print_farm(args, farm):
	if check_args(args, "-farm") == True:
		print ("{} - ants:\t{}\n{} - start:\t{}\n{} - end:\t{}\n\n{} - rooms: \n{}\n\n{} - pos: \n{}\n\n{} - links \n{}\n\n{} - moves \n{}".format(type(farm.ants), farm.ants, type(farm.start), farm.start, type(farm.end), farm.end, type(farm.nodes), farm.nodes, type(farm.pos), farm.pos, type(farm.links), farm.links, type(farm.moves), farm.moves))

def create_settings(args, farm):
	settings = {}
	settings = basic_settings(settings, args, farm)
	settings = color_background(settings, args)
	settings = color_nodes(settings, args)
	settings = color_links(settings, args)
	settings = color_ant(settings, args)
	settings = set_speed(settings, args)
	settings = set_repeat(settings, args)
	settings = set_size(settings, args)
	settings = set_window_size(settings, args)
	# settings = set_nodes_names(settings, args, farm)
	print_usage(args)
	print_farm(args, farm)
	return settings