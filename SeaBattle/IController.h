#ifndef ICONTROLLER_H
#define ICONTROLLER_H

class IController
{
	virtual ~IController() {}
	virtual void shut() = 0;
};

#endif // ICONTROLLER_H
