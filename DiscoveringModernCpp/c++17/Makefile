
CXXFLAGS+=  -std=c++17
# CXXFLAGS+=  -std=gnu++17
# CXXFLAGS+=  -std=c++1z
# CXXFLAGS+=  -I. 
# CXXFLAGS+=  -I${BOOST_ROOT} 
# CXXFLAGS+=  -I${HOME}/projects/boost/boost_1_53_0
CXXFLAGS+=  -g # -Wno-long-double
CXXFLAGS+=  -Wall
CXXFLAGS+=  -pedantic
# CXXFLAGS+=  -Wimplicit-fallthrough
# CXXFLAGS+=  -Wunused-parameter
# CXXFLAGS+=  -Wunused-result
# CXXFLAGS+=  -Wno-unused-result
# CXXFLAGS+=  -Werror
# CXXFLAGS+=  -Weverything # clang only
# CXXFLAGS+=  -lstdc++fs # for filesystem g++
# CXXFLAGS+=  -lc++experimental # for filesystem clang++
# CXXFLAGS+=  -O3


# CXX=        clang++
# CXX=        clang++-3.5
# CXX=        clang++-3.6
# CXX=        clang++-3.7
# CXX=        clang++-3.9
# CXX=        clang++-4.0
CXX=        clang++-5.0
# CXX=        clang++-7
# CXX=	    g++-4.9
# CXX=	    g++-5
# CXX=	    g++-7.1 # hand-built
# CXX=	    g++-7
# CXX=        g++-8

%:	%.cpp
	${CXX} ${CXXFLAGS} -o $@ $?
