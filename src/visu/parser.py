#!/usr/bin/python
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    parser.py                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amamy <amamy@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/01 00:05:01 by amamy             #+#    #+#              #
#    Updated: 2019/10/01 00:07:42 by amamy            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import re
import sys
import networkx as nx
import matplotlib.pyplot as plt
from class_farm import ant_farm
from get_items import get_start, get_end, get_room, get_link, get_move

def regex_compile():
	"""pre compile all regex we need to parse map"""

	reg_dict = {}
	reg_dict["is_error"] = re.compile(r"^ERROR$")
	reg_dict["is_ant_nb"] = re.compile(r"^\d+$")
	reg_dict["is_comment"] = re.compile(r"^#")
	reg_dict["is_start"] = re.compile(r"^#{2}(start)")
	reg_dict["is_end"] = re.compile(r"^#{2}(end)")
	reg_dict["is_room"] = re.compile(r"^([\d\w]+) \d+ \d+\n$")
	reg_dict["is_link"] = re.compile(r"^([\d\w]+)-([\d\w]+)\n$")
	reg_dict["is_move"] = re.compile(r"L([\d\w]+)-([\d\w]+)")
	return (reg_dict)

def check_status(farm, status, line):
	"""deal with previous loop iteration comment to pass or add start | end"""

	if (status == None):
		return status
	elif (status == "start"):
		get_start(farm, line)
	elif (status == "end"):
		get_end(farm, line)
	elif (status == "comment"):
		pass
	status = None
	return status

def parser():
	"""create an ant_farm object, parse lemin outpout to fill it's values"""

	status = None
	farm = ant_farm()
	reg_dict = regex_compile()
	
	for line in sys.stdin:
		status = check_status(farm, status, line)
		if (reg_dict["is_ant_nb"].search(line)):
			farm.ants = int(line)
		elif (reg_dict["is_start"].search(line)):
			status = "start"
		elif (reg_dict["is_end"].search(line)):
			status = "end"
		elif (reg_dict["is_comment"].search(line)):
			status = "comment"
		elif (reg_dict["is_room"].search(line)):
			get_room(farm, line)
		elif (reg_dict["is_move"].search(line)):
			get_move(farm, line)
		elif (reg_dict["is_link"].search(line)):
			get_link(farm, line)
		elif (reg_dict["is_error"].search(line)):
			print "ERROR"
			quit()
	return (farm)
