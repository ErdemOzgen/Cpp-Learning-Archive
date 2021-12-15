
CXXFLAGS+=  -std=c++2a
# MFLAGS+=  -fmodules # probably surplus with C++20
MFLAGS+= -fmodules-ts
# MFLAGS+=  -fmodule-map-file=dmc_modules.map
# MFLAGS+=  -fprebuilt-module-path=.
# MFLAGS+=  -fimplicit-modules
CXXFLAGS+=  ${MFLAGS}
# CXXFLAGS+=  -I. 
# OPTFLAGS+=  -O3 -DNDEBUG
#OPTFLAGS +=  -g -O0 # -Wno-long-double
CXXFLAGS+=  ${OPTFLAGS}
CXXFLAGS+=    -pedantic
CXXFLAGS+=    -Wall
# CXXFLAGS+=    -Weverything


# CXX=   clang++-8
# CXX=   clang++-9
CXX=   clang++-10

# PCM_TARGET=	$(shell ls *.ixx | sed -e 's/\.pcm//')	
# MAIN_TARGETS=	$(shell ls *.cpp | sed -e 's/\.cpp//')
# 	
# all:	${PCM_TARGETS} ${MAIN_TARGETS}	
# all:	${MAIN_TARGETS}	
# all:	math_app vector_from_module # doesn't compile with clang++-10
all:	math_app 

clean:
	rm -f ${MAIN_TARGETS} *.o *.pcm



%.pcm:	%.cppm
	${CXX} -std=c++2a ${MFLAGS} --precompile -o $@ $?
	
# %.o:	%.pcm
# 	${CXX} -std=c++2a ${MFLAGS} ${OPTFLAGS} -c -o $@ $?
# 	
# %.o:	%.cpp
# 	${CXX} -std=c++2a ${MFLAGS} ${OPTFLAGS} -c -o $@ $?
	
math.pcm:	math.cppm math_extra.pcm
	${CXX} -std=c++2a ${MFLAGS} -fmodule-file=math_extra.pcm --precompile -o $@ $<
	
math.o:	math.cpp math.pcm
	${CXX} -std=c++2a ${MFLAGS} -fmodule-file=math.pcm -c -o $@ $<
	
# math_extra.o:	math_extra.cpp math_extra.pcm
# 	${CXX} -std=c++2a ${MFLAGS} -fmodule-file=math_extra.pcm -c -o $@ $<
	
	
vector_from_generated_module:	vector_from_generated_module.cpp
	${CXX} ${CXXFLAGS} -o $@ $? -fmodule-map-file=dmc_modules.map -fimplicit-modules
	
vector_from_module:	vector_from_module.cpp vector.pcm 
	${CXX} -std=c++2a ${MFLAGS} ${OPTFLAGS} -fmodule-file=vector.pcm -o $@ $<

# vector_from_module:	vector_from_module.cpp 
# 	${CXX} -std=c++2a ${MFLAGS} ${OPTFLAGS} -o $@ $?

math_app:	math.o math_app.cpp
	${CXX} -std=c++2a ${MFLAGS} -fprebuilt-module-path=. -o $@ $+


	
# %:	%.cpp
# 	${CXX} ${CXXFLAGS} -o $@ $?
