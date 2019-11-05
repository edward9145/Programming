import os
for x in range(1,254):
        ip = '192.168.1.'+ str(x);
        res = os.system('ping -c 1 ' + ip + ' > /dev/null 2>&1');
        if res == 0:
                print ip