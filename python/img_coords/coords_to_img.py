"""

This project was inspired by John Hammond's video:
https://www.youtube.com/watch?v=81sDM2HoGOs&t=616s

"""

from PIL import Image

coords = []
max_x = max_y = 0

with open('coords.txt', 'r') as f:
    for line in f.readlines():
        x, y, c = line.strip().split()
        x = int(x[1:-1])
        y = int(y[:-1])
        r = int(c[1:3], 16)
        g = int(c[3:5], 16)
        b = int(c[5:7], 16)

        coords.append([x, y, r, g, b])

        max_x = max(x, max_x)
        max_y = max(y, max_y)

w = max_x + 1
h = max_y + 1
size = w, h

img = Image.new('RGB', size)
data = img.load()

for coord in coords:
    x, y, r, g, b = coord
    data[x, y] = (r, g, b)

img.show()
img.save('image.jpg')
