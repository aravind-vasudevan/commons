#ifndef _COMMONS_HPP
#define _COMMONS_HPP

#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <vector>
#include <string>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <cmath>
#include <algorithm>

// Macro function for debug printing
#define _ENABLE_DEBUG0
// #define _ENABLE_DEBUG1
// #define _ENABLE_DEBUG2
// #define _ENABLE_DEBUG3
// #define _ENABLE_DEBUG4
// #define _ENABLE_DEBUG5

#ifdef _ENABLE_DEBUG0
	#define DEBUG0(x)	\
	{					\
		x; 				\
		fflush(stdout); \
	}
#else
	#define DEBUG0(x)
#endif

#ifdef _ENABLE_DEBUG1
	#define DEBUG1(x)	\
	{					\
		x; 				\
		fflush(stdout); \
	}
#else
	#define DEBUG1(x)
#endif

#ifdef _ENABLE_DEBUG2
	#define DEBUG2(x)	\
	{					\
		x; 				\
		fflush(stdout); \
	}
#else
	#define DEBUG2(x)
#endif

#ifdef _ENABLE_DEBUG3
	#define DEBUG3(x)	\
	{					\
		x; 				\
		fflush(stdout); \
	}
#else
	#define DEBUG3(x)
#endif

#ifdef _ENABLE_DEBUG4
	#define DEBUG4(x)	\
	{					\
		x; 				\
		fflush(stdout); \
	}
#else
	#define DEBUG4(x)
#endif

#ifdef _ENABLE_DEBUG5
#define DEBUG5(x)	\
{					\
	x; 				\
	fflush(stdout); \
}
#else
	#define DEBUG5(x)
#endif

using namespace std;

char* substr(const char* str, int start, int end);
bool fileExists(const char *filename);
double atod(const char* a);

class Commons
{
	public:

	int getdir( string directory, vector<string> &returnFiles );
};

class ConnectivityMatrix
{
	public:
	ConnectivityMatrix(int n);
	ConnectivityMatrix();
	std::vector < std::pair < int64_t, double > > list;
	int size();
	double& operator[] (int64_t);
	double& operator[] (int);
};

#endif