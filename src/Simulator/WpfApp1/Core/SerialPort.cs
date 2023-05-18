using System;
using System.Collections.Generic;
using System.IO.Ports;
using System.Linq;
using System.Text;

namespace WpfApp1.Core
{
    public class mySerialPort
    {
        SerialPort serialPort = new SerialPort();
        
        public void Open()
        {
            serialPort.PortName = "COM4";
            serialPort.Open();
        }


    }
}
