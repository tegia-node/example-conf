#!/bin/bash


# ////////////////////////////////////////////////////////////////////////////////
#
# VARIABLES
#
# ////////////////////////////////////////////////////////////////////////////////


RED=`tput setaf 1`
GREEN=`tput setaf 2`
RESET=`tput sgr0`

_OK_="${GREEN}[OK]  ${RESET}"
_ERR_="${RED}[ERR] ${RESET}"


# ////////////////////////////////////////////////////////////////////////////////
#
# VENDORS
#
# ////////////////////////////////////////////////////////////////////////////////



# ////////////////////////////////////////////////////////////////////////////////
#
# BUILD
#
# ////////////////////////////////////////////////////////////////////////////////

make

exit 0
