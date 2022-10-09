from turtle import * import random
speed(speed ='fastest')
def draw(n, x, angle):
	for i in range(n):
		colormode(255)
		a = random.randint(0, 255)
		b = random.randint(0, 255)
		c = random.randint(0, 255)
		pencolor(a, b, c)
		fillcolor(a, b, c)
		begin_fill()
		for j in range(5):
			forward(5 * n-5 * i)
			right(x)
			forward(5 * n-5 * i)
			right(72 - x)
		end_fill()
		rt(angle)
n = 30 # number of stars
x = 144 # exterior angle of each star
angle = 18 # angle of rotation for the spiral
draw(n, x, angle)
