#ifndef _DEF_H_
#define _DEF_H_

#include <string>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <vector>
#include <sys/types.h> 
#include <sys/stat.h> 
#include <math.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <ctype.h> 
#include <sstream>
#include <set>
#include <memory>
#include <typeinfo>

struct entry {
	std::string a;
	std::string b;
	int overlap;
};

bool operator== (entry& lhs, entry& rhs) {
	if ((lhs.a == rhs.a && lhs.b == rhs.b) || (lhs.a == rhs.b && lhs.b == rhs.a)) return true;
	else return false;
}

struct overlap {
	std::string read;
	std::string ref;
	int start, end;
};

bool operator< (const entry& lhs, const entry& rhs)
{ return lhs.overlap < rhs.overlap; }

struct classcom {
	bool operator() (const entry& lhs, const entry& rhs) const
	{ return lhs.overlap < rhs.overlap; }
};

std::vector<std::string> split (const std::string &s, char delim)
{
	std::vector<std::string> result;
	std::stringstream ss (s);
	std::string item;

	while (std::getline (ss, item, delim))
	{
		result.push_back (item);
	}

	return result;
}

#endif