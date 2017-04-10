#include <SFML/Network.hpp>
#include <sstream>
#include <exception>
#include <iostream>
#include <string>
#include <vector>
#include <boost/tokenizer.hpp>
#include <boost/lexical_cast.hpp>
#include <fstream>

// to run :  CXXFLAGS="-Ofast -march=native" LDLIBS="-lsfml-network -lsfml-system" make 0.ReadStockIBM

int main()
{
	//Download link: Yahoo finance is used to download IBM stod (IBM)
	//http://chart.finance.yahoo.com/table.csv?s=IBM&a=3&b=1&c=1986&d=3&e=1&f=2017&g=d&ignore=.csv
	sf::Http http("http://chart.finance.yahoo.com/");
	sf::Http::Request request;
	request.setMethod(sf::Http::Request::Get);
	request.setUri("/table.csv?s=IBM&a=3&b=1&c=1986&d=3&e=1&f=2017&g=d&ignore=.csv");
	request.setHttpVersion(1, 1); // HTTP 1.1
	sf::Http::Response response = http.sendRequest(request);
	//Make the file IBM.csv
	std::ofstream file("IBM.csv");
	//Throw in the data to file IBM.csv
	file << response.getBody() << '\n';
}