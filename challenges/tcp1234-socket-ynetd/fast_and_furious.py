import sys

print("You have 15 seconds to count to 100. Don't mess up.\n")

for i in range(100):
    io = input(f"Send me the number {i}: ")

    if not io == str(i):
        print("Thats not what I asked for!!")
        exit()

with open("flag.txt","r") as f:
    for l in f: print(l)
