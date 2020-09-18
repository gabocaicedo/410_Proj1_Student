/***
 * KP Utils
 */
#include <numeric>
#include <math.h>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "utilities.h"
#include "stdlib.h"

using namespace std;
std::vector<process_stats> myvector;

//test for push #2

//********************** private to this compilation unit **********************

//if myString does not contain a string rep of number returns o
//if int not large enough has undefined behaviour, very fragile
int stringToInt(const char *myString) {
	return atoi(myString);
}

int loadData(const char* filename, bool ignoreFirstRow) {

	//clear vector for inputing preocess_stat structs
	myvector.clear();

	fstream fileReader("filename");
	if(!fileReader.is_open()){
		return COULD_NOT_OPEN_FILE;
	}
	
	
	string pn, st, ct, it;
	string myString, line;
	process_stats data;

	
	
	while(getline(fileReader, line)){

		if(line.empty()){
			break;
		}
		if(ignoreFirstRow){
			fileReader.ignore(1,'\n');
		}
		else
		{
		stringstream ss(line);

		if(line.length() != 0){
		getline(ss, pn, CHAR_TO_SEARCH_FOR);
		}else { break; } 
		
		if(line.length() != 0){
		getline(ss, st, CHAR_TO_SEARCH_FOR);
		}else { break; } 

		if(line.length() != 0){
		getline(ss, ct, CHAR_TO_SEARCH_FOR);
		}else { break; } 

		if(line.length() != 0){
		getline(ss, it, CHAR_TO_SEARCH_FOR);
		}else { break; } 


		data.process_number = stoi(pn);
		data.start_time = stoi(st);
		data.cpu_time = stoi(ct);
		data.io_time = stoi(it);

		myvector.push_back(data);
	}
	}
	//int i = 0;
	// while(! fileReader.eof()){
	// 	fileReader >> pn >> st >> ct >> it;

	// 	process_stats[i].process_number = pn;
	// 	process_stats[i] = pn;
	// 	process_stats[i] = pn;
	// 	process_stats[i] = pn;
	// }
	// 	if(ignoreFirstRow == true){

	// 	}

	// 	process_stats row{}
	// }


	return SUCCESS;
}


//will sort according to user preference
void sortData(SORT_ORDER mySortOrder) {

}

process_stats getNext() {
	process_stats myFirst;

	return myFirst;
}

//returns number of process_stats structs in the vector holding them
int getNumbRows(){
	return 0;
}


