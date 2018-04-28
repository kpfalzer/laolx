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

import apfev2.runtime.*;

public class TemplateArgument implements Acceptor {
    @Override
    public Accepted accept(CharBuffer charBuffer) {
        return MATCHER.accept(charBuffer);
    }

    private static final Acceptor MATCHER = new PrioritizedChoice(
        Named.THE_ONE,
        Positional.THE_ONE
    );

    public static final TemplateArgument THE_ONE = new TemplateArgument();

    public static class Positional implements Acceptor {

        @Override
        public Accepted accept(CharBuffer charBuffer) {
            return MATCHER.accept(charBuffer);
        }

        private static final Acceptor MATCHER = new PrioritizedChoice(
                // TODO: there is ambiguity here with 'IDENT' as first() of Type|ConstantExpression,
                // so let's just pull it out?
                TypeName.THE_ONE, //NO DOT3 yet...
                ConstantExpression.THE_ONE
        );

        private static final Positional THE_ONE = new Positional();
    }

    public static class Named implements Acceptor {

        @Override
        public Accepted accept(CharBuffer charBuffer) {
            return MATCHER.accept(charBuffer);
        }

        private static final Acceptor MATCHER = new Sequence(
          Tokens.IDENT.acceptor,
          Tokens.S_COLON.acceptor,
          Positional.THE_ONE
        );

        private static final Named THE_ONE = new Named();
    }


}
