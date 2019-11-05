def isPrime(num):
    # if num < 2:
    #     return True
    if num < 0:
        return False

    import math
    sqrt = int(math.sqrt(num))
    for i in range(2, sqrt+1):
        if num % i == 0:
            return False
    return True
