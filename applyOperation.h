#pragma once

#include <map>
#include <string>
#include "Arguments.h"

typedef std::map<std::string,int> Dictionary;

void applyOperation(const Dictionary& words, Arguments::Operation op);