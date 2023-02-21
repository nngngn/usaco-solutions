
# http://www.usaco.org/index.php?page=viewproblem2&cpid=923

n, k = map(int, input().split())
plants = []
for i in range(n):
    d, w = map(int, input().split())
    plants.append((d, w))
plants.sort()

trips = 0
water = k
i = 0
while i < n:
    d, w = plants[i]
    if water < w:
        # refill the watering can
        j = i - 1
        while j >= 0 and plants[j][1] < water:
            j -= 1
        if j < 0:
            # cannot water all the plants
            trips = -1
            break
        refill_d, refill_w = plants[j]
        trips += 1
        water = k - (refill_w - water)
        i = j + 1
    else:
        # water the current plant
        water -= w
        i += 1

if trips >= 0:
    # watered all the plants
    print(trips)
else:
    # could not water all the plants
    print(-1)


    # minimizes number of trips cuz plants are already sorted by distance