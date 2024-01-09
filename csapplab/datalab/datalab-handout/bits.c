/* 
 * CS:APP Data Lab 
 * 
 * <2024.01.09: 28/36 = 77分>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  每个"Expr"都是仅使用以下内容的表达式：

  1. 整数常量0到255（包括0xFF）。不允许使用大整数常量，如0xffffffff。
  2. 函数参数和局部变量（不允许使用全局变量）。
  3. 一元整数操作符 ! ~
  4. 二元整数操作符 & ^ | + << >>

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

  您被明确禁止：

  1. 使用任何控制结构，如 if、do、while、for、switch 等。
  2. 定义或使用任何宏。
  3. 在此文件中定义任何额外的函数。
  4. 调用任何函数。
  5. 使用任何其他操作，例如 &&、||、- 或 ?。
  6. 使用任何形式的类型转换。
  7. 使用除 int 以外的任何数据类型。这意味着您不能使用数组、结构体或联合。
 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31.

  您可以假设您的计算机：
  1. 使用二进制补码，32位整数的表示形式。
  2. 在算术右移时执行右移操作。
  3. 在进行移位操作时，如果移位量小于0或大于31，则具有不可预测的行为。

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

可接受的编码样式示例：

  /*
  * pow2plus1 - 返回 2^x + 1，其中 0 <= x <= 31
  */
  int pow2plus1(int x) {
      /* 利用移位操作计算2的幂 */
      return (1 << x) + 1;
  }

  /*
  * pow2plus4 - 返回 2^x + 4，其中 0 <= x <= 31
  */
  int pow2plus4(int x) {
      /* 利用移位操作计算2的幂 */
      int result = (1 << x);
      result += 4;
      return result;
  }


FLOATING POINT CODING RULES

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.  The max operator count is checked by dlc.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
//1
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
  // x^y = (x & ~y) | (~x & y)
  // 画图分析
  return ~(x & y)&~(~x & ~y);
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
  // 返回最小的补码整数，32位机器-> -2^31
  // 参考pow2plus1
  int x = 31;
  return 1<<x;
}
//2
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmax(int x) {
  // isTmax - 如果 x 是最大的二进制补码整数，则返回1，否则返回0
  // Tmax + Tmin = 0xFFFFFFFF (二进制全1)
  // ?如何判断大小。在不调用条件语句的情况下
  int TMIN = tmin();
  return !~(x+TMIN);
}
/* 
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allOddBits(int x) {
  // allOddBits - 如果 word 的所有奇数位都设置为 1，则返回 1(0~31位有效)
  /*
   *  所有奇数位为1，偶数位为0的数是：0xAAAAAAAA
   */
  x = x&0xAAAAAAAA;
  return !(x^0xAAAAAAAA);
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
  // 考加法逆元，补码的非：按位取反+1
  return ~x + 1;
}
//3
/* 
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x) {
  // 判断该数是否在0x30~0x39之间
  // 1. 大于等于0x30， x-0x30不为负数，看符号位
  // 2. 小于等于0x39， 0x39-x不为负数
  int first = !((negate(0x30) + x)>>31);
  int second = !((0x39 + negate(x))>>31);
  return first&second;
}
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
  // x!=0 ? y:z
  // (1)的补码 全1， (0）的补码为全0
  int ans = negate(!!x); // 将x转为bool值,扩展为全1或全0
  return (ans & y) | (~ans & z);
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
  // 结合isAsciiDigit函数
  // 判断x、y的大小
  int flag = !((negate(x) + y)>>31);
  return flag;
}
//4
/* 
 * logicalNeg - implement the ! operator, using all of 
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int logicalNeg(int x) {
  // 逻辑非：只有0x0的情况才是1，不然返回0
  // 判断x!=0
  // +0 == -0, 将对整个数的判断转换为对符号位的判断
  // (negate(x) | x)>>31 + 1
  return (((~x + 1) | x)>>31) + 1;
}
/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int howManyBits(int x) {
  // 返回在二进制补码中表示 x 所需的最小位数——二分法
  // 1. 判断正负，
  //int flag = ~(!!(x>>31))+1;//判断正负并拓展位
  int flag = ~(!!(x>>31))+1; // 将x符号位转为bool值,扩展为全1或全0
  x =  (flag & ~x) | (~flag & x);

  // 2. 判断16位
  int b16 = !!(x>>16);//求高16位是否有值
  x = x >> (b16<<4); // 有就丢弃低16位

  // 2. 判断8位
  int b8 = !!(x>>8);
  x = x >> (b8<<3);

  // 3. 判断4位
  int b4 = !!(x>>4);
  x = x >> (b4<<2);

  // 4. 判断2位
  int b2 = !!(x>>2);
  x = x >> (b2<<1);

  // 5. 判断1位
  int b1 = !!(x>>1);
  x = x >> b1;
  
  int b0 = !!x;
  //
  return (b16<<4)+(b8<<3)+(b4<<2)+(b2<<1)+b1+b0+1;
}
//float
/* 
 * floatScale2 - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
/*
 * floatScale2 - 返回浮点数表达式 2*f 的位级等效表示
 *   输入和输出都以无符号整数（unsigned int）的形式表示，
 *   但应该将它们解释为单精度浮点数的位级表示。
 * 参数:
 *   uf: 以无符号整数表示的单精度浮点数
 * 返回:
 *   以无符号整数表示的单精度浮点数，表示 2*f 的位级等效表示
 *   当输入 uf 表示的浮点数是 NaN 时，返回原始输入 uf
 * 约束:
 *   可以使用整数和无符号整数的任意操作，包括 ||、&&、if、while
 *   最大操作数（ops）数为30
 * 难度: 4
 */
unsigned floatScale2(unsigned uf) {
  // 32位浮点数：1S+8exp+23frac
  // 2*f 等价于 2.0xf
  // 
  // 1. NaN : exp阶码为全1
  unsigned sign = uf & (1<<31);
  unsigned exp = (uf & 0x7f800000)>>23;
  unsigned frac = uf & (~0xff800000);
  if (exp == 0xff) return uf; // exp = 11111111, NaN
  if (exp == 0) return sign | frac << 1;
  // 规格化
  exp++;
  if (exp == 0xff) return sign | 0x7f800000; // 溢出，返回+inf/-inf
  return sign | (exp << 23) | frac;
}
/* 
 * floatFloat2Int - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
/* 
 * floatFloat2Int - 返回浮点数参数 f 的表达式 (int) f 的位级等效表示。
 *   浮点数参数 f 以无符号整数形式传递，但
 *   应该将其解释为单精度浮点数的位级表示。
 *   任何超出范围的值（包括 NaN 和无穷大）都应返回
 *   0x80000000u。
 *   合法操作：任何整数/无符号操作，包括 ||、&&。还有 if、while
 *   最大操作数：30
 *   评分：4
 */
int floatFloat2Int(unsigned uf) {
  /* !!! 舍入
   * double/float → int
   * § Truncates fractional part
   * § Like rounding toward zero
   * § Not defined when out of range or NaN: Generally sets to TMin
   */
  return 2;
}
/* 
 * floatPower2 - Return bit-level equivalent of the expression 2.0^x
 *   (2.0 raised to the power x) for any 32-bit integer x.
 *
 *   The unsigned value that is returned should have the identical bit
 *   representation as the single-precision floating-point number 2.0^x.
 *   If the result is too small to be represented as a denorm, return
 *   0. If too large, return +INF.
 * 
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. Also if, while 
 *   Max ops: 30 
 *   Rating: 4
 */
unsigned floatPower2(int x) {
    return 2;
}
