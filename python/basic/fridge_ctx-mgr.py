from contextlib import closing

class RefrigeratorRaider():

    def open(self):
        print("Open fridge door")

    def take(self, food):
        print("Finding {}...".format(food))
        if "fries" in food or "fried" in food:
            raise RuntimeError("Health warning!")
        print("Taking {}".format(food))

    def close(self):
        print("Close fridge door\n")

def raid(food):
    with closing(RefrigeratorRaider()) as r:
        r.open()
        r.take(food)

if __name__ == "__main__":
    raid("apple")
    raid('pizza')
    raid('fried potato')