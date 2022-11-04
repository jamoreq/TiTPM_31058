#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>

using namespace std;
vector<float> ab;

void write
(vector<char> a, map<char, float> mappin, string wiadomosc, int licz, float Wartosca){
    cout<<endl;
    if(licz<wiadomosc.length()){
        if(licz == 0){
    	    for(int i=0; i<a.size(); i++) {
			 cout<<mappin.find(a[i])->first <<" -> " 
			 <<mappin.find(a[i])->second<<endl;
    	    }
        }
    	float abc; float temp_mappin = Wartosca;
    	for(int i=0; i<a.size(); i++){
        	cout<< "[" << temp_mappin << ";" 
			<< temp_mappin + (mappin.find(a[i])->second)<<")"<<endl;
        	if(wiadomosc[licz] == mappin.find(a[i])->first){
        	    abc = mappin.find(a[i])->second; Wartosca = temp_mappin;	   
        	}
        temp_mappin += mappin.find(a[i])->second;
    	} }	}

int main(){
    string wiadomosc,
	wiadomosc_temp;
    cout<<"Podaj wiadomosc do zakodowania:"<<endl;
    cin>>wiadomosc; 
	wiadomosc_temp = wiadomosc;
    sort(wiadomosc_temp.begin(), wiadomosc_temp.end());
    
    map<char, float> mappin; vector<char> a;
    
    char znak = wiadomosc_temp[0]; int counter = 0;
    
    for(int i=0; i<wiadomosc_temp.length(); i++){ 
        if(i == wiadomosc_temp.length()-1 && znak != wiadomosc_temp[i]){
            mappin.insert(pair<char,float>(znak, 
			float(counter)/float(wiadomosc.length())));
            a.push_back(znak);
            ab.push_back(float(counter)/float(wiadomosc.length()));
            
            mappin.insert(pair<char,float>(wiadomosc_temp[i],
			float(1)/float(wiadomosc.length())));
            a.push_back(wiadomosc_temp[i]);
            ab.push_back(float(counter)/float(wiadomosc.length()));
            break;} 
			    
        if(znak != wiadomosc_temp[i] || i == wiadomosc_temp.length()-1){
            if(i == wiadomosc_temp.length()-1) counter++;
            mappin.insert(pair<char,float>(znak, 
			float(counter)/float(wiadomosc.length())));
            a.push_back(znak);
            ab.push_back(float(counter)/float(wiadomosc.length()));
            
            counter = 0; znak =wiadomosc_temp[i];
        }
        counter++;
    } 
	write(a, mappin, wiadomosc, 0, 0);
    return 0;
}
