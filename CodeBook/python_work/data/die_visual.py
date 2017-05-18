from pygal_practise import Die
import pygal

die = Die()
results = []

for roll_num in range(1, 1000000):
    result = die.roll()
    results.append(result)

frequencies = []
for value in range(1, die.num_sides + 1):
    frequency = results.count(value)
    frequencies.append(frequency)

# test data
# print(frequencies)
# print(results)

# 创建直方图
hist = pygal.Bar()

hist.title = "Result of rolling one D6 1000000 times"
hist.x_labels = ['1', '2', '3', '4', '5', '6']
hist.x_title = "Result"
hist.y_title = "Frequency of result"

hist.add('D6', frequencies)

hist.render_to_file('die_visual.svg')
