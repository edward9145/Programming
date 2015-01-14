# Filename: img_crawl.py

import urllib
import re
import os

def dumpPath(src, type='.html'):
	return r'img\\' + src.replace('/', '').replace(':','').replace('?','').replace('&','').replace('<','').replace('>','').replace('/','').replace('\\','').replace('|','') + type

def dumpUrl(src, type='.html'):
	# test_dump = ''
	# test_img = 'http://pic.yupoo.com/jinyanjay/BUbioqv4/xaQI5.png'
	thumb_href = 'http://g.e-hentai.org/s/7fb1e53661/526371-1'
	path = dumpPath(src, type)
	if not os.path.exists(path):
		try:
			urllib.urlretrieve(src, path);
		except:
			print 'failed'


def imgCrawl(page=0, url_entry='http://g.e-hentai.org/g/527302/ef8defdd9a/'):
	if page != 0:
		url_entry += ('?p=' + str(page))
	print url_entry
	
	# 'http://g.e-hentai.org/g/526288/0a8a9c55cc/?p=2'
	# 'http://g.e-hentai.org/g/526311/62906a7ae4/' 
	# 'http://g.e-hentai.org/g/526371/c75d2d9372/'
	# http://g.e-hentai.org/g/526458/24847dbc5c/
	# http://g.e-hentai.org/g/514235/61fb059a0f/
	
	# f = urllib.urlopen(url_entry)

	dumpUrl(url_entry)
	f = open(dumpPath(url_entry))

	for line in f.readlines():
		print line,
		urls = re.findall(r'href=[\'"]?([^\'" >]+)', line)
		# print urls
		for url in urls:
			if url.count('-') == 2:
				dumpUrl(url)
				print dumpPath(url)
				img_file = open(dumpPath(url))
				for l in img_file.readlines():
					img_urls = re.findall(r'src=[\'"]?([^\'"]+)', l)
					# print img_urls
					for img_url in img_urls:
						if len(img_url) > 40 and (img_url.endswith('.jpg') or img_url.endswith('.png')):
							print img_url
							dumpUrl(img_url, '')
							# dumpUrl(img_url[img_url.rindex('/'):], '')  # save jpg
				img_file.close()
				# raw_input()

	f.close()


if not os.path.exists('img'):
	os.mkdir('img')
file_path = os.getcwd() + '\\img\\' ;
print file_path

# file_entry = file_path + 'httpg.e-hentai.orgg526371c75d2d9372.html'

startPage = 0
endPage = 4
for i in range(startPage, endPage):
	imgCrawl(i)

# http://173.162.62.113:9000/h/7fb1e53661c95e3af3875ffc76959de7e03bc571-161022-560-420-jpg/keystamp=1347763723-ec4456b4ce/00001.jpg
# http://173.162.62.113:9000/h/7fb1e53661c95e3af3875ffc76959de7e03bc571-161022-560-420-jpg/keystamp=1347763723-ec4456b4ce/00001.jpg
# http://173.162.62.113:9000/h/7fb1e53661c95e3af3875ffc76959de7e03bc571-161022-560-420-jpg/keystamp=1347763671-6c8f343750/00001.jpg

# http://82.135.231.211/h/46f968eea94c68189c80b31356a5fbd72ee4a0b9-497008-800-600-png/keystamp=1347804300-4c416eefef/00002.png

# url = raw_input('url: ')
# f = urllib.urlopen(url)
# file:///E:/Programme/Python/ch12.html
# while True:
	# line = f.readline()
	# if len(line) == 0:
		# break;
	# print line,
# f.close()