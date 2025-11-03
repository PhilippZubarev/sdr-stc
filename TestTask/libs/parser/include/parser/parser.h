#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <iostream>
#include <cstdint>
#include <vector>
/**
 * namespace Printing предполагает что в этойм пространстве имён кроме данного класса будет что-то ещё, касающееся принтеров,
 *  например, логика, связывающее каким-то образом взаимодействие принтеров
 */
namespace Parsing {

	class Parser {
	public:

		Parser();
		~Parser();
	private:
		uint32_t id;

		uint32_t time;
	};
}

#endif
