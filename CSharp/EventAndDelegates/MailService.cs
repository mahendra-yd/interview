using System;

namespace EventAndDelegates
{
	public class MailService
	{
		public void onVideoEncoded(object obj, VideoEncoderEventArgs e)
		{
			Console.WriteLine("Sending emial to owner ...." + e.video.Title);
		}
	}

}
