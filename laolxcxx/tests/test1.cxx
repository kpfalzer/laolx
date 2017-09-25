/*
 * The MIT License
 *
 * Copyright 2017 kwpfalzer.
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

/* 
 * File:   test1.cxx
 * Author: kwpfalzer
 *
 * Created on September 23, 2017, 12:05 PM
 */

#include <stdlib.h>
#include <iostream>
#include <string>
#include <memory>
#include <cassert>
#include <regex>
#include "laolx/map.hxx"
#include "laolx/array.hxx"
#include "laolx/regex.hxx"
#include "laolx/list.hxx"

/*
 * Simple C++ Test Suite
 */

class C : public virtual laolx::Object {
public:

    explicit C() {
    }

    auto& name() {
        return _name;
    }

    auto& name() const {
        return _name;
    }

    auto& operator<<(int v) {
        _vals << v;
        return *this;
    }

    int operator[](int ix) {
        return _vals[ix];
    }

    auto vals() const {
        return _vals;
    }

    virtual ~C() {
    }

private:
    std::string _name;
    laolx::Array<int> _vals;
};

typedef std::shared_ptr<C> TRcC;

void test1() {
    typedef laolx::Map<int, bool> Map;
    Map map;
    map[6] = true;
    std::cout << "map =========" << std::endl;
    map.each([](auto k, auto v) {
        std::cout << "k=" << k << ",v=" << v << std::endl;
    });
    const Map& cmap = map;
    //no: cmap[7] = false;
    map[7] = false;
    map[1] = true;
    std::cout << "cmap =========" << std::endl;
    cmap.each([](auto k, auto v) {
        std::cout << "k=" << k << ",v=" << v << std::endl;
    });
    Map smap = cmap.select([](auto k, auto v) {
        return (k >= 6);
    });
    std::cout << "smap =========" << std::endl;
    smap.each([](auto k, auto v) {
        std::cout << "k=" << k << ",v=" << v << std::endl;
    });
    laolx::Map<bool, int> xform = smap.map<bool, int>([](auto k, auto v) {
        return std::make_pair(v, k);
    });
    std::cout << "xform =========" << std::endl;
    xform.each([](auto k, auto v) {
        std::cout << "k=" << k << ",v=" << v << std::endl;
    });
    laolx::Array<bool> keys = xform.keys();
    bool reduced = keys.reduce<bool>(true, [](auto a, auto b) {
        return a & b;
    });
}

void test2() {
    std::vector<bool> v({true, false, true, false});
    bool b = v[2];
    b = v.at(2);
    v[0] = !v[0];

    /**/
    laolx::Array<bool> aa;
    aa << true << false << false;
    /**/
    aa[1] = true;
    b = aa[0];
    int count = 0;
    aa
            .select([](auto e) {
                return e;
            })
    .each([&count](auto e) {
        count++;
    });
    assert (2 == count);
    std::cout << "count=" << count << std::endl;
    /**/
}

void test3() {
    C c;
    c.name() = "foobar";
    c << 1 << 2 << 3;
    int x = c[1];
    assert(x == 2);
    TRcC c2;
    assert(!c2); //nil!
    c2 = std::make_shared<C>();
    c2->name() = "dogbar";
    *c2 << 6 << 7 << 8;
    assert(c2);
    assert((*c2)[2] == 8);
    std::cout << "c2 =========" << std::endl;
    c2->vals().each([](auto i) {
        std::cout << i << std::endl;
    });
}

void test4() {
    laolx::Array<TRcC> cs(5);
    assert(!cs[0]);
    cs[0] = std::make_shared<C>();
    assert(cs[0]);
    *cs[0] << 10 << 11 << 12;
    assert(3 == cs[0]->vals().length());
    cs[0]->name() = "kitty";
    assert(!cs[0]->name().empty());
    assert(!cs[4]);
    assert(cs[0]->vals()[-1] == cs[0]->vals().last());
}

void test5() {
    laolx::Regex rex("^(\\d+)");
    std::string s1 = "12345", s2 = "abc123def";
    unsigned long num;
    bool matched;
    matched = rex.match(s2);
    std::cout << "s2.count=" << rex.getMatchCount() << "," << rex.getMatch(1) << std::endl;
    matched = rex.match(s1);
    assert(matched);
    std::cout << "s1=" << rex.getMatch(1) << std::endl;
}

void test6() {

    union U {

        U() {
        }

        ~U() {
        }
        laolx::Array<int> m_int;
        laolx::Map<int, int> m_map;
    } u;
}

void test7() {
    laolx::List<int> list;
    list << 1 << 2 << 3 << 4;
    assert(4 == list.length());
    list.each([](auto i) {
        std::cout << i << std::endl;
    });
    std::cout << "selected (i>2):" << std::endl;
    list.select([](auto i){return i >2;}).each([](auto i) {
        std::cout << i << std::endl;
    });
}

int main(int argc, char** argv) {
    std::cout << "%SUITE_STARTING% maptest" << std::endl;

    std::cout << "%TEST_STARTED% test1 (maptest)" << std::endl;
    test1();
    std::cout << "%TEST_FINISHED% test1 (maptest)" << std::endl;

    std::cout << "%TEST_STARTED% test2 (maptest)" << std::endl;
    test2();
    std::cout << "%TEST_FINISHED% test2 (maptest)" << std::endl;

    std::cout << "%TEST_STARTED% test3 (maptest)" << std::endl;
    test3();
    std::cout << "%TEST_FINISHED% test3 (maptest)" << std::endl;

    std::cout << "%TEST_STARTED% test4 (maptest)" << std::endl;
    test4();
    std::cout << "%TEST_FINISHED% test4 (maptest)" << std::endl;

    std::cout << "%TEST_STARTED% test5 (maptest)" << std::endl;
    test5();
    std::cout << "%TEST_FINISHED% test5 (maptest)" << std::endl;

    std::cout << "%TEST_STARTED% test6 (maptest)" << std::endl;
    test6();
    std::cout << "%TEST_FINISHED% test6 (maptest)" << std::endl;

    std::cout << "%TEST_STARTED% test7 (maptest)" << std::endl;
    test7();
    std::cout << "%TEST_FINISHED% test7 (maptest)" << std::endl;

    std::cout << "%SUITE_FINISHED%" << std::endl;

    return (EXIT_SUCCESS);
}

