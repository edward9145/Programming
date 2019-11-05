>>> be = {'Olivia','Harry','Lily','Jack'}
>>> bh = {'Harry','Jack','Amelia','Mia','Jack'}
>>> sh = {'Harry','Amelia'}
>>> tp = {'Harry','Lily','Amelia','Lola'}
>>> be.union(bh)
{'Jack', 'Lily', 'Olivia', 'Harry', 'Amelia', 'Mia'}
>>> be.union(sh)
{'Jack', 'Lily', 'Olivia', 'Harry', 'Amelia'}
>>> be.intersection(sh)
{'Harry'}
>>> be.intersection(bh)
{'Jack', 'Harry'}
>>> be.difference(bh)
{'Lily', 'Olivia'}
>>> be.symmetric_difference(bh)
{'Lily', 'Olivia', 'Amelia', 'Mia'}
>>> sh.issubset(bh)
True
>>> sh.issubset(be)
False
>>> bh.issuperset(sh)
True
>>> ob = {'Mia'}
>>> ob.isdisjoint(be)
True
>>> ob.isdisjoint(bh)
False