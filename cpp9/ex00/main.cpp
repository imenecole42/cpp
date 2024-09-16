#include "BitcoinExchange.hpp"
int main(int argc,char **argv)
{
    if(argc !=2)
    {
        std::cout<<"Error: could not open file."<<std::endl;
        return 0;
    };
    Btc b;
    Btc::dataBase data = b.parse_date("data.csv");
    std::ifstream file(argv[1]);
    if (!file.is_open()) {
        std::cout<<"Error: could not open file."<<std::endl;
        return 0;
    }
    std::string Ligne;
    std::getline(file, Ligne);
    std::string line;
    while (std::getline(file, line)) {
        size_t pos = line.find(" | ");
        if (pos != std::string::npos) 
        {
            std::string date = line.substr(0, pos);
            float inputValue = std::atof(line.substr(pos + 3).c_str());
            float dataValue = b.lookupValue(data, date);
            float result = dataValue * inputValue;
            if(b.isvaliddate(date)==false)
              std::cout<<"date non valid"<<std::endl;
            else if(dataValue== -9999999.0)
                std::cout << "Erreur : Date non trouvée et aucune valeur précédente disponible pour " << date << std::endl;
            else if(inputValue< 0)
              std::cout<<"Error: not a positive number."<<std::endl;
            else if(inputValue>1000)
                std::cout<<"Error: too large a number."<<std::endl;
            else
                std::cout << date << " => " << inputValue << " = " << result << std::endl;
        }
        else
            std::cout<<"Error: bad input "<<"=>"<<line<<std::endl;

    }
    file.close();
    return 1;
}
