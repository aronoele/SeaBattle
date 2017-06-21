#ifndef ICONTROLLER_H
#define ICONTROLLER_H

class IController
{
public:
	virtual ~IController() {}
	virtual void start() = 0;
};

#endif // ICONTROLLER_H
