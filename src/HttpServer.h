#include <iostream>
#include "ThreadPool.h"

using namespace std;

public class HttpServer
{
public:
	HttpServer();
	~HttpServer();
    int serverStatus = 0;
    int clientCount = 0;
    int maxClientsCount = 0;
private:
    void InitializeListenerThreadPool();
    ThreadPool listenerThreadPool;
}
