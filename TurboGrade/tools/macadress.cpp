#include "macadress.h"

MacAdress::MacAdress()
{
    foreach(QNetworkInterface interface, QNetworkInterface::allInterfaces())
    {
      if (interface.flags().testFlag(QNetworkInterface::IsUp) && !interface.flags().testFlag(QNetworkInterface::IsLoopBack))
          foreach (QNetworkAddressEntry entry, interface.addressEntries())
          {
              if ( interface.hardwareAddress() != "00:00:00:00:00:00" && entry.ip().toString().contains("."))
                  qDebug() << interface.index() << " : " << interface.name() + " "+ entry.ip().toString() +" " + interface.hardwareAddress();
          }
    }
}
