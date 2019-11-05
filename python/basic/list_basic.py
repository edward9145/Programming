# copy list
org = list("abcde")
org1 = org[:]
org2 = org[:]

print(id(org) == id(org1))


# create list
al = [[-1,1]] * 5
print(al)


# >>> a = [[1,2],[3,4]]
# >>> b = a[:]
# >>> a[1]
# [3, 4]
# >>> a[1].append(5)
# >>> b[1]
# [3, 4, 5]
# >>> b
# [[1, 2], [3, 4, 5]]


u = "the quick brown fox jumps over the lazy dog".split()
u.sort()
u.reverse()
u.sort(reverse=True)

# >>> sorted(u)
# >>> reversed(u)
list(reversed(u))
