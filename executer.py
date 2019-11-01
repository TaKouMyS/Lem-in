#!/usr/bin/env python
# coding: utf-8

import os
import time 
import parser
import checker
import numpy as np
import subprocess

class   Map_Exec() :
    def __init__(self) :
        self.output = "" 
        self.map_gen = "" 
        self.error_message = ""

    def generate_map(self, option = "--big-superposition", map_name = "map") :
        try :
            pipe = subprocess.Popen(["./generator", str(option)],\
                    stdout=subprocess.PIPE,\
                    stderr=subprocess.PIPE,\
                    universal_newlines=True)
            self.map_gen, self.error_message = pipe.communicate()
            pipe.terminate()
        except FileNotFoundError:
            self.error_message = "Error during map generation :\n"\
                    + "No file name 'generator'."
            return (1)
        except PermissionError :
            self.error_message = "Error during map generation :\n"\
                    + "Permission denied.\nSolution : execute 'chmod 777 generator'"
            return (1)
        except :
            self.error_message = "Error during map generation."
            return (1)
        if (self.error_message != "") :
            self.error_message = "Error during map generation :\n"\
                    + self.error_message
            return (1)
        f = open("map", "w")
        f.write(self.map_gen)
        f.close()
        self.map_gen = self.map_gen.split("\n")
        if self.map_gen[-1] == '' :
            del self.map_gen[-1]
        return (0)

    def read_custom_map(self, path_map) :
        try :
            f = open(path_map, "r")
            self.map_gen = f.readlines()
            f.close()
        except FileNotFoundError :
            self.error_message = "Error during map reading.\n" +\
                    "No file named '{}'".format(path_map)
            return (1)
        except IsADirectoryError :
            self.error_message = "Error during map reading.\n" +\
                    "'{}' is a directory".format(path_map)
            return (1)
        return (0)

    def exec_lem_in(self, exec_name = "./lem-in", path_map = "map") :
        try :
            p = subprocess.Popen([exec_name])
            p.terminate()
        except FileNotFoundError :
            self.error_message = "Error during lem-in execution.\n" +\
                    "No file named '{}'".format(exec_name)
            return (1)
        self.output = os.popen(exec_name + " < " + path_map).readlines()
        if (self.error_message != "") :
            self.error_message = "Error during execution of lem-in :\n"\
                    + self.error_message
            return (1)
        elif (self.output == []) :
            self.error_message = "Error during execution of lem-in :\n"\
                    + "lem-in returned nothing on stdout (probably invalid map)"
            return (-1)
        return (0)

class   Gen_Executer() :
    def __init__(self, nb_exec, gen_option = "--big-superposition", lim_diff = 8) :
        self.nb_exec = nb_exec
        self.gen_option = gen_option
        self.lim_diff = lim_diff 
        self.result = []

    def display_generator_summary(self) :
        self.result = sorted(self.result)
        dict_diff = dict.fromkeys(set(self.result), 0)
        total = sum(self.result)
        for value in list(self.result) :
            dict_diff[value] += 1
        print("\n------- SUMMARY ---------")
        print("Nb execution : " + str(self.nb_exec))
        print("Results : ", self.result)
        print("\nMin : ", min(self.result))
        print("Max : ", max(self.result))
        print("Moyenne des self.result : {} pour {} executions".format(\
                str(total / len(self.result)), str(len(self.result))))
        print("\nMAP : ")
        for key, value in dict_diff.items() :
            print("\t{} : {}".format(key, value))

    def display_result(self, steps, steps_required,\
            error_message, warning_message) :
        blue = "\033[94m"
        green = "\033[92m"
        warning = "\033[93m"
        if (warning_message != "") :
            print(warning_message)
        warning_message = ""
        if (error_message != "") :
            print(error_message)
        else :
            print("Nb steps :       " + str(steps))
            print("Steps required : " + str(steps_required))
            diff = steps - steps_required
            color = green
            if diff > 3 and diff < 5 :
                color = blue
            elif diff > 4 :
                color = warning
            print("Difference : " + color + str(diff) + "\033[0m")
        print("--------------------------")

    def execute_generator(self, nb_exec = -1, gen_option = "") :
        nb_exec = self.nb_exec if nb_exec == -1 else nb_exec
        gen_option = self.gen_option if gen_option == "" else gen_option
        warning = ""
        map_exec = Map_Exec()
        for i in range(int(nb_exec)) :
            print("\n------- Test {}/{} -------".format(i + 1, nb_exec))
            if (map_exec.generate_map(gen_option) == 1) :
                self.display_result(-1, -1, str(map_exec.error_message), "")
                return (1)
            if (map_exec.exec_lem_in() == 1) :
                self.display_result(-1, -1, str(map_exec.error_message), "")
                return (1)
            map_parser = parser.Map_Parser(map_exec.map_gen)
            if (map_parser.parse_map() == 1) :
                warning = "WARNING : the map has not been read entirely"
            output_checker = checker.Output_Checker(map_exec.output, map_parser)
            if (output_checker.split_output() != 1) :
                if output_checker.check_map_output() == 1 :
                    os.system("mv map map_error_" + str(i))
                    self.display_result(-1, -1, output_checker.error_message +\
                            "\nThe map has been registered has map_error_" +\
                            str(i), "")
                    continue 
                if output_checker.check_actions() == 1 :
                    os.system("mv map map_error_" + str(i))
                    self.display_result(-1, -1, output_checker.error_message +\
                            "\nThe map has been registered has map_error_" +\
                            str(i), "")
                    continue 
            else :
               self.display_result(-1, -1, output_checker.error_message, "")
               continue
            steps = len(output_checker.actions)
            if map_parser.steps_required != None :
                self.result.append(steps - map_parser.steps_required)
            if self.result[i] > self.lim_diff :
                os.system("mv map map_hard_" + str(i))
                warning += "This map has been register has map_hard_" + str(i)
            steps_map = map_parser.steps_required
            self.display_result(steps, steps_map, "", warning)
            time.sleep(1)
        if self.result != [] :
            self.display_generator_summary()

class   Custom_Executer() :
    def __init__(self, path = "") :
        self.path = path

    def display_result(self, steps = -1, steps_required = -1, error_message = "") :
        if (error_message == "") :
            print("Checker : ok")
            print("steps : " + str(steps))
            if (steps_required != -1) :
                print("steps_required : " + str(steps_required))
        else :
            print(error_message)
        print("-"*len("------- Map : {} ------".format(self.path)))

    def execute_custom(self, path = "") :
        path = self.path if path == "" else path
        if (path == "") :
            print("No path")
            return (1)
        print("\n------- Map : {} ------".format(path))
        map_exec = Map_Exec()
        if (map_exec.read_custom_map(path_map = path)) :
            self.display_result(error_message = map_exec.error_message)
            return (1)
        ret = map_exec.exec_lem_in(path_map = path)
        if (ret) :
            self.display_result(error_message = map_exec.error_message)
            return (1 if ret == 1 else 0)
        map_parser = parser.Map_Parser(map_exec.map_gen)
        map_parser.parse_map()
        output_checker = checker.Output_Checker(map_exec.output, map_parser)
        if (output_checker.split_output() or output_checker.check_actions()) :
            self.display_result(error_message = output_checker.error_message)
        else :
            steps = len(output_checker.actions)
            self.display_result(steps, map_parser.steps_required)
        return (0)
