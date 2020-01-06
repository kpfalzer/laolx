//
//  token.cxx
//  
//
//  Created by Karl W Pfalzer on 12/11/19.
//

#include "apfev3/acceptor.hxx"
#include "laolx/parser/Token.hxx"

namespace laolx {
namespace parser {

using apfev3::Regex;
using apfev3::token::CharSequence;
using apfev3::token::Spacing;
using apfev3::toAlternativeNode;
using apfev3::TPTerminal;

/**
 Sized: DEC'BASEvalue
 */
TPNode
Sized::_accept(Consumer& consumer) const {
    static const Regex HEX("[0-9a-fA-F][_0-9a-fA-F]*");
    static const Regex OCT("[0-7][_0-7]*");
    static const Regex DEC("[0-9][_0-9]*");
    static const Regex BIN("[01][_01]*");
    const Mark start = consumer.mark();
    TPNode size = DEC.accept(consumer);
    if (size.isNull()) return nullptr;
    if ('\'' == consumer[0]) {
        consumer.accept(1);
        char base = consumer[0];
        const Regex *rex = nullptr;
        switch(base) {
            case 'h': case 'H':
                rex = &HEX;
                break;
            case 'o': case 'O':
                rex = &OCT;
                break;
            case 'd': case 'D':
                rex = &DEC;
                break;
            case 'b': case 'B':
                rex = &BIN;
                break;
            default:
                break;
        }
        if (nullptr != rex) {
            consumer.accept(1);
            TPNode val = rex->accept(consumer);
            if (val.isValid()) {
                Spacing::THE_ONE.accept(consumer);
                return new Node(size, base, val);
            }
        }
    }
    consumer.rewind(start);
    return nullptr;
}

/*static*/ const Sized& Sized::THE_ONE = Sized();

Sized::Node::Node(const TPNode& _size, char _base, const TPNode& _val) {
    TPTerminal size = toTerminal(_size);
    TPTerminal val = toTerminal(_val);
    std::string text = size->text + '\'' + _base + val->text;
    _set(text, size->location);
}

ostream&
Sized::Node::operator<<(ostream& os) const {
	return os << text;
}

TPNode
Symbol::_accept(Consumer& consumer) const {
    static const apfev3::Regex IDENT("([_a-zA-Z][_a-zA-Z\\d]*)");
    TPNode node;
    const Mark start = consumer.mark();
    if (consumer[0] == ':') {
        consumer.accept(1);
        node = IDENT.accept(consumer);
        if (node.isNull()) {
            consumer.rewind(start);
            return nullptr;
        }
        const size_t n = consumer.mark() - start;
        consumer.rewind(start);
        node = toNode(consumer.accept(n));  //no -1 since we already account for :
        node = new Node(node);
        Spacing::THE_ONE.accept(consumer);
    }
    return (node.isValid()) ? node : nullptr;
}

/*static*/ const Symbol& Symbol::THE_ONE = Symbol();

Symbol::Node::Node(const TPNode& node)
: _Terminal(node)
{}

ostream&
Symbol::Node::operator<<(ostream& os) const {
	return os << text;
}

TPNode
Bool::_accept(Consumer& consumer) const {
    static const Alternatives GRAM({&K_FALSE, &K_TRUE});
	TPNode node = GRAM.accept(consumer);
    return (node.isValid()) ? new Node(node) : nullptr;
}

/*static*/ const Bool& Bool::THE_ONE = Bool();

Bool::Node::Node(const TPNode& node)
: _Terminal(toAlternativeNode(node)->actual()) {
    __isTrue = (text == "true");
}

ostream&
Bool::Node::operator<<(ostream& os) const {
	return os << text;
}

// accept : /.../ or %r{...}
TPNode
Regexp::_accept(Consumer& consumer) const {
    TPNode node;
    if (consumer[0] == '/') {
        const char opening = consumer[0];
        size_t n = 1;
        for (; !(consumer[n] == opening) && !consumer.isEOF(n); ++n) {
            if (consumer[n] == '\\') ++n;
        }
        node = toNode(consumer.accept(n+1)); //todo
    } else {
        static const char* OPEN = "%r{";
        static const CharSequence R1(OPEN);
        const Mark start = consumer.mark();
        node = R1.accept(consumer);
        if (node.isValid()) {
            size_t n = 0;
            for (; !(consumer[n] == '}') && !consumer.isEOF(n); ++n) {
                if (consumer[n] == '\\') ++n;
            }
            INVARIANT(!consumer.isEOF(n));
            consumer.rewind(start);
            n += strlen(OPEN);
            node = toNode(consumer.accept(n+1));
        }
    }
    if (node.isValid()) {
        node = new Node(node);
        Spacing::THE_ONE.accept(consumer);
    }
    return (node.isValid()) ? node : nullptr;
}

/*static*/ const Regexp& Regexp::THE_ONE = Regexp();

TPNode
Ident::_accept(Consumer& consumer) const {
    TPNode node = apfev3::token::Ident::THE_ONE.accept(consumer);
    return (node.isValid()) ? new Node(node) : nullptr;
}

/*static*/ const Ident& Ident::THE_ONE = Ident();

TPNode
Token::_accept(Consumer& consumer) const {
    TPNode node = sequence.accept(consumer);
    if (node.isNull()) return nullptr;
    /*unused*/ apfev3::token::Spacing::THE_ONE.accept(consumer);
    return new Node(node, type);
}

//extern
const Token
    S_AND("&", Token::Node::eS_AND),
    S_AND2("&&", Token::Node::eS_AND2),
    S_COLON(":", Token::Node::eS_COLON),
    S_COMMA(",", Token::Node::eS_COMMA),
    S_EXCLAMATION("!", Token::Node::eS_EXCLAMATION),
    S_TILDE("~", Token::Node::eS_TILDE),
    S_LBRACK("[", Token::Node::eS_LBRACK),
    S_LCURLY("{", Token::Node::eS_LCURLY),
    S_LPAREN("(", Token::Node::eS_LPAREN),
    S_LT("<", Token::Node::eS_LT),
    S_MINUS("-", Token::Node::eS_MINUS),
    S_MINUS2("--", Token::Node::eS_MINUS2),
    S_OR("|", Token::Node::eS_OR),
    S_PLUS("+", Token::Node::eS_PLUS),
    S_PLUS2("++", Token::Node::eS_PLUS2),
    S_GT(">", Token::Node::eS_GT),
    S_DOT(".", Token::Node::eS_DOT),
    S_RBRACK("]", Token::Node::eS_RBRACK),
    S_RCURLY("}", Token::Node::eS_RCURLY),
    S_RPAREN(")", Token::Node::eS_RPAREN),
    S_SEMICOLON(";", Token::Node::eS_SEMICOLON),
    S_SYMBOLS("%s{", Token::Node::eS_SYMBOLS),
    S_WORDS("%w{", Token::Node::eS_WORDS),
    //
    K_BOOL("bool", Token::Node::eK_BOOL),
    K_CHAR("char", Token::Node::eK_CHAR),
    K_FALSE("false", Token::Node::eK_FALSE),
    K_FLOAT("float", Token::Node::eK_FLOAT),
    K_FROM("from", Token::Node::eK_FROM),
    K_IMPORT("import", Token::Node::eK_IMPORT),
    K_INT("int", Token::Node::eK_INT),
    K_NIL("nil", Token::Node::eK_NIL),
    K_STRING("string", Token::Node::eK_STRING),
    K_SYMBOL("symbol", Token::Node::eK_SYMBOL),
    K_THIS("this", Token::Node::eK_THIS),
    K_TRUE("true", Token::Node::eK_TRUE)
;

ostream&
Token::Node::operator<<(ostream& os) const {
    os << text;
    return os;
}

}
}
