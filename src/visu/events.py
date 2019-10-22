
# def on_click(event):
# 	print("button: {}".format(event.button))
# def on_key(event):
# 	global ani
# 	print("key: {}\tevent source: {}".format(event.key, ani.event_source))
# 	global settings
# 	global anim_running
# 	if (event.key == "p"):
# 		anim_running = play_pause(ani, anim_running)
# 	elif (event.key == "z"):
# 		up_node_size(settings)
# 	elif (event.key == "x"):
# 		down_node_size(settings)
# 	elif (event.key == "c"):
# 		up_ant_size(settings)
# 	elif (event.key == "v"):
# 		down_ant_size(settings)
# 	elif (event.key == "d"):
# 		switch_background_color(settings)
# 	elif (event.key == "f"):
# 		switch_node_color(settings)
# 	elif (event.key == "g"):
# 		switch_link_color(settings)
# 	elif (event.key == "h"):
# 		reset_settings(settings)
		
def play_pause(ani, anim_running):
	if anim_running:
		ani.event_source.stop()
		anim_running = False
	else:
		ani.event_source.start()
		anim_running = True
	return anim_running

def up_node_size(settings):
	settings["node_size"] += 20

def down_node_size(settings):
	settings["node_size"] -= 20

def up_ant_size(settings):
	settings["markersize"] += 3

def down_ant_size(settings):
	settings["markersize"] -= 3

def reset_settings(settings):
	settings["steps"] = 15
	settings["window_size"] = None
	settings["repeat"] = False
	settings["link_color"] = "#101010"
	settings["text_color"] = "#EEEEEE"
	settings["background_color"] = "#15202B"
	settings["node_color"] = "#282828"
	settings["ant_colors_list"] = ['#1515B6', '#1515B6', '#1515B6', '#1515B6', '#1515B6', '#1515B6', '#1515B6', '#1515B6', '#1515B6', '#1515B6', '#1515B6']

def switch_background_color(settings):
	print (settings["background_color"])
	if settings["background_color"] == "#15202b":
		settings["background_color"] = "#1515b6"
	elif settings["background_color"] == "#1515b6":
		settings["background_color"] = "#15B6b6"
	elif settings["background_color"] == "#15B6b6":
		settings["background_color"] = "#6615b6"
	elif settings["background_color"] == "#6615b6":
		settings["background_color"] = "#b61566"
	elif settings["background_color"] == "#b61566":
		settings["background_color"] = "#b66615"
	elif settings["background_color"] == "#b66615":
		settings["background_color"] = "#b61515"
	elif settings["background_color"] == "#b61515":
		settings["background_color"] = "#b6b615"
	elif settings["background_color"] == "#b6b615":
		settings["background_color"] = "#15b615"
	elif settings["background_color"] == "#15b615":
		settings["background_color"] = "#15202B"

def switch_node_color(settings):
	if settings["node_color"] == "#282828":
		settings["node_color"] = "#1515B6"
	elif settings["node_color"] == "#1515B6":
		settings["node_color"] = "#15B6B6"
	elif settings["node_color"] == "#15B6B6":
		settings["node_color"] = "#6615B6"
	elif settings["node_color"] == "#6615B6":
		settings["node_color"] = "#B61566"
	elif settings["node_color"] == "#B61566":
		settings["node_color"] = "#B66615"
	elif settings["node_color"] == "#B66615":
		settings["node_color"] = "#B61515"
	elif settings["node_color"] == "#B61515":
		settings["node_color"] = "#B6B615"
	elif settings["node_color"] == "#B6B615":
		settings["node_color"] = "#15B615"
	elif settings["node_color"] == "#15B615":
		settings["node_color"] = "#282828"

def switch_link_color(settings):
	if settings["link_color"] == "#101010":
		settings["link_color"] = "#1515B6"
	elif settings["link_color"] == "#1515B6":
		settings["link_color"] = "#15B6B6"
	elif settings["link_color"] == "#15B6B6":
		settings["link_color"] = "#6615B6"
	elif settings["link_color"] == "#6615B6":
		settings["link_color"] = "#B61566"
	elif settings["link_color"] == "#B61566":
		settings["link_color"] = "#B66615"
	elif settings["link_color"] == "#B66615":
		settings["link_color"] = "#B61515"
	elif settings["link_color"] == "#B61515":
		settings["link_color"] = "#B6B615"
	elif settings["link_color"] == "#B6B615":
		settings["link_color"] = "#15B615"
	elif settings["link_color"] == "#15B615":
		settings["link_color"] = "#101010"
