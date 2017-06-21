#ifndef IMODEL_H
#define IMODEL_H

class IModel
{
	virtual ~IModel() {}
	virtual void changeState() = 0;
};

#endif // IMODEL_H
