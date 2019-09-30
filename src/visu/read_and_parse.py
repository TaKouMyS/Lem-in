# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    read_and_parse.py                                  :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amamy <amamy@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/19 02:22:52 by amamy             #+#    #+#              #
#    Updated: 2019/09/30 04:00:05 by amamy            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import sys
import re

from farm import farm
        
def fill_moves(line):
    tmp = line.strip().split()
    moves = []
    for steps in tmp :
        steps = steps[1:]
        moves.append(steps.split('-'))
    return (moves)

    
def farm_parser():
    input_list = []
    ant_farm = farm()
    tmp2 = []
    for line in sys.stdin:
        input_list.append((line.strip()).split())
        if line[0][0] == 'L':
            ant_farm.moves.append(fill_moves(line)) 
    ant_farm.ants = int(input_list[0][0])
    flag = None
    gen = (line for line in input_list if (line and re.search(r"()-()", line[0][0]) is None))
    for line in gen:
        if re.search(r"^#{2}(start|end)", line[0]):
            if line and re.search(r"^#{2}(start)", line[0]):
                flag = "s"
            elif line and re.search(r"^#{2}(end)", line[0]):
                 flag = "e"
        elif len(line) == 3 and line[0][0] != 'L':
            print line
            ant_farm.nodes.append(line[0])
            ant_farm.pos[line[0]] = tuple(line[1:])
            print "pooooos-------------" 
            print ant_farm.pos[line[0]]
            if flag == 's' :
                ant_farm.start = line[0]
            elif flag == 'e' :
                ant_farm.end = line[0]
            flag = None
    gen = (line for line in input_list if (line and re.search(r"()-()", line[0]) and line[0][0] != 'L'))
    for line in gen:
        ant_farm.links.append(line[0].split('-'))
    return (ant_farm)


    

