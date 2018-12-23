using Microsoft.ServiceBus;
using Microsoft.ServiceBus.Messaging;

namespace SampleRestServiceWeb
{
	public static class QueueConnector
	{
		// Thread-safe. Recommended that you cache rather than recreating it
		// on every request.
		public static QueueClient OrdersQueueClient;

		// Obtain these values from the portal.
		public const string Namespace = "your Service Bus namespace";

		// The name of your queue.
		public const string QueueName = "OrdersQueue";

		public static NamespaceManager CreateNamespaceManager()
		{
			string connectionString = "Endpoint=sb://mcontosorgsb.servicebus.windows.net/;SharedAccessKeyName=RootManageSharedAccessKey;SharedAccessKey=IbqFd2SYobwJVSD+mc8jCTOWZTpEE+xIa3yi0YTVg9k=";// CloudConfigurationManager.GetSetting("Microsoft.ServiceBus.ConnectionString");
			var namespaceManager = NamespaceManager.CreateFromConnectionString(connectionString);
			return namespaceManager;
		}

		public static void Initialize()
		{
			// Using Http to be friendly with outbound firewalls.
			ServiceBusEnvironment.SystemConnectivity.Mode =
				ConnectivityMode.Http;

			// Create the namespace manager which gives you access to
			// management operations.
			var namespaceManager = CreateNamespaceManager();

			// Create the queue if it does not exist already.
			if (!namespaceManager.QueueExists(QueueName))
			{
				namespaceManager.CreateQueue(QueueName);
			}

			// Get a client to the queue.
			var messagingFactory = MessagingFactory.Create(
				namespaceManager.Address,
				namespaceManager.Settings.TokenProvider);
			OrdersQueueClient = messagingFactory.CreateQueueClient(
				QueueName);
		}
	}
}
