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

// Standard includes
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>    // due to exit()

// Boost includes
#include <boost/algorithm/string.hpp> 

// Local includes
#include "file_parser.h"

bool Belongs_to(char c, std::string s){
  for (int i = 0; i < s.size(); i++){ if (c == s.at(i)) return true; }
  return false;
}

std::vector< std::vector<std::string> > Parse_file(std::string file_name, std::string separators, std::string comment){
// Safe file opening
	std::ifstream file_to_parse(file_name, std::ios::in);
	if( !file_to_parse ){ 
		std::cout << "Cannot open " << file_name << ". Quitting..." << std::endl;
		exit(12);
	}
// Internal variables
	std::string line;
	std::vector<std::string> tokens;
    std::vector< std::vector<std::string> > parsed;
// Parsing loop
	while ( getline(file_to_parse, line) ){
	  boost::algorithm::trim(line);  // remove leading/trailing spaces
	  if( !line.size() ) continue;   // ignore empty lines
	  boost::algorithm::split(tokens, line, boost::algorithm::is_any_of(separators), boost::token_compress_on);  // split line to tokens, BOOST required
	  std::transform(tokens[0].begin(), tokens[0].end(), tokens[0].begin(), ::tolower);  // convert to lower, NOT UTF-8 compatible
	  for(int i=0; i<tokens.size(); i++){  // remove inline comments
	  	if( Belongs_to(tokens[i][0],comment) ){ tokens.erase( tokens.begin()+i, tokens.end()); }  
	  }
	  if( tokens.size() ){  // ignore empty tokens
	  	parsed.push_back( tokens );
	  }
	  line.clear(); tokens.clear(); 
	}
	file_to_parse.close();
	return parsed;
}
