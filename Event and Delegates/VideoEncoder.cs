using System;
using System.Threading;

namespace ConsoleApp1
{
    public class VideoEncoderEvent : EventArgs
    {
        public Video video { get; set; }
    }
               
    public class VideoEncoder {

        public event EventHandler<VideoEncoderEvent> VideoEncodedEventHandler; 
        public void encodeVideo(Video video)
        {
            Console.WriteLine("encoding video ...");
            Thread.Sleep(3000);
            OnEncoded(video);
        }
        public void OnEncoded(Video video)
        {
            if(VideoEncodedEventHandler != null)
            {
                VideoEncodedEventHandler(this, new VideoEncoderEvent() { video = video });
            }
        }
    }
}
