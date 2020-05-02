import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import matplotlib.patches as patches



if __name__ =='__main__':

    width = 6
    height = 4

    data = pd.read_csv("../result.csv")

    fig = plt.figure()
    ax = plt.axes()
    r = patches.Rectangle(xy=(4, 10), width=width, height=height, color='black')
    ax.add_patch(r)
    ax.plot(data['t'], data['s'], color="red")
    plt.xlabel('t[s]')
    plt.ylabel('s[m]')
    plt.title('A star Speed Planning')
    plt.show()
