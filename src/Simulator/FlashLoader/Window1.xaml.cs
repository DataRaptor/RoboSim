using System;
using System.Collections.Generic;
using System.IO.Ports;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Shapes;
using System.Windows.Threading;
using FlashLoader.Core.Communication;
using FlashLoader.Core.Communication.ComProtocol;


namespace FlashLoader
{
    /// <summary>
    /// Interaction logic for Window1.xaml
    /// </summary>
    public partial class Window1 : Window
    {
        Protocol protocol = new Protocol();
        DispatcherTimer updateloop = new DispatcherTimer();
        public Window1()
        {
            InitializeComponent();

            
            updateloop.Interval = TimeSpan.FromMilliseconds(1000);
            updateloop.Tick += Updateloop_Tick;
            updateloop.Start();


            
            protocol.OnConnectionLost += Protocol_OnConnectionLost;
            protocol.OnConnectionAvailable += Protocol_OnConnectionAvailable;



            //FatalError fe = new FatalError();
            //fe.Show();

        }


        



        private void Protocol_OnConnectionAvailable(object sender, EventArgs e)
        {
            message.Visibility = Visibility.Hidden;
        }

        private void Protocol_OnConnectionLost(object sender, EventArgs e)
        {
            message.Visibility = Visibility.Visible;
        }


        public struct TempStruct
        {
            public byte Temp;
        }
        TempStruct tempStruct = new TempStruct();
        private void UpdateTemp(string header, byte[] data)
        {

            tempStruct = (TempStruct)Protocol.GetObject(data, typeof(TempStruct), Marshal.SizeOf(tempStruct));

            Dispatcher.Invoke((Action)(() =>
            {
                temp.Text = tempStruct.Temp.ToString();
            }));
        }

        private void Update_Dashbaord()
        {
            //updateloop.Stop();
            protocol.SendRequest("oio gettemp", "", UpdateTemp);
        }

        private void Update_BotConfig()
        {

        }

        private void Update_Watch()
        {

        }

        private void Updateloop_Tick(object sender, EventArgs e)
        {
            //updateloop.Stop();

            if (tab.SelectedItem == dashboard_tab)
            {
                Update_Dashbaord();
            }
            else if (tab.SelectedItem == botconfig_tab)
            {
                Update_BotConfig();
            }
            else if (tab.SelectedItem == watch_tab)
            {
                Update_Watch();
            }


        }


        



        private void Header_MouseLeftButtonDown(object sender, MouseButtonEventArgs e)
        {
            DragMove();
        }




    }
}
