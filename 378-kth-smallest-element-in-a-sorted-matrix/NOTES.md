This problem has a trick pattern
It's binary search with k condition where k satisfies the recursion from the 2D matrix
resulting in a time complexity of
O(m+n * logD)
where m and n are rows and colomns and D is the difference between the maximum and minimum elements
​
the format pattern will be
​
binary search
conditon recurrance
recurrance code -> on the top
​
//original conditon
```
`if (countLessOrEqual(matrix, mid) >= k) {
ans = mid;
right = mid - 1; // try to looking for a smaller value in the left side
} else left = mid + 1; // try to looking for a bigger value in the right side
}`
```
​
​