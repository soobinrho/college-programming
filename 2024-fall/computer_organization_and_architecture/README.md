# Computer Organization and Architecture
`2024 Fall`

My entire life, I wasn't able to understand what 2's complement actually means.
In this class, I finally understood how it works.
Basically, the best way so far to do subtractions in computer circuits is to store all negative numbers in 2's complements.

1. Invert all 0's to 1's, and vice versa.
2. Add 1.

Now, A-B becomes A + (2's complement of B), which makes the subtraction efficient.
