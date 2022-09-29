from numpy import zeros, where, array, round as npround
from sys import stdin


def main():
    N = int(stdin.readline())
    
    i = 0
    t = zeros(N)
    y = zeros(N)

    for line in stdin:
        t[i], y[i] = map(float, line.split())
        i += 1
        if i == N:
            break
        
    roc_auc = 0.0
    
    mask =  t[:, None] > t
    idx = array(where(mask == True))
    size = array(idx).size // 2


    for i in range(size):
        roc_auc += (y[idx[0, i]] > y[idx[1, i]]) + (y[idx[0, i]] == y[idx[1, i]]) / 2

    return npround(roc_auc / size, 6)

if __name__ == "__main__":
    print(main())
