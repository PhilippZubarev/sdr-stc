#include <gtest/gtest.h>
#include "parser/parser.h"


TEST(ParserTests, Creating) {
	Parser testedObject;
}

TEST(ParserTests, RightParseId){
	Parser prim;
	prim = prim.parse("primer.json");
	size_t t = 1;
	ASSERT_EQ(prim.par.id,t);
}
TEST(ParserTests, RightParseType){
	Parser prim;
	prim = prim.parse("primer.json");
	ASSERT_EQ(prim.par.type,TransferParams::Type::loop);
}
TEST(ParserTests, RightParseBuffSize){
	Parser prim;
	prim = prim.parse("primer.json");
	size_t t = 10;
	ASSERT_EQ(prim.par.bufferSize,t);
}

TEST(ParserTests, RightParsePackageSize){
	Parser prim;
	prim = prim.parse("primer.json");
	size_t t = 5;
	ASSERT_EQ(prim.par.packageSize,t);
}

TEST(ParserTests, RightParseTime){
	Parser prim;
	prim = prim.parse("primer.json");
	size_t t = 1;
	ASSERT_EQ(prim.add,t);
}

TEST(ParserTests, WrongName){
	Parser prim;
	prim = prim.parse("wromg");
}