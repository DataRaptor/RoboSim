using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using FlashLoader.Core.Communication;

namespace FlashLoader.Core.Communication
{
    public struct ComDataStruct
    {

    }

    public class Hub
    {
        public static void Connect()
        {
            Connection.Connect();
        }

        public static void StartReceiving()
        {
            Connect();

            string buffer = string.Empty;
            while (true)
            {
                buffer = Connection.Port.ReadLine();
                ProcessPacket(buffer);
            }
        }


        private static void ProcessPacket(string buffer)
        {




        }

        public void SendData(ComDataStruct data)
        {

        }
    }
}
