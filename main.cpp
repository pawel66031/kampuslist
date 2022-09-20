#include <curl/curl.h>
// #include <jsoncpp/json/json.h>
#if __has_include(<jsoncpp/json/json.h>)
	#include <jsoncpp/json/json.h>
#else
	#include <json/json.h>
#endif

// #include <ctime>
#include <chrono>
#include <string>
#include <iostream>
#include <locale>

// #include <wx-3.0/wx/wx.h>

#include "src/gui/Window.hpp"
#include "src/ArgumentsHandler.hpp"
#include "Timer.hpp"

#define API_WEB_PAGE "https://api.radiokampus.fm/playlista"

size_t writeFunction(void *ptr, size_t size, size_t nmemb, std::string* data) {
    data->append((char*) ptr, size * nmemb);
    return size * nmemb;
}

// std::string UsageInfo(){
// 	return 
// 	"Usage: kampuslist [OPTIONS]\n"
// 	"\n"
// 	"-y\tDisplay track list played yesterday\n";
// }


int main(int argc, char* argv[]){
	if (argc >= 2){
		ArgumentHandler::ReadArguments(argc, argv);
	}

	// Window* window = new Window;
	// window->OnInit();

	struct curl_slist *headers = NULL;
	headers = curl_slist_append(headers, "Accept: application/json");
	headers = curl_slist_append(headers, "Origin: https://radiokampus.fm");

	Timer timer;

	// std::string date = "/?day=20220401";
	std::string date = "/?day=" + timer.GetDate();

	CURL* curl = curl_easy_init();
	if(curl){
		const std::string link = API_WEB_PAGE;
		// std::string date = API_DATE;

		curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
		curl_easy_setopt(curl, CURLOPT_URL, (link + date).c_str());

		curl_easy_setopt(curl, CURLOPT_MAXREDIRS, 2L);

		// std::string header_string;
		std::string trackLists;
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeFunction);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &trackLists);

		long response_code;
		curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);

		curl_easy_perform(curl);

		if(response_code == CURLE_OK){
			Json::Value json;
			Json::Reader reader;

			bool parseChecker = reader.parse(trackLists, json);

			if(!parseChecker){
				std::cout << "Error parsing the string" << std::endl;
				return 1;
			}

			std::cout << "Radio Kampus - utwory (" << timer.GetDay() << "." << timer.GetMonth() << "." << timer.GetYear() << ")\n"
					  << "-------------------------------------------" << '\n';

			for(auto i = 0; i < json.size(); ++i){
				std::string artist = json[i]["artist"].asString();
				std::string title = json[i]["title"].asString();

				std::cout << json[i]["start_time"].asString() + "\t" + artist + " - " + title << '\n';
			}

			curl_easy_cleanup(curl);
			curl = NULL;
		} else {
			std::cout << response_code << '\n';
			std::cerr << "Getting playlist error!" << std::endl;
		}
	}
	
	return 0;
}
