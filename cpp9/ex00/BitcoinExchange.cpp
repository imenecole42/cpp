#include "BitcoinExchange.hpp"
#include <string>
Btc::Btc(){}
Btc::Btc(const Btc &cpy){*this=cpy;}
Btc &Btc ::operator=(const Btc &cpy)
{
    if(this != &cpy)
        *this=cpy;
    return *this;
}
Btc::~Btc(){}
bool Btc::isvaliddate(const std::string&date)
{
    if (date.size() > 10)
    {
        return false;
    }
    if((date[4] !='-') || (date[7] != '-'))
    {
        return false;
    }
    std::string str1=date.substr(0,4);
    std::string str2=date.substr(5,2);
    std::string str3=date.substr(8,2);
    for (int i = 0; i < 10; ++i)
    { 
        if (std::isdigit(str1[i]) && std::isdigit(str2[i]) && std::isdigit(str3[i]))  
            return true;
        else
            return false;
    }
    int year= std::atoi(str1.c_str());
    int month= std::atoi(str2.c_str());
    int day= std::atoi(str3.c_str());
    int maxDay = 31; 
    if (month == 4 || month == 6 || month == 9 || month == 11) 
        maxDay = 30;
    else if (month == 2)
    {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        maxDay = 29;
    else 
        maxDay = 28;
    if((month > 12) ||(month < 1) ||(day < 1) || (day > maxDay) ||(year < 1))
        return false;
    }
    return true;
}
Btc::dataBase Btc::parse_date(const std::string& fd)
{
    dataBase data;
    std::ifstream file(fd.c_str());
    if (!file.is_open()) {
        std::cerr << "Erreur : Impossible d'ouvrir le fichier de la base de données." << std::endl;
    }
    std::string Ligne;
    std::getline(file, Ligne);
    std::string line;
    while (std::getline(file, line)) {
        size_t pos = line.find(",");
        if (pos != std::string::npos)
        {
            std::string date = line.substr(0, pos);
            float value = std::atof(line.substr(pos + 1).c_str());
            data[date] = value;
        }
    }
    file.close();
    return data;
} 

float Btc::lookupValue(const dataBase& data, const std::string& date) {
    dataBase::const_iterator it = data.find(date);
    if (it != data.end()) {
        return it->second;
    } 
    else {
        dataBase::const_iterator prevIt = data.lower_bound(date);
        if (prevIt != data.begin()) {
            --prevIt;
            return prevIt->second;
        } 
        else 
        {
            //std::cout << "Erreur : Date non trouvée et aucune valeur précédente disponible pour " << date << std::endl;
            return -9999999.0;
        }
    }
}
