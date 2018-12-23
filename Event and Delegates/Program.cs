namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            Video video = new Video() { Title = "Video 1" };
            VideoEncoder encoder = new VideoEncoder();
            EmailService email = new EmailService();
            encoder.VideoEncodedEventHandler += email.OnVideoEncoded;
            encoder.encodeVideo(video);
        }
    }
}
