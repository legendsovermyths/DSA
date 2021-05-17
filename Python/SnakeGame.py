from os import system, name as OSname
from getkey import getkey, keys
from threading import Thread
from random import randint
from cursor import hide
from sys import stdout
from time import sleep

# --------------configs-------------#
speed = 0.4
IMG_food = "🍎"
IMG_body = "🟩"
IMG_border = "⬜"
IMG_empty = " "
length = 11
width = 11
snakeBody = [5, 3]  # start position
foodPos = [5, 7]  # food start position
# ----------------------------------#

hide()
border = 0
points = 1
running = True
order, old = "null", "null"

world = [[IMG_empty] * length for _ in range(width)]
x, y = snakeBody[0], snakeBody[1]
world[x][y] = IMG_body
world[foodPos[0]][foodPos[1]] = IMG_food

for _ in world:
    world[border][0] = IMG_border
    world[border][-1] = IMG_border
    border += 1
world[0] = IMG_border * len(world[0])
world[-1] = IMG_border * len(world[-1])


def clear(t=0):
    sleep(t)
    system("cls" if OSname == "nt" else "clear")


def printt(string, delay=0.005):
    for character in string:
        stdout.write(character)
        stdout.flush()
        sleep(delay)
    print("")


def display():
    print("\033[H", end="")
    for row in world:
        print(" ".join(map(str, row)))


def foodgen():
    pos1 = randint(1, width - 2)
    pos2 = randint(1, length - 2)

    if world[pos1][pos2] == IMG_empty:
        world[pos1][pos2] = IMG_food
    else:
        foodgen()


def update(nx=0, ny=0):
    global x, y, points, running
    x += nx
    y += ny
    snakeBody.append(x)
    snakeBody.append(y)

    if world[x][y] == IMG_empty:
        world[snakeBody[0]][snakeBody[1]] = IMG_empty
        del snakeBody[1]
        del snakeBody[0]
    if world[x][y] == IMG_food:
        points += 1
        foodgen()
    if world[x][y] == IMG_border or world[x][y] == IMG_body:
        running = False
    else:
        try:
            world[x][y] = IMG_body
        except:
            running = False


def move():
    global old
    if order == "up":
        update(-1, 0)
        old = "up"
    if order == "down":
        update(1, 0)
        old = "down"
    if order == "left":
        update(0, -1)
        old = "left"
    if order == "right":
        update(0, 1)
        old = "right"
    display()


def keypress(key):
    global order
    if key == keys.UP and old != "down" or key == "w" and old != "down":
        order = "up"
    if key == keys.DOWN and old != "up" or key == "s" and old != "up":
        order = "down"
    if key == keys.LEFT and old != "right" or key == "a" and old != "right":
        order = "left"
    if key == keys.RIGHT and old != "left" or key == "d" and old != "left":
        order = "right"


class KeyboardThread(Thread):
    def __init__(self, input_cbk=None, name="keyboard-input-thread"):
        self.input_cbk = input_cbk
        super(KeyboardThread, self).__init__(name=name)
        self.start()

    def run(self):
        while running:
            self.input_cbk(getkey())


printt("Use WASD or ←↕→ to move", 0.05)
clear(1)
kthread = KeyboardThread(keypress)

while running:
    move()
    sleep(speed)
print("You died\nLength =", points)
