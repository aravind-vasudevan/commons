#ifndef _COMMONS_CPP
#define _COMMONS_CPP

#include "Commons.hpp"

int
Commons::getdir( string directory, vector<string> &returnFiles )
{
	DIR *directoryPointer;
    struct dirent *entries;
    if((directoryPointer  = opendir(directory.c_str())) == NULL)
	{
        cout << "Error(" << errno << ") opening " << directory << endl;
        return errno;
    }

    while ((entries = readdir(directoryPointer)) != NULL)
        returnFiles.push_back(string(entries->d_name));

    closedir(directoryPointer);
    return 0;
}

double&
ConnectivityMatrix::operator [] (int x)
{
	int size = list.size(), i=0;
	for(; i<size; ++i)
		if( list[i].first == x )
			return list[i].second;
	cout<<"lists contents : ";
	cout<<"\nstats : list.size="<<list.size()<<" x = "<<x;
	for(i=0; i<size; ++i)
		cout<<"\t"<<list[i].first;
	cout<<"\nLooks like you are trying to do some unwanted access(accessing connectivityMatrix through array indices, for some particular connection that doesn't exist. Exiting now!)";
	exit(0);
}

double&
ConnectivityMatrix::operator [] (int64_t x)
{
	int size = list.size(), i=0;
	for(; i<size; ++i)
		if( list[i].first == x )
			return list[i].second;
	
	cout<<"\nstats : list.size="<<list.size()<<" x = "<<x;
	cout<<"lists contents : ";
	for(i=0; i<size; ++i)
		cout<<list[i].first<<"\t";
	cout<<"\nLooks like you are trying to do some unwanted access(accessing connectivityMatrix through array indices, for some particular connection that doesn't exist. Exiting now!)";
	exit(0);
}

ConnectivityMatrix::ConnectivityMatrix(int n)
{
	for(int i=0; i<n; ++i)
	{
		pair < int64_t, double > temp;
		temp.first = 0;
		temp.second = 0;
		list.push_back(temp);
	}
}

ConnectivityMatrix::ConnectivityMatrix()
{
}

int
ConnectivityMatrix::size()
{
	return list.size();
}

#endif

// testing from source blah
// testing from SA
// testing from Noise
