#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <iostream>
#include <nlohmann/json.hpp>
#include <fstream>
#include <cstdlib>
#include "transfer.h"



	class Parser {
	public:

		TransferParams par;
		size_t add;
		
		Parser parse(const std::string& filename);
		
	};

	


#endif
