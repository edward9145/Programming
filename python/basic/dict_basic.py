from pprint import pprint as pp
m = {
    'B': [1, 2, 3],
    'Be': [7, 9, 10],
    'C': [11, 12, 13, 14],
    'He': [3, 4],
    'Li': [6, 7],
    'N': [13, 14, 15]
}

pp(m)

for key in m:
    print("{} => {}".format(key, m[key]))

pp(m.values())

color = dict(red='F00',blue='0F0')
update_color = {'green': '00F', 'yellow': 'FF0', 'blue': '00ff00'}
color.update(update_color)

pp(color)
