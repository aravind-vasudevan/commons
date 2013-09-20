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

#define _MASTER 0
#define _SLAVE 1

using namespace std;

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
