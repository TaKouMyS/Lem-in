#!/usr/bin/env python
# coding: utf-8

class   Room() :
    def __init__(self, name) :
        self.name = name
        self.tab_link = []

    def __str__(self) :
        s = self.name + " -> ["
        for i in range(len(self.tab_link)) :
            s += str(self.tab_link[i].name)
            if i != len(self.tab_link) - 1 :
                s += ", "
        s += "]"
        return s

    def __repr__(self) :
        return (self.__str__())

class   Map_Parser() :
    def __init__(self, map_gen) :
        self.map_gen = map_gen
        self.ants = 0
        self.steps_required = -1 
        self.start = None
        self.end = None
        self.room_tab = [None] * 9679

    def hash_function(self, name) :
        nbr = 0
        b_value = int(''.join(format(ord(x), 'b') for x in name), 2)
        for i in range(len(name)) :
            nbr += b_value 
            nbr += nbr << 10
            nbr ^= nbr >> 6
        nbr += nbr << 3
        nbr ^= nbr >> 11
        nbr += nbr << 15
        return (nbr % len(self.room_tab))
    
    def find_room(self, name) :
        cel = self.room_tab[self.hash_function(name)]
        if cel != None :
            for room in cel :
                if room.name == name :
                    return (room)
        return (None)

    def parse_com(self, line, i) :
        if line[1] == "#" :
            line_next = self.map_gen[i].rstrip("\n")
            if line[2:] == "start" :
                self.start = self.parse_room(line_next)
                return (1)
            elif line[2:] == "end" :
                self.end = self.parse_room(line_next)
                return (1)
        if "lines required:" in line and self.steps_required == -1 :
            line = line.split(" ")
            if line[-1].isdigit() :
                self.steps_required = int(line[-1])
        return (0)

    def parse_room(self, line) :
        line = line.rsplit(" ", 2)
        if len(line) < 3 or not line[-2].isdigit() or not line[-1].isdigit() :
            return (None)
        name = " ".join(line[:len(line) - 2])
        room = Room(name)
        hash_nbr = self.hash_function(room.name);
        if self.room_tab[hash_nbr] == None :
            self.room_tab[hash_nbr] = [room]
        else :
            self.room_tab[hash_nbr].append(room)
        return (room)

    def parse_link(self, line) :
        line = line.split("-")
        if len(line) < 2 :
            return (0)
        for i in range(len(line) - 1) :
            name1 = "-".join(line[:i + 1])
            name2 = "-".join(line[i + 1:])
            room1 = self.find_room(name1)
            room2 = self.find_room(name2)
            if room1 != None and room2 != None :
                room1.tab_link.append(room2)
                room2.tab_link.append(room1)
                return (0)
        return (1)

    def parse_map(self) :
        step = 0
        i = 0
        while i < len(self.map_gen) :
            line = self.map_gen[i]
            line = line.rstrip("\n")
            i += 1
            done = 0
            if line[0] == "#" :
                i += self.parse_com(line, i)
                continue
            if step == 0 :
                if not line.isdigit() :
                    return (1)
                self.ants = int(line)
                step += 1
                continue
            if step == 1 :
                room = self.parse_room(line)
                if room != None :
                    continue
            if step == 2 or step == 1 :
                link = self.parse_link(line)
                if link != None :
                    if (step == 1) :
                        step += 1
                    continue
            return (1)
        return (0)

    def __str__(self) :
        s = ""
        for cel in self.room_tab :
            if cel != None :
                s += str(cel[0]) + "\n"
        s += "Ants : " + str(self.ants)
        s += "\nStart : " + str(self.start)
        s += "\nEnd : " + str(self.end)
        return (s)

    def __repr__(self) :
        print(self.__str__())
