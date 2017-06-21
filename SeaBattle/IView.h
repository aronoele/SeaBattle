#ifndef IVIEW_H
#define IVIEW_H

class IView
{
public:
	virtual ~IView() {}
	virtual void show() = 0;
};

#endif // IVIEW_H

