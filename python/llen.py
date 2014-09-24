import redis
import datetime,time
import sys

print '--usage: llen.py lname [count] [interval]\n'

lname = 'SMS_SEND_QUEUE'
count = 10
interval = 1

if len(sys.argv) > 1:
  lname = sys.argv[1]
if len(sys.argv) > 2:
  count = int(sys.argv[2])
if len(sys.argv) > 3:
  interval = int(sys.argv[3])

r = redis.Redis(host='127.0.0.1', port=6379, db=0)

for i in range(0, count):
  slen = r.llen(lname)
  time.sleep(interval)
  elen = r.llen(lname)
  dlen = elen - slen
  sign = '+' if dlen >= 0 else ''
  now = time.strftime("%Y-%m-%d %H:%M:%S")
  print "%s [%s]: %4d\t\t%s%d" % (now, lname, elen, sign, dlen)

