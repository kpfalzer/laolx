//
//  string.cxx
//  
//
//  Created by Karl W Pfalzer on 12/11/19.
//

#include "apfev3/acceptor.hxx"
#include "laolx/parser/string.hxx"

namespace laolx {
namespace parser {

using apfev3::_Acceptor;
using apfev3::Consumer;
using apfev3::TPTokens;

class String::__Acceptor : public _Acceptor {
public:
    
protected:
    TPTokens _accept(Consumer& consumer) const;
};

//todo: #{expression} as EVALSTRING, actually parses expression.
static const apfev3::Terminal __evalBegin("#{");
static const apfev3::Regex __evalBody("([^}\\\\]|\\\\.)*}");
static const apfev3::Regex __squoted("'([^'\\\\]|\\\\.)*'");
static const apfev3::Regex __dquoted("\"([^\"\\\\]|\\\\.)*\"");

}
}
