import sys

class farm:
    """ This class represent the content of the farm."""

    def __init__(self):
        self.links  = []
        self.nodes  = []
        self.moves  = []
        self.pos    = {}
        self.start  = None
        self.end    = None
        self.ants   = int(0)
