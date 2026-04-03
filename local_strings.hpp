#pragma once
#include <string>

namespace localization {
    std::string getSystemLanguage();
    std::string determineSystemLanguage();
    std::string getTranslation(const std::string& key, const std::string& language); 
}