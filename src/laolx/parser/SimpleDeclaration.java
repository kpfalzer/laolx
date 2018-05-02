/*
 *
 *  * The MIT License
 *  *
 *  * Copyright 2018 kpfalzer.
 *  *
 *  * Permission is hereby granted, free of charge, to any person obtaining a copy
 *  * of this software and associated documentation files (the "Software"), to deal
 *  * in the Software without restriction, including without limitation the rights
 *  * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *  * copies of the Software, and to permit persons to whom the Software is
 *  * furnished to do so, subject to the following conditions:
 *  *
 *  * The above copyright notice and this permission notice shall be included in
 *  * all copies or substantial portions of the Software.
 *  *
 *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *  * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *  * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 *  * THE SOFTWARE.
 *
 *
 */

package laolx.parser;

/**
 * Some examples:
 *  const int a
 *  var string s = "bar"
 *  var lambda{(T a, b) -> int} v  //declare v to be function.
 *  const f = lambda ()->float {return 45}  //define f as function
 *  g = %w{a b c}  //const array of words
 *  h = %s{d e f}  //const of symbols
 *  int[] j = [1,2,3]   //array of int.  'j = [1,2,3]' would also be ok (since type can be inferred)
 *  v = lambda (T a, b) -> int {return a + b}  //later define v
 *  xx = lambda()->void {...}  //define xx as function with no return value
 *  yy = lambda(){...}  //define yy as function with no return value
 *  zz = lambda<T,R>(T a, T b)->R {return a + b}  //template-d function
 *  // example usage: result = zz(12,13)
 *  //              : rr = zz(b:123, a:456)  //named arguments
 *  aa = lambda()->%t{r1,r2} {... return %t{v1,v2}}  //define aa as function return tuple.  Tuple is %t{...}
 *  bb = lambda<T1,T2=int>(T1 x)->%t{T2 r1, r2} {... return %t{...}}
 *  v1 = C1.new(...) //v1 is instance of class C1
 *
 *  //structured binding
 *  v1, v2 = bb(...)  //bb return tuple (i.e., pair) and splat to v1 and v2
 *  T1 v3, T2 v4 = bb(...) //explicit types for v3 and v4
 *
 *  //declare multiple types
 *  T1 v2, T2 v2, T3[] v3
 *
 *  NOTES:
 *  1) In general, lack of specific type is allowed: assuming 'auto' type inference can be done for c++ target.
 *  2) By default, all declarations are 'const', unless 'var' specified.
 *  3) [] is fixed array for default/const; else vector (for 'var').
 *  4) 'lambda{...}' syntax expresses a type.
 */
public class SimpleDeclaration {
}
