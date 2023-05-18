using System;
using System.Collections.Generic;
using System.IO.Ports;
using System.Linq;
using System.Text;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Animation;
using System.Windows.Media.Imaging;
using System.Windows.Shapes;

namespace WpfApp1
{
    /// <summary>
    /// Interaction logic for Editor.xaml
    /// </summary>
    public partial class Editor : Window
    {
        public Editor()
        {
            InitializeComponent();

            WindowStartupLocation = WindowStartupLocation.CenterScreen;



            //PointAnimation ani = new PointAnimation();
            //ani.To = new Point(100,200);
            //ani.Duration = TimeSpan.FromSeconds(10);

            //p1.BeginAnimation(LineSegment.PointProperty, ani);




        }




        Point start;
        Point box_initial;
        bool move_started = false;
        private void Viewport_MouseDown(object sender, MouseButtonEventArgs e)
        {
            move_started = true;
            start = e.GetPosition(viewport);
            box_initial.X = Canvas.GetLeft(drawboard);
            box_initial.Y = Canvas.GetTop(drawboard);
            Mouse.Capture(drawboard);
        }

        private void Viewport_MouseMove(object sender, MouseEventArgs e)
        {
            if (move_started == true)
            {
                double val = box_initial.X + e.GetPosition(viewport).X - start.X;
                
                if (val <= 0)
                    Canvas.SetLeft(drawboard, val);
                else
                    Canvas.SetLeft(drawboard, 0);

                val = box_initial.Y + e.GetPosition(viewport).Y - start.Y;
                if (val <= 0)
                    Canvas.SetTop(drawboard, val);
                else
                    Canvas.SetTop(drawboard, 0);
            }

            Title = e.GetPosition(drawboard).ToString();
        }

        private void Viewport_MouseUp(object sender, MouseButtonEventArgs e)
        {
            drawboard.ReleaseMouseCapture();

            move_started = false;
        }

        void UpdateScaleCenter(Point mousepos)
        {
            UpdateLayout();
            drawboard.UpdateLayout();
            viewport.UpdateLayout();

            drawboard_ScaleTransform.CenterX = -((drawboard.Width / 2) - mousepos.X);
            drawboard_ScaleTransform.CenterY = -((drawboard.Height / 2) - mousepos.Y);

            UpdateLayout();
            drawboard.UpdateLayout();
            viewport.UpdateLayout();
        }

        private void Viewport_MouseWheel(object sender, MouseWheelEventArgs e)
        {
            if (e.Delta > 0)
            {
                if (drawboard_ScaleTransform.ScaleX < 2)
                {
                    UpdateScaleCenter(e.GetPosition(drawboard));

                    drawboard_ScaleTransform.ScaleX += .2;
                    drawboard_ScaleTransform.ScaleY += .2;

                    UpdateScaleCenter(e.GetPosition(drawboard));
                    //Title = "drawboard_ScaleCenter: " + drawboard_ScaleTransform.CenterX + " " + drawboard_ScaleTransform.CenterY;

                }
            }
            else
            {
                if (drawboard_ScaleTransform.ScaleX > .45)
                {
                    UpdateScaleCenter(e.GetPosition(drawboard));

                    drawboard_ScaleTransform.ScaleX -= .2;
                    drawboard_ScaleTransform.ScaleY -= .2;

                    UpdateScaleCenter(e.GetPosition(drawboard));


                }

            }
        }
    }
}
