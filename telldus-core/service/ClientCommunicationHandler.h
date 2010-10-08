#ifndef CLIENTCOMMUNICATIONHANDLER_H
#define CLIENTCOMMUNICATIONHANDLER_H

#include <string>
#include "Thread.h"
#include "Socket.h"
#include "Event.h"

class ClientCommunicationHandler : public TelldusCore::Thread
{
public:
	ClientCommunicationHandler();
	ClientCommunicationHandler(TelldusCore::Socket *clientSocket, Event *event);
	~ClientCommunicationHandler(void);

	bool isDone();

protected:
	void run();

private:
	class PrivateData;
	PrivateData *d;
	std::wstring parseMessage(std::wstring &clientMessage);
};

#endif //CLIENTCOMMUNICATIONHANDLER_H