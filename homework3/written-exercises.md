Problem 1.
 Address of A[0][0] = 0x7fffda007c50
 Address of A[3][7] = 0x7fffda007d78

 This shows that the array of structs is declared beginning at memory location 0x7fffda007c50 with a size of 8, and each subsequent array element has a size of 8 leading to increments of 8 for each element. For 37 increments, an increment of 296 spaces lead to the address of A[3][7].

Problem 2.
