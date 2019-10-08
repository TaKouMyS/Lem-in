#!/usr/bin/python
import sys

class ant_farm:
	"""this class represent our graph"""

	def __init__(self):
		"""init a the data to none and empty"""
		self.ants   		= None
		self.start  		= None
		self.end    		= None
		self.nodes  		= []
		self.used_nodes  	= []
		self.pos    		= {}
		self.links  		= []
		self.used_links		= []
		self.moves  		= []

	def print_ant_farm(self):
		"""print the object"""
		print "Ants:\t", self.ants
		print "Start:\t", self.start
		print "End:\t", self.end
		print "\nrooms:\n", self.rooms
		print "\npos:\n", self.pos
		print "\nmoves:\n", self.moves
		print "\nlinks:\n", self.links