#include <iostream>
#include <string>
#include <fstream>
#include <sys/stat.h>
#include <vector>
#include <boost/regex.hpp>
#include <boost/filesystem.hpp>
#include <cmath>
using namespace std;
void makefolder(string,string);
int main(){
	string pathprefix;
	vector<string> path;
	string password;
	cout<<"Please enter password pattern, and press enter."<<endl;
	cout<<"For example, 123456 or abcde"<<endl;
	getline(cin,password);
	int total_level;
	total_level = password.size();
	//start generating path array
	//stop at all levels have been reached
	string cwd = boost::filesystem::current_path().generic_string();	
	int totalFolder;
	totalFolder = (total_level*(1-pow(total_level,total_level)))
			/(1-total_level);
	cout<< "that is "<< totalFolder<<" folders, do you want to proceed? [n/y]"<<endl;
	string answer;
	cin>> answer;
	if (answer != "y"){ return 0;};
	cout<<"Please enter number of layers you want to apply."<<endl;
	cout<<"Total possbile layers are "<< password.size()<<endl;
	cin>> answer;
	if(!isdigit(answer[0])){ return 0;};
	int layer = atoi(answer.c_str())-1;
	
	cout<<"Do you want to print folder log? [y/n]"<<endl;
	cin>>answer;
	bool print = false;
	if (answer == "y"){print = true;};

	cout<<"please type your contact numbers here:"<<endl;
	cin>>answer;
	string msg = "pls contact "+answer;
	mkdir(msg.c_str(),0777);
	

	cout<<"creating folders"<<endl;
	mkdir("DirPassword",0777);
	//now path prefix
	pathprefix = cwd + "/DirPassword";
	//first level
	makefolder(pathprefix,password);
	//second level
	string cdir;
	for (int i = 0; i < total_level; ++i){	
		//check layers
		if(layer < 1){break;};
		cdir = pathprefix + "/"+password[i];
		if(print){cout<<"i= "<<i<<cdir<<endl;}
		makefolder(cdir,password);
		for (int j=0; j<total_level;++j){
			if(layer<2){break;};
			cdir = pathprefix + "/"+password[i]+"/"+password[j];
			if(print){cout<<"j=  "<<j<<"  "<<cdir<<endl;}
			makefolder(cdir,password);	
			//check if this is final root
			for (int k=0; k<total_level;++k){
				if(layer<3){break;};
				cdir = pathprefix + "/"+password[i]+"/"+password[j]+"/"+password[k];
				if(print){cout<<"k= "<<k<<" " <<cdir<<endl;}
				makefolder(cdir,password);	
				for (int l=0; l<total_level;++l){
					if(layer<4){break;};
					cdir = pathprefix + "/"+password[i]+"/"+password[j]+"/"+password[k]+ "/"
						+password[l];
					if(print){cout<<"l= "<<l<<" " <<cdir<<endl;}
					makefolder(cdir,password);	
	for (int m=0; m<total_level;++m){
		if(layer<5){break;};
		cdir = pathprefix + "/"+password[i]+"/"+password[j]+"/"+password[k]+ "/"
			+password[l]+ "/"+password[m];
		if(print){cout<<"m= "<<m<<" " <<cdir<<endl;}
		makefolder(cdir,password);	
		for (int n=0; n<total_level;++n){
			if(layer<6){break;};
			cdir = pathprefix + "/"+password[i]+"/"+password[j]+"/"+password[k]+ "/"
				+password[l]+ "/"+password[m]+ "/"+password[n];
			if(print){cout<<"n= "<<n<<" " <<cdir<<endl;}
			makefolder(cdir,password);	
			for (int o=0; o<total_level;++o){
				if(layer<7){break;};
					cdir = pathprefix + "/"+password[i]+"/"+password[j]+"/"+password[k]+ "/"
						+password[l]+ "/"+password[m]+ "/"+password[n]+ "/"+password[o];
				if(print){cout<<"o= "<<o<<" " <<cdir<<endl;}
				makefolder(cdir,password);	
				for (int p=0; p<total_level;++p){
					if(layer<8){break;};
						cdir = pathprefix + "/"+password[i]+"/"+password[j]+"/"+password[k]+ "/"
							+password[l]+ "/"+password[m]+ "/"+password[n]+ "/"+password[o]+"/"
							+password[p];
					if(print){cout<<"p= "<<p<<" " <<cdir<<endl;}
					makefolder(cdir,password);	
				}
			}
		}
	}
				}
			}
		}
	}	
	cout<<"Done."<<endl;
	return 0;

}
void makefolder(string path,string password){
	string folderDir;	
	for (int i = 0; i<password.size();++i){
		folderDir = "";
		folderDir = path+"/"+password[i];
		//cout<<"make folder " <<folderDir<<endl;
		mkdir(folderDir.c_str(), 0777);
	}	
}








