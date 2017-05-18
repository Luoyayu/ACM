import csv
import matplotlib.pyplot as plt

fname = 'sitka_weather_07-2014.csv'
with open(fname) as f:
    reader = csv.reader(f)  # reader 阅读器对象
    header_row = next(reader)  # next返回文本下一行
    # print(header_row)
    
    highs = []
    for row in reader:
        highs.append(int(row[1]))

fig = plt.figure(dpi=128, figsize=(10,6))
plt.plot(highs, c='r')
