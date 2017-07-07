#include "Field.h"

Field::Field(std::shared_ptr<Bone> first_double)
{
    head = std::make_shared<node>();
    head->bone = first_double;
}
