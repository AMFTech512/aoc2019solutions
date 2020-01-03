inputFile = open("./input.txt", 'r')

total = 0

def calcMoreFuel(fuel):
    morefuel = ((fuel//3)-2)
    while morefuel > 0:
            fuel = fuel + morefuel
            morefuel = ((morefuel//3)-2)
            # print(morefuel)
    # print(fuel)
    return fuel

while True:
    line = inputFile.readline()
    if not line:
        break
    mass = int(line)
    fuel = ((mass//3)-2)
    morefuel = calcMoreFuel(fuel)
    total = total + morefuel

# mass = 1969
# fuel = ((mass//3)-2)
# morefuel = calcMoreFuel(fuel)
# total = total + morefuel
    
print(total)
