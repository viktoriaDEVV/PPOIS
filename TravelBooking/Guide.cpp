#include "Guide.h"

string Guide::getGuideInfo() const {
        return "Guide Name: " + name + "\n" +
               "Language: " + language + "\n" +
               "Fee: $" + to_string(fee);
    }
Guide::Guide(const string& guideName, const string& guideLanguage, double guideFee)
        : name(guideName), language(guideLanguage), fee(guideFee) {}