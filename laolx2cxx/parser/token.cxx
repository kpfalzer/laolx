/*
 * The MIT License
 *
 * Copyright 2017 kpfalzer.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include "parser/token.hxx"

laolx::String Location::toString() const {
    laolx::String loc;
    if (!filename.empty()) {
        loc += filename + ":";
    }
    loc += ":";
    loc += linenum;
    loc += ":";
    loc += colnum;
    return loc;
}

const laolx::String Token::EMPTY = "";

const Token::CodeByString Token::stKeywords({
    // K_xxx are keywords
    {"assert", Token::K_ASSERT},
    {"case", Token::K_CASE},
    {"catch", Token::K_CATCH},
    {"class", Token::K_CLASS},
    {"const", Token::K_CONST},
    {"default", Token::K_DEFAULT},
    {"else", Token::K_ELSE},
    {"elsif", Token::K_ELSIF},
    {"extends", Token::K_EXTENDS},
    {"extern", Token::K_EXTERN},
    {"float", Token::K_FLOAT},
    {"for", Token::K_FOR},
    {"if", Token::K_IF},
    {"implements", Token::K_IMPLEMENTS},
    {"include", Token::K_INCLUDE},
    {"int", Token::K_INT},
    {"interface", Token::K_INTERFACE},
    {"namespace", Token::K_NAMESPACE},
    {"new", Token::K_NEW},
    {"nil", Token::K_NIL},
    {"private", Token::K_PRIVATE},
    {"protected", Token::K_PROTECTED},
    {"public", Token::K_PUBLIC},
    {"static", Token::K_STATIC},
    {"string", Token::K_STRING},
    {"throw", Token::K_THROW},
    {"unless", Token::K_UNLESS},
    {"until", Token::K_UNTIL},
    {"when", Token::K_WHEN},
    {"while", Token::K_WHILE}
});


const Token::CodeByString Token::stSymbols({
    {"~", Token::S_TIDLE},
    {"!", Token::S_EXCLAMATION},
    {"@", Token::S_AT},
    {"#", Token::S_POUND},
    {"$", Token::S_DOLLAR},
    {"%", Token::S_PCNT},
    {"^", Token::S_PCNTEQ},
    {"%w{", Token::S_WORDS},
    {"%s{", Token::S_SYMBOLS},
    {"^", Token::S_CARET},
    {"&", Token::S_AND},
    {"&=", Token::S_ANDEQ},
    {"&&", Token::S_AND2},
    {"&&=", Token::S_AND2EQ},
    {"*", Token::S_STAR},
    {"*=", Token::S_STAREQ},
    {"**", Token::S_STAR2},
    {"**=", Token::S_STAR2EQ},
    {"(", Token::S_LPAREN},
    {")", Token::S_RPAREN},
    {"-", Token::S_MINUS},
    {"+", Token::S_PLUS},
    {"++", Token::S_PLUS2},
    {"=", Token::S_EQ},
    {"=>", Token::S_EQGT},
    {"+=", Token::S_PLUSEQ},
    {"-=", Token::S_MINUSEQ},
    {"{", Token::S_LCURLY},
    {"}", Token::S_RCURLY},
    {"[", Token::S_LBRACK},
    {"]", Token::S_RBRACK},
    {"|", Token::S_OR},
    {"|=", Token::S_OREQ},
    {"||", Token::S_OR2},
    {"||=", Token::S_OR2EQ},
    {"\\", Token::S_BSLASH},
    {":", Token::S_COLON},
    {"::", Token::S_COLON2},
    {";", Token::S_SEMI},
    {"\"", Token::S_DQOUTE},
    {"'", Token::S_SQUOTE},
    {"<", Token::S_LT},
    {"<=", Token::S_LTEQ},
    {"<<", Token::S_LT2},
    {"<<=", Token::S_LT2EQ},
    {">", Token::S_GT},
    {">=", Token::S_GTEQ},
    {">>", Token::S_GT2},
    {">>=", Token::S_GT2EQ},
    {",", Token::S_COMMA},
    {".", Token::S_DOT},
    {"..", Token::S_DOT2},
    {"...", Token::S_DOT3},
    {"?", Token::S_QMARK},
    {"/", Token::S_DIV},
    {"`", Token::S_BACKTIC},
});

Token::SymbolsByChar Token::stSymbolsByChar;

bool Token::stInited = Token::init();

bool Token::init() {
    stSymbols.each([](const CodeByString::value_type & kv) {
        char ch = kv.first.at(0);
        stSymbolsByChar[ch] << kv;
    });
    //sort by descending length
    stSymbolsByChar.each([](const SymbolsByChar::value_type & kv) {
        auto vals = const_cast<SymbolsByChar::mapped_type&> (kv.second);
        vals.sort([](auto& a, auto& b) {
            return a.first.length() > b.first.length();
        });
    });
    return true;
}

bool Token::isKeyword(const laolx::String& text, Code& code) {
    const bool isKeyword = stKeywords.hasKey(text);
    code = isKeyword ? stKeywords[text] : INVALID;
    return isKeyword;
}

Token::~Token() {
}
