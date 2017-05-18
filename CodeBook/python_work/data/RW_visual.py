import matplotlib.pyplot as plt

from random import choice


class RandomWalk:
    """make a RandomWalk picture just for fun"""

    def __init__(self, num_points=100000):
        self.num_points = num_points

        # create list for x and y AND set startPoint(0,0)
        self.x_value = [0]
        self.y_value = [0]

    def fill_walk(self):
        while len(self.x_value) < self.num_points:
            x_direction = choice([1, -1])
            x_distance = choice([0, 1, 2, 3, 4])
            x_step = x_direction * x_distance

            y_direction = choice([1, -1])
            y_distance = choice([0, 1, 2, 3, 4])
            y_step = y_direction * y_distance

            if x_step == 0 and y_step == 0:
                continue

            next_x = self.x_value[-1] + x_step
            next_y = self.y_value[-1] + y_step

            self.x_value.append(next_x)
            self.y_value.append(next_y)


while True:
    rw = RandomWalk()
    rw.fill_walk()
    point_number = list(range(rw.num_points))

    plt.scatter(0, 0, c='r', edgecolors='none', s=50)
    plt.scatter(rw.x_value[-1], rw.y_value[-1], edgecolors='none', c='b', s=50)

    plt.scatter(rw.x_value, rw.y_value, c=point_number,
                cmap=plt.cm.Oranges, edgecolors='none', s=6)

    plt.savefig("Random_Walk.png", bbox_include='tight')

    # hide axes
    plt.axes().get_xaxis().set_visible(False)
    plt.axes().get_yaxis().set_visible(False)

    # plt.figure(figsize=(10, 6))
    plt.show()

    keep_running = input("Are you want more walk? (y/n) ")
    if keep_running == 'n':
        break
