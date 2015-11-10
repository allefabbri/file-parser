// FILE-PARSER
// Copyright 2015,  Stefano Sinigardi and Alessandro Fabbri
// for any question, please mail rommacc@yahoo.it

/************************************************************************
* This program is free software: you can redistribute it and/or modify  *
* it under the terms of the GNU General Public License as published by  *
* the Free Software Foundation, either version 3 of the License, or     *
* (at your option) any later version.                                   *
*                                                                       *
* This program is distributed in the hope that it will be useful,       *
* but WITHOUT ANY WARRANTY; without even the implied warranty of        *
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
* GNU General Public License for more details.                          *
*                                                                       *
* You should have received a copy of the GNU General Public License     *
* along with this program.  If not, see <http://www.gnu.org/licenses/>. *
************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "file_parser.h"

#define SEPARATORS       " \t=,"
#define COMMENTS         "#/!;"

int main(){
	std::cout << "*********** FILE PARSER ***********" << std::endl;
  
	std::vector< std::vector<std::string> > parsed_file = Parse_file("config.conf",SEPARATORS,COMMENTS);

    std::cout << "PARSER: parsed size is " << parsed_file.size() << std::endl;
	  for( auto p : parsed_file ){
	  	std::cout << "PARSER: ";
	  	for(auto s : p){
	  		std::cout  << s << " ";
	  	}
	  	std::cout << std::endl;
	  }

	return 0;
}
