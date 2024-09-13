# Computer Organization and Architecture
`2024 Fall`

- Textbook: Computer Organization and Design: RISC-V Edition
- Author: David A. Patterson & John L. Hennessy

## 2024-09
My entire life, I wasn't able to understand what 2's complement actually means.
In this class, I finally understood how it works.
Basically, the best way so far to do subtractions in computer circuits is to store all negative numbers in 2's complements.

1. Invert all 0's to 1's, and vice versa.
2. Add 1.

Now, A-B becomes A + (2's complement of B), which makes the subtraction efficient.

#### Context
- RISC-V is an open-source instruction set.
- Assembly language is a subet + high-level abstraction of instruction set, which refers to all instructions available in an architecture.
- Assembly language has high-level abstractions like macros and mnemonics.
- Instruction set is hard-wired in the CPU.
- The popular 64bit (x86-64 aka. AMD64) instruction set was developed by AMD in 2000, and has been used extensively by AMD and Intel.
- Apple's M2 chip uses the ARM instruction set.

#### RISC-V
- RISC-V has 32 registers. Therefore, all instruction sets in their binary forms are 32-bits long.
- For example, the add instruction consists of funct7 + rs2 + rs1 + funct3 + rd + opcode. Here, notice that funct7 has 7 bits and funct3 has 3 bits.
