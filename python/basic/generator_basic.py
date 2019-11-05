def gen246():
    print("about to yield 2")
    yield 2
    print("about to yield 4")
    yield 4
    print("about to yield 6")
    yield 6
    print("about to return")
    
g = gen246()

next(g)
next(g)
next(g)
next(g, None)


def gen_range():
    for i in range(5):
        print("about to yield {}".format(i))
        yield i

gr = gen_range()
next(gr)

# sum [1...9]
sum(x for x in range(1,10))
square1000 = (x*x for x in range(1,1000))
list(square1000)
