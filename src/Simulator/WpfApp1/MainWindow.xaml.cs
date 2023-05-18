using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Net;
using System.Net.Sockets;
using System.Text;
using System.Threading;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Animation;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using System.Windows.Threading;

namespace WpfApp1
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {


        public MainWindow()
        {
            InitializeComponent();


            //Test Tq = new Test();
            //Tq.Show();

            try
            {
                TcpClient client = new TcpClient();
                client.Connect(new IPEndPoint(IPAddress.Parse("127.0.0.1"), 9890));

                NetworkStream ns = client.GetStream();
                
            }
            catch
            {
                MessageBox.Show("Smart Cat IDE is not running.", "Fatal ERROR", MessageBoxButton.OK, MessageBoxImage.Error);
                //Application.Current.Shutdown();
            }


            Thread.CurrentThread.Priority = ThreadPriority.Highest;
            Process.GetCurrentProcess().PriorityBoostEnabled = true;
            Process.GetCurrentProcess().PriorityClass = ProcessPriorityClass.RealTime;


            Thread newWindowThread = new Thread(new ThreadStart(ThreadStartingPoint));
            newWindowThread.SetApartmentState(ApartmentState.STA);
            newWindowThread.IsBackground = true;
            newWindowThread.Priority = ThreadPriority.Highest;
            newWindowThread.Start();
        }

        private void ThreadStartingPoint()
        {
            Editor T = new Editor();
            T.Show();
            System.Windows.Threading.Dispatcher.Run();
        }



        int count = 0;
        private void Square_MouseDown(object sender, MouseButtonEventArgs e)
        {
            count++;
            Title = count.ToString();
        }

        private void Window_MouseLeftButtonDown(object sender, MouseButtonEventArgs e)
        {
            
        }

        Point start;
        Point box_initial;
        bool move_started = false;
        private void Canvas_MouseLeftButtonDown(object sender, MouseButtonEventArgs e)
        {
            move_started = true;
            start = e.GetPosition(canvas);
            box_initial.X = Canvas.GetLeft(box);
            box_initial.Y = Canvas.GetTop(box);
            Mouse.Capture(box);
        }

        private void Canvas_MouseLeftButtonUp(object sender, MouseButtonEventArgs e)
        {
            box.ReleaseMouseCapture();

            move_started = false;
        }


        private void Canvas_MouseMove(object sender, MouseEventArgs e)
        {
            if(move_started == true)
            {
                Canvas.SetLeft(box, box_initial.X + e.GetPosition(canvas).X - start.X);
                Canvas.SetTop(box, box_initial.Y + e.GetPosition(canvas).Y - start.Y);

                Canvas.SetLeft(track, box_initial.X + e.GetPosition(canvas).X - start.X);
                Canvas.SetTop(track, box_initial.Y + e.GetPosition(canvas).Y - start.Y);
            }
        }

        private void Box_MouseWheel(object sender, MouseWheelEventArgs e)
        {
            
        }

        private void Canvas_MouseWheel(object sender, MouseWheelEventArgs e)
        {
            if (e.Delta > 0)
            {
                //box_scale.CenterX = e.GetPosition(canvas).X;
                //box_scale.CenterY = e.GetPosition(canvas).Y;

                box_scale.ScaleX += .2;
                box_scale.ScaleY += .2;

                Track_ScaleTransform.ScaleX += .2;
                Track_ScaleTransform.ScaleY += .2;
            }
            else
            {
                if(box_scale.ScaleX > .4)
                {
                    box_scale.ScaleX -= .2;
                    box_scale.ScaleY -= .2;

                    Track_ScaleTransform.ScaleX -= .2;
                    Track_ScaleTransform.ScaleY -= .2;
                }
                
            }
        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {

            DispatcherTimer tim = new DispatcherTimer();
            tim.Interval = TimeSpan.FromTicks(100);
            tim.Tick += Tim_Tick;
            tim.Start();


            DoubleAnimation ani = new DoubleAnimation();
            ani.To = 3600;
            ani.RepeatBehavior = RepeatBehavior.Forever;
            ani.AutoReverse = true;
            ani.Duration = TimeSpan.FromMinutes(5);
            BotCircleRotateTransform.BeginAnimation(RotateTransform.AngleProperty, ani);
        }

        int[] IRArray = new int[10];

        double LSpeed = 0.7;
        double RSpeed = .5;
        double Speed = 0;
        double RotationSpeed = 0;
        double RotationAngle = 0;
        int LSteps = 0;
        int RSteps = 0;
        double LStepPixels = 0;
        double RStepPixels = 0;

        double Move_X = 0;
        double Move_Y = 0;
        double Move = 0;
        private void Tim_Tick(object sender, EventArgs e)
        {
            Speed = LSpeed + RSpeed;
            Speed /= 2;


            double radians = (Math.PI / 180) * CarRotateTransform.Angle;
            Vector vector = new Vector { X = Math.Sin(radians), Y = -Math.Cos(radians) };
            Move_X = vector.X * Speed;
            Move_Y = vector.Y * Speed;
            CarTranslateTransform.X += Move_X;
            CarTranslateTransform.Y += Move_Y;


            //Rotation
            RotationSpeed = LSpeed - RSpeed;
            RotationAngle = 1 * RotationSpeed;
            CarRotateTransform.Angle += RotationAngle;


            //Steps Calculation
            //Move = Math.Sqrt(Move_X * Move_X + Move_Y * Move_Y);
            //LStepPixels += Move;
            //RStepPixels += Move;

            Lwheeltranslate.Y -= LSpeed;
            Rwheeltranslate.Y -= RSpeed;

            if (Lwheeltranslate.Y < -185 || Lwheeltranslate.Y > 185)
                Lwheeltranslate.Y = -1.7;
            if (Rwheeltranslate.Y < -185 || Rwheeltranslate.Y > 185)
                Rwheeltranslate.Y = -1.7;


            //LStepPixels += RotationAngle;
            //RStepPixels += -RotationAngle;

            LStepPixels += LSpeed;
            RStepPixels += RSpeed;


            if (LStepPixels > 1.9 || LStepPixels < -1.9)
            {
                LSteps++;
                LStepPixels = 0;
            }
            if(RStepPixels > 1.9 || RStepPixels < -1.9)
            {
                RSteps++;
                RStepPixels = 0;
            }
            Title = LSteps + "   " + RSteps + "  " + (LSteps - RSteps);
            LencoderTxt.Text = LSteps.ToString();
            RencoderTxt.Text = RSteps.ToString();


            //foreach (Ellipse item in irarray.Children)
            //{
            //    Point point = new Point();

            //    point.X = 2 + item.Margin.Left + irarray.Margin.Left + Canvas.GetLeft(bot) + CarTranslateTransform.X;
            //    point.Y = 2 + item.Margin.Top + irarray.Margin.Top + Canvas.GetTop(bot) + CarTranslateTransform.Y;


            //    /*Shifting Axis*/
            //    //Finding Sensor Angle
            //    Point shifted_point = new Point();
            //    shifted_point = RotateAxis(point, GetOrigin(), CarRotateTransform.Angle);


            //    HitTestResult result = VisualTreeHelper.HitTest(track, shifted_point);

            //    if (result != null)
            //    {
            //        if (result.VisualHit is Path || result.VisualHit is Ellipse || result.VisualHit is Border)
            //        {
            //            item.Fill = Brushes.Red;
            //        }
            //    }
            //    else
            //    {
            //        item.Fill = new SolidColorBrush(Color.FromRgb(178,197,203));
            //    }


            //    //Canvas.SetLeft(pointer, shifted_point.X - 2);
            //    //Canvas.SetTop(pointer, shifted_point.Y - 2);

            //    //MessageBox.Show("Hello");
            //}




            ///*Calculate Sonar value*/
            ////SonarL
            //Point origin = GetOrigin();
            //Point p = new Point();
            //Point SonarL_Base = new Point();
            //SonarL_Base.X = Canvas.GetLeft(bot) + sonarL.Margin.Left + (sonarL.Width / 2) + CarTranslateTransform.X;
            //SonarL_Base.Y = Canvas.GetTop(bot) + sonarL.Margin.Top + (sonarL.Height / 2) + CarTranslateTransform.Y;

            //p.X = SonarL_Base.X;
            //p.Y = SonarL_Base.Y;
            //for (int i = 0; i < 300; i++)
            //{
            //    Point loc = RotateAxis(p, origin, CarRotateTransform.Angle);

            //    //Canvas.SetLeft(pointer, loc.X - 2);
            //    //Canvas.SetTop(pointer, loc.Y - 2);
            //    //MessageBox.Show("Hello");

            //    bool res = CheckObstacle(loc);
            //    if (res == true)
            //        break;

            //    p.X--;

            //}
            //double SonarL_Value = Math.Sqrt(Math.Pow((p.X - SonarL_Base.X), 2) + Math.Pow((p.Y - SonarL_Base.Y), 2));
            //sonarL_line.Width = SonarL_Value;
            //LSonarTxt.Text = SonarL_Value.ToString();


            //if (SonarL_Value < 50)
            //{
            //    sonarL_line.Stroke = Brushes.Red;
            //}
            //else if (SonarL_Value < 120)
            //{
            //    sonarL_line.Stroke = Brushes.Orange;
            //}
            //else if (SonarL_Value < 170)
            //{
            //    sonarL_line.Stroke = Brushes.SlateGray;
            //}
            //else
            //{
            //    sonarL_line.Stroke = Brushes.Transparent;
            //}


            ////SonarM
            //Point SonarM_Base = new Point();
            //SonarM_Base.X = Canvas.GetLeft(bot) + sonarM.Margin.Left + (sonarM.Width / 2) + CarTranslateTransform.X;
            //SonarM_Base.Y = Canvas.GetTop(bot) + sonarM.Margin.Top + (sonarM.Height / 2) + CarTranslateTransform.Y;

            //p.X = SonarM_Base.X;
            //p.Y = SonarM_Base.Y;
            //for (int i = 0; i < 300; i++)
            //{
            //    Point loc = RotateAxis(p, origin, CarRotateTransform.Angle);

            //    //Canvas.SetLeft(pointer, loc.X - 2);
            //    //Canvas.SetTop(pointer, loc.Y - 2);
            //    //MessageBox.Show("Hello");

            //    bool res = CheckObstacle(loc);
            //    if (res == true)
            //        break;

            //    p.Y--;
            //}
            //double SonarM_Value = Math.Sqrt(Math.Pow((p.X - SonarM_Base.X), 2) + Math.Pow((p.Y - SonarM_Base.Y), 2));
            //sonarM_line.Height = SonarM_Value;
            //MSonarTxt.Text = SonarM_Value.ToString();

            //if (SonarM_Value < 50)
            //{
            //    sonarM_line.Stroke = Brushes.Red;
            //}
            //else if (SonarM_Value < 120)
            //{
            //    sonarM_line.Stroke = Brushes.Orange;
            //}
            //else if (SonarM_Value < 170)
            //{
            //    sonarM_line.Stroke = Brushes.SlateGray;
            //}
            //else
            //{
            //    sonarM_line.Stroke = Brushes.Transparent;
            //}


            ////SonarR
            //Point SonarR_Base = new Point();
            //SonarR_Base.X = Canvas.GetLeft(bot) + sonarR.Margin.Left + (sonarR.Width / 2) + CarTranslateTransform.X;
            //SonarR_Base.Y = Canvas.GetTop(bot) + sonarR.Margin.Top + (sonarR.Height / 2) + CarTranslateTransform.Y;

            //p.X = SonarR_Base.X;
            //p.Y = SonarR_Base.Y;
            //for (int i = 0; i < 300; i++)
            //{
            //    Point loc = RotateAxis(p, origin, CarRotateTransform.Angle);

            //    //Canvas.SetLeft(pointer, loc.X - 2);
            //    //Canvas.SetTop(pointer, loc.Y - 2);
            //    //MessageBox.Show("Hello" + p.ToString());

            //    bool res = CheckObstacle(loc);
            //    if (res == true)
            //        break;

            //    p.X++;

            //}
            //double SonarR_Value = Math.Sqrt(Math.Pow((p.X - SonarR_Base.X), 2) + Math.Pow((p.Y - SonarR_Base.Y), 2));
            //sonarR_line.Width = SonarR_Value;
            //RSonarTxt.Text = SonarR_Value.ToString();

            //if (SonarR_Value < 50)
            //{
            //    sonarR_line.Stroke = Brushes.Red;
            //}
            //else if (SonarR_Value < 120)
            //{
            //    sonarR_line.Stroke = Brushes.Orange;
            //}
            //else if (SonarR_Value < 170)
            //{
            //    sonarR_line.Stroke = Brushes.SlateGray;
            //}
            //else
            //{
            //    sonarR_line.Stroke = Brushes.Transparent;
            //}
        }

        bool CheckObstacle(Point point)
        {
            HitTestResult result = VisualTreeHelper.HitTest(track, point);

            if (result != null)
            {
                if (result.VisualHit is Path || result.VisualHit is Ellipse || result.VisualHit is Border || result.VisualHit is UserControl)
                {
                    return true;
                }
            }
            else
            {
                return false;
            }
            return false;
        }

        Point RotateAxis(Point point, Point Base, double Angle)
        {
            double x = point.X - Base.X;
            double y = Base.Y - point.Y;
            double d = Math.Sqrt(x * x + y * y);
            double sensorangle = Math.Acos(x / d) * 180 / Math.PI;

            double newangle = sensorangle - Angle;

            Point shifted_point = new Point();
            shifted_point.X = Base.X + d * Math.Cos(newangle * Math.PI / 180);
            shifted_point.Y = Base.Y - d * Math.Sin(newangle * Math.PI / 180);

            return shifted_point;
        }

        Point GetOrigin()
        {
            Point result = new Point();

            result.X = bot.RenderTransformOrigin.X * bot.Width + Canvas.GetLeft(bot) + CarTranslateTransform.X;
            result.Y = bot.RenderTransformOrigin.Y * bot.Height + Canvas.GetTop(bot) + CarTranslateTransform.Y;
            return result;
        }

        private void Slider_ValueChanged(object sender, RoutedPropertyChangedEventArgs<double> e)
        {
            CarRotateTransform.Angle = e.NewValue;
        }

        private void RightSpeedController_ValueChanged(object sender, RoutedPropertyChangedEventArgs<double> e)
        {
            RSpeed = e.NewValue;
        }

        private void LeftSpeedController_ValueChanged(object sender, RoutedPropertyChangedEventArgs<double> e)
        {
            LSpeed = e.NewValue;
        }
    }
}
