#ifndef _COMMONS_CPP
#define _COMMONS_CPP

#include "Commons.hpp"

bool
fileExists(const char *filename)
{
  ifstream ifile(filename);
  return ifile;
}

char* 
substr(const char* str, int start, int end)
{
	char* a = new char[1+(end-start)]; 
	for(int i=start; i<end; i++) 
		a[i-start] = str[i]; 
	a[end-start] = '\0'; 
	return a;
}

double
atod(const char* a)
{
	double retVal = atoi(a);
	//cout<<"\ngangnam : "<<" ip= "<<a<<" retVal = "<<retVal;
	int start = 0;
	int end = 0;
	for(int i=0; a[i] != '\0'; i++){ 
		if(a[i] == '.' && start == 0){
			start = i+1; 
			end = i+1;
		}
		else if(start != 0)
			end = i+1;
			
/*		else if(start != 0 &&  (a[i] < '0' || a[i] > '9')){ 
			end = i; 
			break; 
		}*/
	}
	if(end > start){ 
		char* decimal = substr(a, start, end); 
		//cout<<" decimal  = "<<decimal;
		int dec = atoi(decimal); 
		int power = end-start; 
		retVal += ((double)dec)/(pow(10.0, (double)power)); 
	}
//	cout<<"\ngangnam : "<<" ip= "<<a<<" retVal = "<<retVal;
	return retVal;
}


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
    vector <string> excludeStrings;
    excludeStrings.push_back(string("."));
    excludeStrings.push_back(string(".."));

    while ((entries = readdir(directoryPointer)) != NULL)
    {
    	if(find(excludeStrings.begin(), excludeStrings.end(), string(entries->d_name)) == excludeStrings.end())
        returnFiles.push_back(string(entries->d_name));
	}

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
