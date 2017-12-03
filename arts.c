#include <stdio.h>
#include "arts.h"

void print_ArtMenu() {

	printf("\
	  sSSSs   d s.   d s   sb d sss          sSSSs   d sss  \n\
	 S     S  S  ~O  S  S S S S             S  |  S  S      \n\
	S         S   `b S   S  S S            S   |   S S      \n\
	S         S sSSO S      S S sSSs       S   |   S SsSS   \n\
	S    ssSb S    O S      S S            S   |   S S      \n\
	 S     S  S    O S      S S             S  |  S  S      \n\
	  sssss   P    P P      P P sSSss        sssss   P      \n\
	                                                        \n\
	sss sssss d    d d ss.    sSSSs   d s  b d sss     sss. \n\
	    S     S    S S    b  S  |   S  S  S S S       d     \n\
	    S     S    S S    P S   |   S S   SS S       Y      \n\
	    S     S sSSS S sS'  S   |   S S    S S sSSs    ss.  \n\
	    S     S    S S   S  S   |   S S    S S            b \n\
	    S     S    S S    S  S  |  S  S    S S            P \n\
	    P     P    P P    P   sssss   P    P P sSSss ` ss'  \n\n");

}

void print_ArtWin() {

	printf("\
    #   #   ####   #    #      #    #  #  #    # \n\
     # #   #    #  #    #      #    #  #  ##   # \n\
      #    #    #  #    #      # ## #  #  #  # # \n\
      #    #    #  #    #      ##  ##  #  #   ## \n\
      #     ####    ####       #    #  #  #    # \n");                                          

}

void print_ArtLose() {

	printf("\
    #   #   ####   #    #      #        ####    ####   ###### \n\
     # #   #    #  #    #      #       #    #  #       #      \n\
      #    #    #  #    #      #       #    #   ####   #####  \n\
      #    #    #  #    #      #       #    #       #  #      \n\
      #     ####    ####       ######   ####    ####   ###### \n");

}