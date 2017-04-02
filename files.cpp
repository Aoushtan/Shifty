#ifdef WINDOWS
#include <atlstr.h>
#else
#include <dirent.h>
#endif
#include <string>
#include <iostream>
#include <vector>

using namespace std;

void GetFilesInDirectory(std::vector<string> &out, const string &directory){
	#ifdef WINDOWS
		HANDLE dir;
		WIN32_FIND_DATA file_data;

		if ((dir = FindFirstFile((directory + "/*").c_str(), &file_data)) == INVALID_HANDLE_VALUE)
		    return; /* No files found */

		do {
		    const string file_name = file_data.cFileName;

			if(file_name[0] != '.')
			    out.push_back(file_name);
		} while (FindNextFile(dir, &file_data));

		FindClose(dir);
	#else
		DIR *dir;
		struct dirent *ent;
		
		dir = opendir(directory.c_str());
		while ((ent = readdir(dir)) != NULL) {
			const string file_name = ent->d_name;

			if(file_name[0] != '.')
		    	out.push_back(file_name);
		}
		closedir(dir);
	#endif
}

int main(){
	std::vector<string> audio_files;
	
	GetFilesInDirectory(audio_files, "Audio");
	
	for(int i = 0; i < audio_files.size(); i++){
		cout << audio_files[i] << endl;
	}
	
	return 0;
}
