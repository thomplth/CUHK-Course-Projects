import matplotlib.pyplot as plt
import numpy as np


# Histogram
data = np.random.normal(0, 1, 1000)
weight = np.ones_like(data) / (len(data))
plt.hist(data, weights=weight)
plt.savefig("histogram.png")
plt.show()

# Pie chart
data = [3193, 3424, 3324, 3595, 300, 600, 300, 1258, 1322]
label = ['Chung Chi College',
           'United College',
           'New Asia College',
           'Shaw College',
           'Morningside College',
           'S.H. Ho College',
           'CW Chu College',
           'Wu Yee Sun College',
           'Lee Woo Sing College']
plt.pie(data[4:7], labels=label[4:7])
plt.savefig("pie.png")
plt.show()

# Bar chart
plt.barh(label[::-1], data[::-1])
plt.savefig("bar.png")
plt.show()

# Scatter plot and line chart
x_list = np.linspace(0, 1, 100)
y_list = x_list + np.random.rand(100)
plt.scatter(x_list, y_list, marker='*', color='red', alpha=0.5)
plt.plot(x_list, x_list, linestyle='dashed')
# plt.plot(y_list, y_list, linestyle='dashed')
plt.savefig("scatter_line.png")
plt.show()

