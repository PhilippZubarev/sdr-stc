#include "parser/parser.h"

using json = nlohmann::json;

Parser Parser::parse(const std::string& filename){
	Parser res; //Переменная с результатом
	std::ifstream file (filename); //Чтение файла
	if (!file.is_open()){ //Проверка на ошибку
		std::cout << "File didn't open" << std::endl;
		exit(1);
	}
	json j;
	file >> j; //Запись файла в переменную для парсинга
	
		res.par.id = j["TransferParams"]["id"].get<std::size_t>();
		if (j["TransferParams"]["Type"].get<std::size_t>() == 0) res.par.type = TransferParams::Type::single;
		else if (j["TransferParams"]["Type"].get<std::size_t>() == 1) res.par.type = TransferParams::Type::loop;
		else {std::cout << "Wrong type" << std::endl; exit(2);}
		res.par.bufferSize = j["TransferParams"]["BufferSize"].get<std::size_t>();
		res.par.packageSize = j["TransferParams"]["PackageSize"].get<std::size_t>();

		res.add = j["AdditionalParams"]["time"].get<std::size_t>();
	
	
	return res;
}

