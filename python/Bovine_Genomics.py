 #http://www.usaco.org/index.php?page=viewproblem2&cpid=860
 
# making my code ~~user friendly~~ lolol

 n, m = map(int, input().split())

# read in the DNA sequences for the two sets of cows
set1 = []
set2 = []
for i in range(n):
    set1.append(input())
for i in range(n):
    set2.append(input())

# iterate through all possible DNA triplets and check if they appear in both sets
unique_triplets = set()
for base1 in ['A', 'C', 'G', 'T']:
    for base2 in ['A', 'C', 'G', 'T']:
        for base3 in ['A', 'C', 'G', 'T']:
            triplet = base1 + base2 + base3
            appears_in_set1 = set()
            appears_in_set2 = set()
            for seq in set1:
                appears_in_set1.add(seq[0:3])
                appears_in_set1.add(seq[1:4])
                appears_in_set1.add(seq[2:5])
            for seq in set2:
                appears_in_set2.add(seq[0:3])
                appears_in_set2.add(seq[1:4])
                appears_in_set2.add(seq[2:5])
            if triplet in appears_in_set1 and triplet in appears_in_set2:
                unique_triplets.add(triplet)

print(len(unique_triplets))

