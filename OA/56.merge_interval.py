intervals = [[1,3],[4,5],[6,9]]
newInterval = [3,4]
left = [one for one in intervals if one[1] < newInterval[0]]
right = [one for one in intervals if one[0] > newInterval[1]]

print left
print right

if left + right != intervals:
    leftVal = intervals[len(left)][0]
    rightVal = intervals[-len(right)-1][1]
    mid = [min(leftVal, newInterval[0]), max(rightVal, newInterval[1])]
    res = left + [mid] + right
else:
    res = left + [newInterval] + right
print res
