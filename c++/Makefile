
RDIR ?= ../..
SRCS ?= src/laolx/parser/*.cxx
MAIN ?= laolx/main.cxx
INCL ?= src src/apfev3 src/xyzzy
OS   ?= $(shell uname -s)
LIB  ?= laolx
EXE  ?= laolx
DOTA ?= ../../apfev3/_VARIANT_/${OS}/apfev3.a

ifeq ("Darwin","${OS}")
	CCOPTS ?= -std=c++11 -lstdc++
else
	CCOPTS ?= -std=c++11 -static-libstdc++
endif

.PHONY: debug debug.a
debug: debug.a
	(cd debug/${OS}; g++ -o ${EXE} -g ${INCL:%=-I ${RDIR}/%} ${CCOPTS} ${MAIN:%=${RDIR}/%} ${LIB}.a $(subst _VARIANT_,${@},${DOTA:%=${RDIR}/%}) )

debug.a:
	-rm -rf debug/${OS}
	mkdir -p debug/${OS}
	(cd debug/${OS}; g++ -c -g ${INCL:%=-I ${RDIR}/%} ${CCOPTS} ${SRCS:%=${RDIR}/%} )
	(cd debug/${OS}; ar cr ${LIB}.a *.o )

