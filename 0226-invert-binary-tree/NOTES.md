Many might say why we need an iterative solution in every tree problem ?
The ans is simple, Tree can be skewed which effectively makes it a linked list.
And if we recurse in a large linked-list, the call stack will overflow for sure.
That's why its necessary to also know how to implement iteratively.
Honestly, iterative implementation also will utilize a stack, but it will be in heap.