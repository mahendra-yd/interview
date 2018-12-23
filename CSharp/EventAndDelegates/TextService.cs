using System;

namespace EventAndDelegates
{
	public class TextService
	{
		public void onVideoEncoded(Object obj, VideoEncoderEventArgs e)
		{
			Console.WriteLine("sending text to video owner ..." + e.video.Title);
		}
	}
}
