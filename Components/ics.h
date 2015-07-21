/*
*  File:		ics.h
*  Author:		Ian Bannerman
*  License:		GNU Public License v3
*
*  Description:
*
*
*/

#ifndef ICS_H
#define ICS_H


#include <QObject>							//Base of ICS class

#include <netcon.h>							//Used by CIcsManager for INet APIs
#include <atlstr.h>							//Used by CIcsManager for CAtlString
#include <atlcoll.h>						//Used by CIcsManager for CRefObjList & CAtlList
#include <comdef.h>							//Easy HRESULT error conversion

#include "IcsMgr\common.h"					//Required by CIcsManager
#include "IcsMgr\icsconn.h"					//Required by CIcsManager
#include "IcsMgr\icsmgr.h"					//Provides CIcsManager


#pragma comment(lib, "Components\\IcsMgr\\IcsMgr.lib")		//IcsMgr library


class ICS : public QObject
{
	Q_OBJECT

public:
	ICS(QObject *parent);
	~ICS();

	//Public list of network connection names used by UI and passed back in to identify connection to use
	QList<QString> networkConnectionNames;


	//Performs legwork of configuring and starting Internet Connection Sharing
	bool initialize(QString networkConnectionName, GUID hostedNetworkGUID);


private:
	//Checks if ICS has been disabled on this machine, message boxes if so
	bool isICSAllowed();


	//Instance of CIcsManager from the Microsoft sample project, defined in icsmgr.h
	CIcsManager* pICSManager;


	//List of available network connections populated via CIcsManager
	CRefObjList<CIcsConnectionInfo *> m_ConnectionList; 


	//Used to store the network connection name and GUID pair; only name used and passed back in by UI
	struct ICSNetworkConnections
	{
		QString networkConnectionName;
		GUID networkConnectionGUID;
	};
	QList<ICSNetworkConnections> icsNetworkConnectionList;

};

#endif // ICS_H