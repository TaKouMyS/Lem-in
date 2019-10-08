#!/usr/bin/env python
# coding: utf-8

import executer
import subprocess

def display_menu() :
    print("Select one of these options :")
    print("1 : Execute generator")
    print("2 : Execute custom map")
    print("3 : Execute all map in a repository")

def ask_input(input_message, invalid_message, valid_arg) :
    while (1) :
        arg = input(input_message)
        if (arg not in valid_arg) :
            print(invalid_message)
        else :
            break
    return (arg)

def ask_int_input(input_message, invalid_message, min_arg = None, max_arg = None) :
    while (1) :
        arg = input(input_message)
        try :
            arg = int(arg)
        except ValueError :
            print(invalid_message)
            continue
        if ((min_arg == None or arg >= min_arg) and (max_arg == None or arg <= max_arg)) :
            break
        else :
            print(invalid_message)
    return (arg)

def generator_option() :
    print("\n--------- Generator Executer ---------")
    valid_arg = ["--big-superposition", "--big", "--flow-thousand", "--flow-ten", "--flow-one"]
    for arg, i in zip(valid_arg, range(1, len(valid_arg) + 1)) :
        print("{} : {}".format(i, arg))
    arg = ask_int_input("\nChoose an arg among the ones up there\nArg : ",\
            "Invalid arg. Valid args are between 1 and " + str(len(valid_arg)), 1, len(valid_arg))
    arg = valid_arg[int(arg) - 1]
    nb_exec = ask_int_input("Number of executions : ",\
            "The number of execution must be an interger > 0", 1)
    execu = executer.Gen_Executer(nb_exec, arg)
    execu.execute_generator()

def custom_option() :
    print("\n--------- Custom Executer ---------")
    custom_exec = executer.Custom_Executer()
    while (1) :
        map_path = input("Give the map path (eg: 'maps/map_custom')\nMap path : ")
        if (custom_exec.execute_custom(map_path) == 0) :
            break

def repository_option() :
    print("\n--------- Repository Execuer ---------")
    while (1) :
        repo_path = input("Give the repository path to execute.\nRepo_path : ")
        try :
            pipe = subprocess.Popen(["ls", repo_path],\
                    stdout=subprocess.PIPE,\
                    stderr=subprocess.PIPE,\
                    universal_newlines=True)
            output, error_message = pipe.communicate()
            pipe.terminate()
            break
        except FileNotFoundError :
            print("No repo '{}'".format(repo_path))
    output = [repo_path + "/" + map_name for map_name in output.split("\n")\
            if map_name != '']
    for map_repo in output :
        map_executer = executer.Custom_Executer(map_repo)
        map_executer.execute_custom()

if __name__ == "__main__" :
    display_menu()
    # valid_input = ["1", "2", "3"]
    valid_input = ["1", "2", "3"]
    option = ask_input("Option : ",\
            "This option doesn't exist. Give an input between " + ", ".join(valid_input), valid_input)
    if (option == "1") :
        generator_option()
    if (option == "2") :
        custom_option()
    if (option == "3") :
        repository_option()
