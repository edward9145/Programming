def lucas():
    yield 2
    a = 2
    b = 1
    while True:
        yield b
        a, b = b, a+b

for x in lucas():
    if  x < 100:
        print(x)
    else:
        break
        