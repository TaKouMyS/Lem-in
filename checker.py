#!/usr/bin/env python
# coding: utf-8

import numpy as np

class   Output_Checker() :
    def __init__(self, output, map_parser) :
        self.output = output 
        self.map_parser = map_parser
        self.actions = None 
        self.raw_actions = "" 
        self.map_output = "" 
        self.ants_arrived = 0
        self.error_message = ""

    def check_unique_action(self, action, nb_line, actions = None) :
        if actions == None :
            actions = self.actions
        if self.map_parser.find_room(action[1]) == None :
            self.error_message = "Room '{}' on line {} doesn'exist"\
                    .format(action[1], nb_line)
            return (1)
        if action[1] in self.map_parser.start.tab_link :
            return (0)
        for i in range(nb_line - 1, -1, -1) :
            index = np.where(actions[i][:, 0] == action[0])[0]
            if len(index) == 1 :
                room = actions[i][int(index)][1]
                room = self.map_parser.find_room(room)
                if self.map_parser.find_room(action[1]) not in room.tab_link :
                    self.error_message = "No link existing between {} (line : {}) and {} (line {})"\
                            .format(action[1], nb_line, room, i)
                    return (1)
                return (0)
            if i == 0 :
                self.error_message = "Ant '{}' in room '{}' come frome nowhere (line : {})"\
                        .format(action[0], action[1], nb_line)
        return (0)

    def check_step(self, nb_line, actions = None) :
        if (actions == None) :
            actions = self.actions
        lst_line = actions[nb_line]
        if (min(map(len, lst_line)) < 2) :
            self.error_message = "Wrong action format : line " + str(nb_line)
            return (1)
        uniques, counts = np.unique(lst_line[:, 0], return_counts=True)
        ants_error = [(key, value) for key, value in zip(uniques, counts)
                if value > 1]
        uniques, counts = np.unique(lst_line[:, 1], return_counts=True)
        nb_occur_room = dict(zip(uniques, counts))
        room_error = [(key, value) for key, value in nb_occur_room.items()\
                if value > 1 and key != self.map_parser.end.name]
        if len(ants_error) > 0 :
            self.error_message = "Ant number '{}' is in {} rooms at the same time line {}."\
                    .format(str(ants_error[0][0]), str(ants_error[0][1]), str(nb_line))
            return (1)
        if len(room_error) > 0 :
            self.error_message = "Multiple ants in a room (" + str(room_error)\
                    + ") line " + str(nb_line)
            return (1)
        if self.map_parser.end.name in nb_occur_room.keys() :
            self.ants_arrived += nb_occur_room[self.map_parser.end.name]
        for action in lst_line :
            if self.check_unique_action(action, nb_line) == 1 :
                return (1)
        return (0)

    def check_actions(self, actions = None) :
        actions = self.actions if actions == None else actions
        if (actions == []) :
            self.error_message = "There is no action to check"
            return (1)
        for i in range(len(self.actions)) :
            actions[i] = actions[i].replace("L", "", 1)
            actions[i] = actions[i].split(" L")
            actions[i] = np.array(\
                    [action.split("-", 1) for action in actions[i]])
            if (self.check_step(i, actions) == 1) :
                self.error_message += "\nLine : '{}'".format(self.raw_actions[i])
                return (1)
        if self.ants_arrived != self.map_parser.ants :
            self.error_message = "Wrong number of ants arrived : \nAnts arrived : {}\nMap ants : {}"\
                    .format(self.ants_arrived, self.map_parser.ants)
            return (1)
        return (0)

    def check_map_output(self, map_output = "") :
        if map_output == "" : 
            map_output = self.map_output
        for i in range(len(map_output)) :
            if map_output[i] != self.map_parser.map_gen[i].rstrip("\n") :
                self.error_message = "The output map is not the same on line "\
                        + str(i) + "\n|{}|\n|{}|".format(str(map_output[i]),\
                        str(self.map_parser.map_gen[i]))
                return (1)
        return (0)

    def split_output(self) :
        self.output = [line.rstrip("\n") for line in self.output]
        for i in range(len(self.output)) :
            if self.output[i] == "" :
                self.actions = self.output[i + 1 :]
                self.raw_actions = self.output[i + 1 :]
                self.map_output = self.output[:i - 1]
                return (0)
        self.error_message = "Wrong output format : No '\\n' separator between map and actions"
        return (1)
