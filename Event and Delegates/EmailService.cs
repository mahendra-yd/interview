using System;

namespace ConsoleApp1
{
    public class EmailService
    {
        public void OnVideoEncoded(Object obj, VideoEncoderEvent e)
        {
            Console.WriteLine("Sending email to owner ...." + e.video.Title);
        }
    }
}
