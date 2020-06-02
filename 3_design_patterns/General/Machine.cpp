#include <iostream>
#include <string>
#include <vector>

struct Document{
	std::vector<std::string> lines;
};

struct IPrinter{
	virtual void print(const std::vector<Document*>& documents) = 0;
};

struct IScanner{
	virtual void scan(const std::vector<Document*>& documents) = 0;
};

struct Printer: IPrinter{
	void print(const std::vector<Document*>& documents) override{
		std::cout<<"Printing document ..."<<std::endl;
		for(auto d: documents){
			std::cout<<"-------------"<<std::endl;

			for(auto l: d->lines){
				std::cout<<"\t"<<l<<std::endl;
			}

			std::cout<<"-------------"<<std::endl<<std::endl;
		}
	}
};

struct Scanner: IScanner{
	void scan(const std::vector<Document*>& documents) override{
		std::cout<<"Scanning document ..."<<std::endl;
		for(auto d: documents){
			std::cout<<"-------------"<<std::endl;

			for(auto l: d->lines){
				std::cout<<"\t"<<l<<std::endl;
			}

			std::cout<<"-------------"<<std::endl<<std::endl;
		}
	}
};


struct IMachine: IPrinter, IScanner{};

struct Machine: IMachine{
	IPrinter& printer;
	IScanner& scanner;

	Machine(IPrinter& printer, IScanner& scanner):printer(printer), scanner(scanner){}

	void print(const std::vector<Document*>& documents) override{
		printer.print(documents);
	}

	void scan(const std::vector<Document*>& documents) override{
		scanner.scan(documents);
	}

};

using std::vector;
using std::string;
using std::cout;
using std::endl;

int main(){
	vector<string> lines{{"abc"}, "bcd", "efg"};
	vector<string> lines1{{"123"}, "456", "789"};

	Document* doc1 = new Document;
	Document* doc2 = new Document;

	vector<Document*> documents{doc1, doc2};

	doc1->lines = lines;
	doc2->lines = lines1;

	Printer printer;

	printer.print(documents);

	Scanner scanner;

	scanner.scan(documents);

	Machine machine(printer, scanner);

	machine.print(documents);
	machine.scan(documents);

	delete doc1;
	doc1 = nullptr;
	delete doc2;
	doc2 = nullptr;

	return 0;
}