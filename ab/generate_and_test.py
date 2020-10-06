import random

print("\nFinding if subarray exists with given sum->\n")
arr = [int(item) for item in input("Enter input array : ").split()]

size = len(arr)

cumilativeSum = []
sum = 0
cumilativeSum.append(sum)
for item in arr :
    sum+=item
    cumilativeSum.append(sum)

target = int(input("Enter target sum : "))

num_iterations = 1000

for i in range(num_iterations):
    print("\nIteration : " + str(i+1))
    start = random.randint(0,size-2)
    end = random.randint(start,size-1)
    sum = cumilativeSum[end+1]-cumilativeSum[start]
    print("Start = {0} End = {1} Sum = {2}".format(start,end,sum))
    
    if sum == target:
        print("Solution Found\n")
        break
    else:
        print("Solution not found, Generate new solution\n")