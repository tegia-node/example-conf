include ../../../Makefile.variable

# =============================================================================================================
#
# BUILD
#
# =============================================================================================================

example:
	@echo " "
	@echo "------------------------------------------------------------"
	@echo "EXAMPLE CONFIGURATION: \033[32;1m BUILD \033[0m"
	@echo "------------------------------------------------------------"
	@echo " "

	make libCONSOLE
	make libPHONE


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
	g++ -c -o PHONE.o                       ../src/actors/PHONE/PHONE.cpp                      $(Flag) -fPIC
	g++ -shared -fPIC -o libPHONE.so        \
	    PHONE.o -fPIC $(Flag)
