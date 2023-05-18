using System;
using System.Collections.Generic;
using System.IO.Ports;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Windows.Threading;

namespace FlashLoader.Core.Communication.ComProtocol
{
    public delegate void CallBackDeligate(string header, byte[] data);

    public class Request
    {
        public string Header;
        public string Body;
        public CallBackDeligate CallBack;
    }

    public class Protocol
    {
        DispatcherTimer tim = new DispatcherTimer();

        private static Request LastRequest = new Request();
        List<Request> RequestsPending = new List<Request>();

        public event EventHandler OnConnectionLost;
        public event EventHandler OnConnectionAvailable;

        public Protocol()
        {
            OnConnectionLost += Protocol_OnConnectionLost;
            OnConnectionAvailable += Protocol_OnConnectionAvailable;

            Connection.Port.ReadTimeout = 40;
            Connection.Port.DataReceived += Port_DataReceived;

            tim.Interval = TimeSpan.FromMilliseconds(60);
            tim.Tick += Tim_Tick;
            
        }

        private void Protocol_OnConnectionAvailable(object sender, EventArgs e)
        {
            
        }

        private void Protocol_OnConnectionLost(object sender, EventArgs e)
        {
            
        }

        private void Tim_Tick(object sender, EventArgs e)
        {
            //tim.Stop();

            if(RequestSent == true)
            {
                RequestSent = false;

                //Send any pending request
                SendPendingRequest();
            }
            
        }

        private static bool RequestSent = false;
        public void SendRequest(string header, string body, CallBackDeligate callback)
        {
            if (Connection.Port.IsOpen == false)
            {
                if(Connection.Connect() == 0)
                {
                    //Notify The connection is failed
                    OnConnectionLost.Invoke(this, new EventArgs());

                    goto END;
                }
            }

            OnConnectionAvailable.Invoke(this, new EventArgs());

            Request req = new Request();
            req.Header = header;
            req.Body = body;
            req.CallBack = callback;

            if (RequestSent == true)
            {
                //Add to Pending Request

                RequestsPending.Add(req);
            }
            else
            {
                //Send the request

                _SendReq(req);
            }

        END:;
        }

        private void _SendReq(Request req)
        {
            LastRequest = req;

            Connection.Port.WriteLine(req.Header + " " + req.Body);
            RequestSent = true;

            tim.Start();

            //Thread.Sleep(1000);


        }


        
        private void Port_DataReceived(object sender, System.IO.Ports.SerialDataReceivedEventArgs e)
        {
            RequestSent = false;

            try
            {
                SerialPort sport = (SerialPort)sender;
                int bufferidx = 0;

                int bytes = sport.BytesToRead;
                byte[] buffer = new byte[bytes];
                sport.Read(buffer, 0, bytes);


                string header = string.Empty;
                int i;
                for (i=0;i<60;i++)
                {
                    char c = (char)buffer[i];
                    if (c == ' ')
                        break;
                    else
                        header += c;
                }
                i++;

                int len = bytes - i;
                byte[] data = new byte[len];
                for(int j =0; j < len; j++)
                {
                    data[j] = buffer[i];
                    i++;
                }

                if (LastRequest.Header == header)
                {
                    LastRequest.CallBack(header, data);
                }
                else
                {
                    //Do something else with that response
                    //This migih be request from MCU of printf


                }

                //Check for Pending Request
                SendPendingRequest();




                //string header = string.Empty;
                //while ((char)b != ' ')
                //{
                //    header += (char)b;
                //    b = sport.ReadByte();
                //    bufferidx++;
                //}

                //int[] buffer = new int[64];
                //int dataidx = 0;
                ////Read Data
                //for (int i = bufferidx; i < 62; i++)
                //{

                //    buffer[dataidx] = sport.ReadByte();
                //    dataidx++;
                //}

                //if (LastRequest.Header == header)
                //{
                //    LastRequest.CallBack(header, buffer);
                //}
                //else
                //{
                //    //Do something else with that response
                //    //This migih be request from MCU of printf


                //}

                ////Check for Pending Request
                //SendPendingRequest();

            }
            catch (Exception ex)
            {
                string st = ex.Message;
            }

        }

        void SendPendingRequest()
        {
            if (RequestsPending.Count > 0)
            {
                _SendReq(RequestsPending[0]);
                RequestsPending.Remove(RequestsPending[0]);
            }
        }






        /// <summary>
        /// Converts Structures to byte array
        /// </summary>
        /// <param name="strct"></param>
        /// <returns></returns>
        public static byte[] GetBytes(object strct)
        {
            int size = Marshal.SizeOf(strct);
            byte[] arr = new byte[size];
            IntPtr ptr = Marshal.AllocHGlobal(size);

            Marshal.StructureToPtr(strct, ptr, true);
            Marshal.Copy(ptr, arr, 0, size);
            Marshal.FreeHGlobal(ptr);

            return arr;
        }




        /// <summary>
        /// Converts Byte array to structure
        /// </summary>
        /// <param name="arr"></param>
        /// <param name="StructType"></param>
        /// <param name="structSize"></param>
        /// <returns></returns>
        public static object GetObject(byte[] arr, Type StructType, int structSize)
        {
            object str = new object();

            int size = structSize;
            IntPtr ptr = Marshal.AllocHGlobal(size);

            Marshal.Copy(arr, 0, ptr, size);

            str = (object)Marshal.PtrToStructure(ptr, StructType);
            Marshal.FreeHGlobal(ptr);
            return str;
        }




    }
}
