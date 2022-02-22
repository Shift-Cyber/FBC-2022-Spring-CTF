
def factor(x:int) -> None:
    for i in range(1, x+1):
        if x % i == 0: print(i)

N=6528775549
factor(N)