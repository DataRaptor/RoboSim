using System;
using System.Collections.Generic;
using System.IO.Ports;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace FlashLoader.Core.Communication
{
    public class Connection
    {
        public static SerialPort Port = new SerialPort();

        public static int Connect()
        {
            Port.ReadBufferSize = 64;
            try
            {
                TryConnect(Properties.Settings.Default.Port);

                return 1;
            }
            catch (Exception ex)
            {
                for (int i = 0; i < 100; i++)
                {
                    try
                    {
                        TryConnect(i);

                        Properties.Settings.Default.Port = i;
                        Properties.Settings.Default.Save();

                        return 1;
                    }
                    catch (Exception ex1)
                    {

                    }
                }
            }

            return 0;
        }



        private static void TryConnect(int portnumber)
        {
            Port.PortName = "COM" + portnumber;
            Port.Open();


            //try
            //{
            //    Port.WriteLine("*WHORU");
            //    Port.ReadTimeout = 100;
            //    string str = Port.ReadLine();

            //    if (str != "SMARTCAT")
            //    {
            //        throw new Exception();
            //    }
            //}
            //catch (Exception ex)
            //{
            //    throw new Exception();
            //}
        }

    }





}
