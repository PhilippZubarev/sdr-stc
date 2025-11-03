#include <gtest/gtest.h>
#include "message/message.h"

TEST(MessageTest,Creating){
    Messaging::Message testedObject;
    Messaging::Message testedObject(3,1,3);
}
