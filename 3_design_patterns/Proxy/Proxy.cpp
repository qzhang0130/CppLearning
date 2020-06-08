#include <cpprest/http_client.h>
#include <cpprest/filestream.h>
using namespace utility;
using namespace web;
using namespace web::http;
using namespace web::http::client;
using namespace concurrency::streams;

struct Pingable{
	virtual ~Pingable() = default;
	virtual wstring ping(const wstring& message) = 0;
};

struct Pong: Pingable{
	wstring ping(const wstring& message) override{
		return message + L" pong";
	}
};

struct RemotePong: Pingable{
	wstring ping(const wstring& message) override{
		wstring result;
		http_client client(U("http://localhost:9149/"));
		uri_builder builder(U("/api/pingpong/"));
		builder.append(message);
		pplx::task<wstring> task = client.request(methods::GET, builder.to_string());
			.then([=](http_response r){
				return r.extract_string();
			});
		task.wait();
		return task.get();
	}
};

void tryit(RemotePong& pp){
	wcout<< pp.ping(L"ping") << "\t";
}

void communication_proxy(){
	RemotePong pp;
	for(int i = 0; i < 10; ++i){
		tryit(pp);
	}
}

int main(){
	communication_proxy();

	return 0;
}

