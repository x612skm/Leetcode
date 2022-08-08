Key intution
We have to make the intervals in the sorted order so we can think of
3 types
map not the unordered one
priority queue
ordered_set
​
why we select the one we **select**
we do not select the **priority queue** as we have to deal with the binary search also for whether can book the interval set or not.
We do not select the **Ordered_set** because we cannot make the pairs there then we have to make the custom set there
We finally **select** **map data strcuture** for storing the details in ordered form and also in the form of intervals we have the [start,end)
start as the key and end as the value;
```
Ordered_map<int,int> mp;
```
​
​
​