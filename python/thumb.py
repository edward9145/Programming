import Image
import glob, os

size = 128, 128

for files in glob.glob(r'./*.jpg'):
    print files  
    filepath,filename = os.path.split(files)  
    filterame,exts = os.path.splitext(filename)  
#    print filepath,filename,filterame,exts

    thumbfile = 's_' + filename
    im = Image.open(files)
    im.thumbnail(size, Image.ANTIALIAS) 
    im.save(thumbfile)
    print thumbfile
