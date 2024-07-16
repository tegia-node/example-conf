include ../../../Makefile.variable

# =============================================================================================================
#
# BUILD
#
# =============================================================================================================

example:
	@echo " "
	@echo "------------------------------------------------------------"
	@echo "APP EXAMPLE CONFIGURATION: \033[32;1m BUILD \033[0m"
	@echo "------------------------------------------------------------"
	@echo " "

	make libCONSOLE
	make libPHONE

#	make libDATASETS

#	make libTEST2
#	make libRANDOM

# =============================================================================================================
#
# BUILD ACTORS
#
# =============================================================================================================


libCONSOLE:
	g++ -c -o CONSOLE.o                     ../src/actors/CONSOLE/CONSOLE.cpp                $(Flag) -fPIC
	g++ -shared -fPIC -o libCONSOLE.so        \
	    CONSOLE.o -fPIC $(Flag)

libPHONE:
	g++ -c -o PHONE.o                     ../src/actors/PHONE/PHONE.cpp                      $(Flag) -fPIC
	g++ -c -o state.o                     ../src/actors/PHONE/state/state.cpp                $(Flag) -fPIC
	g++ -shared -fPIC -o libPHONE.so        \
	    PHONE.o state.o -fPIC $(Flag)






libTEST:
	g++ -c -o TEST.o                     ../src/actors/TEST/TEST.cpp                $(Flag) -fPIC
	g++ -shared -fPIC -o libTEST.so        \
	    TEST.o -fPIC $(Flag)


libDATASETS:
	g++ -c -o DATASETS.o                     ../src/actors/DATASETS/DATASETS.cpp                $(Flag) -fPIC
	g++ -shared -fPIC -o libDATASETS.so        \
	    DATASETS.o -fPIC $(Flag)


libTEST2:
	g++ -c -o TEST2.o                     ../src/actors/TEST2/TEST2.cpp                $(Flag) -fPIC
	g++ -shared -fPIC -o libTEST2.so        \
	    TEST2.o -fPIC $(Flag)


libRANDOM:
	g++ -c -o RANDOM.o                     ../src/actors/RANDOM/RANDOM.cpp                $(Flag) -fPIC
	g++ -shared -fPIC -o libRANDOM.so        \
	    RANDOM.o -fPIC $(Flag)

