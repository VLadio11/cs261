#include "Field.h"

Field::Field(): head(nullptr) {}

Field::~Field()
{
    delete head;
}