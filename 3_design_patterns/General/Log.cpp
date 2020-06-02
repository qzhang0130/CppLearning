#include <iostream>
#include <string>
#include <memory>

struct ILogger{
	virtual void output(std::string s) = 0;
};

struct ConsoleLogger final: public ILogger{
	void output(std::string s) override{
		std::cout<<s<<std::endl;
	}
};

class Engine{
private:
	int horsepower = 400;
	float volume = 4;
public:
	friend std::ostream& operator<<(std::ostream& os, const Engine& e1){
		os << "Horsepower: " << e1.horsepower <<" Volume: " << e1.volume;
		return os;
	}
};

class Car{
private:
	std::shared_ptr<ILogger> logger;  //= std::make_shared<ConsoleLogger>();
	std::shared_ptr<Engine> engine; // = std::make_shared<Engine>();
public:
	Car(const std::shared_ptr<ILogger>& logger, const std::shared_ptr<Engine>& engine): logger(logger), engine(engine){}

	friend std::ostream& operator<<(std::ostream& os, const Car& car){
		os << "Car with Engine "<< *(car.engine) << "\n";
		return os;
	}
};


int main(){
	std::shared_ptr<ILogger> logger = std::make_shared<ConsoleLogger>();
	std::shared_ptr<Engine> engine = std::make_shared<Engine>();

	Car car(logger, engine);
	std::cout<<car<<std::endl;
	return 0;
}