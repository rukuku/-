/*
 * Copyright 2018-2020 Qter(qsaker@qq.com). All rights reserved.
 *
 * The file is encoded using "utf8 with bom", it is a part
 * of QtSwissArmyKnife project.
 *
 * QtSwissArmyKnife is licensed according to the terms in
 * the file LICENCE in the root of the source code directory.
 */
#ifndef SAKTCPSERVERDEVICE_HH
#define SAKTCPSERVERDEVICE_HH

#include <QThread>
#include <QTcpServer>
#include <QTcpSocket>

#include "SAKDebugPageDevice.hh"

class SAKTcpServerDebugPage;
class SAKTcpServerDeviceController;
class SAKTcpServerDevice:public SAKDebugPageDevice
{
    Q_OBJECT
public:
    SAKTcpServerDevice(SAKTcpServerDebugPage *mDebugPage, QObject *parent = Q_NULLPTR);
private:
    bool initializing(QString &errorString) final;
    bool open(QString &errorString) final;
    QByteArray read() final;
    QByteArray write(QByteArray bytes) final;
    bool checkSomething(QString &errorString) final;
    void close() final;
    void free() final;
signals:
    void addClient(QString host, quint16 port, QTcpSocket *socket);
    void removeClient(QTcpSocket *socket);
private:
    SAKTcpServerDebugPage *mDebugPage;
    QTcpServer *mTcpServer;
    SAKTcpServerDeviceController *mDeviceController;
    QList<QTcpSocket*> mClientList;
};

#endif
