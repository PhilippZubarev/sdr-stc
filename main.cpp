#include "parser/parser.h"
using namespace std;

int main()
{
    Parser parser;
    parser.parse("primer.json");
    
    cout << "id" << parser.par.id << endl;
    cout << parser.par.bufferSize << endl;
    cout << parser.par.packageSize << endl;
    cout << parser.add << endl;

	return 0;
}
