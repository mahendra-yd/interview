using Microsoft.ServiceBus.Messaging;

namespace SampleRestServiceWeb.Models
{
	public class MessageSender
	{
		static int i = 0;
		public static async void sendMessage()
		{
			while (i++ < 100)
			{
				var message = new BrokeredMessage("Hello Message" + i.ToString());
				QueueConnector.OrdersQueueClient.Send(message);
			}
			i = 0;
		}

	}
}