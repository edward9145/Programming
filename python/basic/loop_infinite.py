import random

while True:
    rand = random.randint(0, 10)
    if rand > 8:
        print('.' * rand)

