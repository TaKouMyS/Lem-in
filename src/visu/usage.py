import os

def usage():
	os.system('clear')

	red = "\x1b[31m"
	orange = "\x1b[91m"
	blue = "\x1b[34m"
	green = "\x1b[32m"
	yellow = "\x1b[33m"
	purple = "\x1b[35m"
	pink = "\x1b[95m"
	cyan = "\x1b[36m"
	grey = "\x1b[40m"
	underline = "\x1b[4m"
	rev = "\x1b[7m"
	bold = "\x1b[1m"
	end = "\x1b[0m"

	print("  {}{}{}compile:{}".format(underline, bold, cyan, end))
	print
	print("\t{}{}make".format(bold, blue, end))
	print("  {}{}{}Launch visualizer:{}".format(underline, bold, cyan, end))
	print
	print("\t{}{}./visualizer.sh [map_file] [-visu_argument_1] [-visu_argument_2] etc...{}".format(bold, blue, end))
	print
	print("  {}{}{}visu options:{}".format(underline, bold, cyan, end))
	print
	print("\t{}-farm:{} print the farm structure in terminal".format(green, end))
	print("\t{}-fast:{} change the step settings from 15 to 5".format(green, end))
	print("\t{}-slow:{} change the step settings from 5 to 30".format(green, end))
	print("\t{}-small:{} change the node size setting from 50 to 5000 and ant size from ".format(green, end))
	print("\t{}-big:{} change the node size setting from 500 to 5000".format(green, end))
	print("\t{}-repeat:{} change the repeat settings from False to True".format(green, end))
	# print("\t{}-nodes_name:{} print rooms names in visu".format(green, end))
	print("\t{}-window-size:{} next argument must be size 'x y' or it will launch with basic settings".format(green, end))
	print("\t{}-dark_theme:{} change the theme settings".format(green, end))
	print("\t{}-blue_theme:{} change the theme settings".format(green, end))
	print("\t{}-[color]_ant:{} change the ant color".format(green, end))
	print("\t{}-[color]_nodes{}: change the nodes color".format(green, end))
	print("\t{}-[color]_links:{} change the links color".format(green, end))
	print("\t{}-[color]_background:{} change the background color".format(green, end))
	print
	print("\t{}{}[colors]:{} {}red, {}orange, {}yellow, {}green, {}blue, {}darkblue, {}purple, {}pink".format(bold, green, end, red, orange, yellow, green, cyan, blue, purple, pink))
	print
