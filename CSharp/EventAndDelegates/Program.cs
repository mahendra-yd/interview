namespace EventAndDelegates
{
	class Program
	{
		static void Main(string[] args)
		{
			Video video = new Video { Title = "Video 1" };
			VideoEncoder videoEncoder = new VideoEncoder();
			MailService mailService = new MailService();
			TextService textService = new TextService();
			videoEncoder.videoEncoded += textService.onVideoEncoded;
			videoEncoder.videoEncoded += mailService.onVideoEncoded;
			videoEncoder.EncodeVideo(video);
		}
	}

}

