import pprint
class Item:
    def __init__(self, v1, v2):
        self.v1 = v1
        self.v2 = v2
    
    def __str__(self):
        return "%s,%s | v1+v2: %s | v1-v2 = %s" % (self.v1, self.v2, self.v1 + self.v2, self.v1 - self.v2)

def printls(list):
    for item in list:
        print(item)
    print()

item_list = [Item(1,2), Item(2,4), Item(3,1), Item(2,3)]
sorted_list = sorted(item_list, key=lambda item: item.v1, reverse=True)

printls(item_list)
print()
printls(sorted_list)


def item_cmp(i1, i2):
    return (i1.v1+i1.v2) < (i2.v1+i2.v2)

Item.__lt__ = item_cmp

sorted_list2 = sorted(item_list)
printls(sorted_list2)


def item_cmp2(i1, i2):
    return (i1.v1-i1.v2) < (i2.v1-i2.v2)

Item.__lt__ = item_cmp2
sorted_list2 = sorted(item_list)
printls(sorted_list2)

Item.__lt__ = item_cmp
printls(item_list)
item_list.sort()
printls(item_list)
