#include <iostream>
#include <map>
#include <string>

#ifndef LOCAL_STRINGS_HPP
#define LOCAL_STRINGS_HPP
                                                     

std::map<std::string, std::map<std::string, std::string>> translations = {
    {"STRING_LEVEL", {
        {"en", "How hard should the equations be?\n"},
        {"de", "Wie schwer sollten die Aufgaben sein?\n"}
    }},
    {"STRING_ERROR", {
        {"en", "Something doesn't seem to work out..."},
        {"de", "Irgendetwas scheint nicht zu funktionieren..."}
    }},
    {"STRING_RETRIEVING", {
        {"en", "Type outcome of "},
        {"de", "Berechne das Ergebnis von "}
    }},
    {"STRING_POSITIVFEEDBACK", {
        {"en", "Great! You rock."},
        {"de", "Super! Du rockst."}
    }},
    {"STRING_BEFOREEXIT", {
        {"en", "Exiting..."},
        {"de", "Das Programm wird geschlossen..."}
    }},
    {"STRING_TRYHARD1", {
        {"en", "\aIt is "},
        {"de", "\aEs ist "}
    }},
    {"STRING_TRYHARD2", {
        {"en", "; try harder next time! 'X' to quit ...\n"},
        {"de", "; Streng dich das naechste Mal mehr an! 'X' zum Beenden ...\n"}
    }}
};
namespace localization {

    // Funktion zum Abrufen der Übersetzung
    std::string getTranslation(const std::string& key, const std::string& language) {
        // Überprüfen, ob der Schlüssel und die Sprache vorhanden sind
        if (translations.find(key) != translations.end() && translations[key].find(language) != translations[key].end()) {
            return translations[key][language];
        }
        return "Translation not found";
    }

}
#endif