using System;
using System.Threading;

namespace EventAndDelegates
{
	public class VideoEncoderEventArgs : EventArgs
	{
		public Video video { get; set; }
	}
	public class VideoEncoder
	{
		//public delegate void VideoEncodedEventHnadler(Object obj, EventArgs e);
		public event EventHandler<VideoEncoderEventArgs> videoEncoded;

		public void EncodeVideo(Video video)
		{
			Console.WriteLine("Encoding video ... " + video.Title);
			Thread.Sleep(3000);
			OnEncodedVideo(video);
		}

		private void OnEncodedVideo(Video video)
		{
			if (videoEncoded != null)
			{
				videoEncoded(this, new VideoEncoderEventArgs() { video = video });
			}
			Console.WriteLine("Video encoding completed...");
		}
	}
}
