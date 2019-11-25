"""

This project was inspired by John Hammond's video:
https://www.youtube.com/watch?v=81sDM2HoGOs&t=616s

"""

from modules import *

init()

input = input('Enter a image file name: ')

try:
    img = Image.open(input)
except:
    print(colored('Something went wrong when opening the file', 'red'))
    exit()


size = w, h = img.size

data = img.load()

pieces = []

for x in range(w):
    for y in range(h):
        hex_c = '#' + ''.join([hex(it)[2:].zfill(2).upper() for it in data[x, y]])
        pieces.append((x, y, hex_c))

random.shuffle(pieces)
print(pieces)

with open('coords.txt', 'w') as f:
    for piece in pieces:
        f.write(str(piece).replace("'", '') + '\n')
